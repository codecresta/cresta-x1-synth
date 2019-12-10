/*
audio_fns.cpp

Implements various functions for audio processing / DSP.

notes
-----
for chorus see http://www.musicdsp.org/archive.php?classid=4#98

*/

#include "audio_fns.h"
#include <math.h>
#include <stdlib.h>

double AudioFns::zOClip(double x)
// clips signal to 0 to 1 range
{
	if (x < 0)
		return 0;
    else if (x > 1)
		return 1;
	else
		return x;
}

double AudioFns::clip(double x)
// clips a signal to -1 to +1 range
{
	if (x < -1)
		return -1;
	else if (x > 1)
		return 1;
	else
		return x;
}

// oscillators functions work on 0 to 1 input, p = position and return in range -1 to 1
double AudioFns::sawTri(double p, double c)
// c = 0 saw down, c = 0.5 triangle, c = 1 saw up
{
	if (c < SLOPE)
		c = SLOPE;
	if (c > 1.0 - SLOPE)
		c = 1.0 - SLOPE;
	double d = 0.5 * c;
	if (p <= d)
		return p / d;
	else if (p <= 1.0 - d)
		return (1.0 - 2.0*p)/(1.0 - c);
	else
		return (p - 1.0)/d;
}

double AudioFns::sine(double p)
// sine function
{
	return sin(p*DBL_PI);
}

double AudioFns::pulse(double p, double c)
// c is pulse width c = 0.5 - min_c for square wave, e.g. c = width of wave top, note: a perfect
// pulse is impossible, the constant SLOPE determines the width of the sloping part of the wave
{
	double d;
	d = 0.5 * SLOPE;
	if (p < d)
		return p / d;
	else if (p < c - d)
		return 1;
	else if (p < c + d)
		return (c - p) / d;
	else if (p < 1 - d)
		return -1;
	else
		return (p - 1) / d;
}

double AudioFns::noise()
// white noise
{
	return 2*(double)rand()/(double)(RAND_MAX) - 1;
}

double AudioFns::updPos(double p, double f, double r)
// returns new position in range 0 to 1, p = current position, f = frequency, r = sample rate
{
	double q;
	q = p + f / r;
	return q - floor(q);
}

double AudioFns::freq(double p)
// after scaling 0 to 1, maps MIDI note number (p) to frequency (Hz), f is the tuning
// e.g. p = 0 to 127, continuos and representing the pitches C1 to G9
// see http://en.wikipedia.org/wiki/Pitch_class and http://en.wikipedia.org/wiki/C_(musical_note
{
	if (p < 0)
		p = 0;
	else if (p > 128)
		p = 128;
	return 440 * pow(2, (p - 69.0) / 12);
}

double AudioFns::ramp(double p, double sv, double ev)
// ramp: between sv and ev for 0 to gt, then just ev after 1.0
{
	if (p <= 1.0)
		return (1.0 - p) * sv + p * ev;
	else
		return ev;
}

double AudioFns::aDSR(bool on, double ot, double ol, double t, double at, double dt, double sl, double rt)
// traditional ADSR envelope, pass t = at + dt to achieve sustain level
// on = note on, ot = time of note off, ol = level at note off time, t = time, at = attack time,
// dt = decay time, sl = sustain level, rt = release time
{
	if (on)
	{
		if (t <= at)
			return t / at;
		else if (t < at + dt)
			return (at + dt - t + (t - at) * sl) / dt;
		else
			return sl;
	}
	else if (t < ot + rt)
		return (ot + rt - t) * ol / rt;
	else
		return 0;
}

bool AudioFns::aDSRFin(bool on, double ot, double t, double rt)
// determines whether the above envelope has finished
{
	if (on)
		return false;
	else
		return (t >= ot + rt);
}

double AudioFns::crossFade(double a, double x0, double x1)
// outputs a cross fade of the two inputs signals
{
	return a * x0 + (1.0 - a) * x1;
}

double AudioFns::multiEnv(int n, double x, double ya[], double yb[])
// given an array of y values, number of points n and value of x, this returns the linear interpolation between the y values
{
	int k;
	double a, t;
	if (x >= 1)
		return ya[n - 1] + yb[n - 1];
	else if (x <= 0)
		return ya[0] + yb[0];
	else
	{
		t = 1.0 / ((double)n - 1.0);
		k = (int)floor(x / t) + 1;
		a = k - x / t;
		return a * (ya[k - 1] + yb[k - 1]) + (1.0 - a) * (ya[k] + yb[k]);
	}
}

void AudioFns::filter(double f, double r, double &x, double s, double b[])
// Subtractive style VCF
// This function may be subject to some other form of licence or copyright:
// Source: https://www.musicdsp.org/en/latest/Filters/25-moog-vcf-variation-1.html
// References: CSound source code, Stilson/Smith CCRMA paper.
// Modified by paul.kellett@maxim.abel.co.uk July 2000
// x = signal (0 to 1 range), f = frequency, r = resonance, s = sample rate, 
// b = filter buffers (beware denormals!)
{
	const double MAX_FREQ = 4186.0; // C8
	double c, p, q; //filter coefficients
	double t1, t2; //temporary buffers
	f = 2.0 * MAX_FREQ * f / s; // scale frequency
	// Set coefficients given frequency & resonance
	q = 1 - f;
	p = f + 0.8 * f * q;
	c = p + p - 1;
	q = r * (1 + 0.5 * q * (1 - q + 5.6 * q * q));
	// Filter (in [-1.0...+1.0])
	x -= q * b[4]; //feedback
	t1 = b[1];
	b[1] = (x + b[0]) * p - b[1] * c;
	t2 = b[2];
	b[2] = (b[1] + t1) * p - b[2] * c;
	t1 = b[3];
	b[3] = (b[2] + t2) * p - b[3] * c;
	b[4] = (b[3] + t1) * p - b[4] * c;
	b[4] = b[4] - b[4] * b[4] * b[4] * 0.166667; //clipping
	b[0] = x;
}

double AudioFns::lPF(double f, double r, double x, double s, double b[])
// Low pass filter
{
	filter(f, r, x, s, b);
	return b[4];
}

double AudioFns::hPF(double f, double r, double x, double s, double b[])
// High pass filter
{
	filter(f, r, x, s, b);
	return x - b[4];
}

double AudioFns::bPF(double f, double r, double x, double s, double b[])
// Band pass filter
{
	filter(f, r, x, s, b);
	return 3.0 * (b[3] - b[4]);
}

double supODrive(double x, double g)
// supporting overdrive function
{
	double const GAIN_MAX = 0.975;
	if (g > GAIN_MAX)
		g = GAIN_MAX;
	return pow(x, 1.0 + log(1.0 + g)/log(0.5));
}

double AudioFns::oDrive(double g, double x)
// overdrive / distortion effect
{
	if (x > 0)
		return supODrive(x, g);
	else if (x < 0)
		return -supODrive(abs(x), g);
	else
		return 0;
}

int AudioFns::getCrushBits(double x)
// supporting function for bit crusher
{
	return (int)floor((MAX_CRUSH_BITS - MIN_CRUSH_BITS)*x + MIN_CRUSH_BITS + 0.5);
}

double AudioFns::bitCrush(double x, int n)
// crushes [-1, 1] signal to n bits
{
	int m;
	m = (int)pow(2.0, n);
	return floor(((x + 1)*0.5)*m + 0.5)*2/m - 1;
}
