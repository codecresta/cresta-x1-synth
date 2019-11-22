/*
module.cpp
*/

#include "module.h"
#include "audio_fns.h"

void BaseModule::clrInps()
// clears the connectors on input i
{
	int i;
	for (i = 0; i <= lastInp(); i++)
		n_conns[i] = 0;
}

void BaseModule::appInp(int inp, int src, double amt)
// appends an input with source module mod_idx and amount amt
{
	src_cd[inp][n_conns[inp]] = src;
	src_amt[inp][n_conns[inp]] = amt;
	n_conns[inp]++;
}

void BaseModule::setContr(int idx, double value)
// sets a controller to the value passed
{
	contr[idx] = value;
}

double BaseModule::getContr(int idx)
// gets a controller value
{
	return contr[idx];
}

void BaseModule::clrContrs()
// sets all controllers to zero
{
	int i;
	for (i = 0; i <= lastInp(); i++)
		contr[i] = 0;
}

void BaseModule::setSrcAmt(int inp, int conn, double amt)
// sets a modulation source amount
{
	src_amt[inp][conn] = amt;
}

void BaseModule::clrSrcAmts()
// sets all source amounts to zero
{
	int i, j;
	for (i = 0; i <= lastInp(); i++)
		for (j = 0; j < n_conns[i]; j++)
			src_amt[i][j] = 0;
}

double BaseModule::getSrcAmt(int inp, int conn)
// gets a modulation source amount
{
	return src_amt[inp][conn];
}

int BaseModule::fndConnIdx(int inp, int src)
// finds the connection for a particular input that is originating from the given source module
{
	int j;
	j = 0;
	while (j < n_conns[inp])
	{
		if (src_cd[inp][j] == src)
			return j;
		j++;
	}
	return -1;
}

// specific module functions and updates
double MixerModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = contr[MIXER_SIGNAL] + inp[MIXER_SIGNAL];
	return out;
}

void ShpOscModule::upd(double inp[], SynthPrms sp, VoicePrms vp)
{
	double f;
	f = AudioFns::freq(vp.pitch + contr[SHP_OSC_FINE] + inp[SHP_OSC_FINE] +
		(contr[SHP_OSC_TUNE] + inp[SHP_OSC_TUNE]) * sp.range);
	pos = AudioFns::updPos(pos, f, sp.smps);
}

double SawTriOscModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[SHP_OSC_SIGNAL] + inp[SHP_OSC_SIGNAL]) * 
		AudioFns::sawTri(pos, AudioFns::zOClip(contr[SHP_OSC_SHAPE] + inp[SHP_OSC_SHAPE]));
	return out;
}

double PulseOscModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[SHP_OSC_SIGNAL] + inp[SHP_OSC_SIGNAL]) * 
		AudioFns::pulse(pos, AudioFns::zOClip(contr[SHP_OSC_SHAPE] + inp[SHP_OSC_SHAPE]));
	return out;
}

void SineOscModule::upd(double inp[], SynthPrms sp, VoicePrms vp)
{
	double f;
	f = AudioFns::freq(vp.pitch + contr[OSC_FINE] + inp[OSC_FINE] +
		(contr[OSC_TUNE] + inp[OSC_TUNE]) * sp.range);
	pos = AudioFns::updPos(pos, f, sp.smps);
}

double SineOscModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[OSC_SIGNAL] + inp[OSC_SIGNAL]) * AudioFns::sine(pos);
	return out;
}

void ShpLFOModule::upd(double inp[], SynthPrms sp, VoicePrms vp)
{
	pos = AudioFns::updPos(pos, RATE_CONST()*(contr[SHP_LFO_RATE] + inp[SHP_LFO_RATE]), sp.smps);
}

double SawTriLFOModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[SHP_LFO_SIGNAL] + inp[SHP_LFO_SIGNAL]) *
		AudioFns::sawTri(pos, AudioFns::zOClip(contr[SHP_LFO_SHAPE] + inp[SHP_LFO_SHAPE]));
	return out;
}

double PulseLFOModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[SHP_LFO_SIGNAL] + inp[SHP_LFO_SIGNAL]) * 
		AudioFns::pulse(pos, AudioFns::zOClip(contr[SHP_LFO_SHAPE] + inp[SHP_LFO_SHAPE]));
	return out;
}

void SineLFOModule::upd(double inp[], SynthPrms sp, VoicePrms vp)
{
	pos = AudioFns::updPos(pos, RATE_CONST()*(contr[LFO_RATE] + inp[LFO_RATE]), sp.smps);
}

double SineLFOModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[LFO_SIGNAL] + inp[LFO_SIGNAL]) * AudioFns::sine(pos);
	return out;
}

double NoiseModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = (contr[NOISE_GEN_SIGNAL] + inp[NOISE_GEN_SIGNAL]) * AudioFns::noise();
	return out;
}

double RampEnvModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
    out = AudioFns::ramp(vp.tm / ((contr[RAMP_ENV_AMT_TM] + inp[RAMP_ENV_AMT_TM])* sp.note_tm),
		contr[RAMP_ENV_START_LEVEL] + inp[RAMP_ENV_START_LEVEL], contr[RAMP_ENV_END_LEVEL] + inp[RAMP_ENV_END_LEVEL]);
	return out;
}

double MultiEnvModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::multiEnv(7, vp.tm / sp.note_tm, contr, inp);
	return out;
}

double XFadeModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::crossFade(AudioFns::zOClip(contr[X_FADE_AMT] + inp[X_FADE_AMT]), contr[X_FADE_SIGNAL1] + inp[X_FADE_SIGNAL1],
		contr[X_FADE_SIGNAL2] + inp[X_FADE_SIGNAL2]);
	return out;
}

double EnvShaperModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::multiEnv(7, AudioFns::clip(contr[ENV_SHAPER_SIGNAL] + inp[ENV_SHAPER_SIGNAL]), contr, inp);
	return out;
}

double LPFilterModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::lPF(contr[FILTER_CUT_OFF] + inp[FILTER_CUT_OFF], contr[FILTER_RESONANCE] + inp[FILTER_RESONANCE],
		contr[FILTER_SIGNAL] + inp[FILTER_SIGNAL], sp.smps, buf);
	return out;
}

double HPFilterModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::hPF(contr[FILTER_CUT_OFF] + inp[FILTER_CUT_OFF], contr[FILTER_RESONANCE] + inp[FILTER_RESONANCE],
		contr[FILTER_SIGNAL] + inp[FILTER_SIGNAL], sp.smps, buf);
	return out;
}

double BPFilterModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	out = AudioFns::bPF(contr[FILTER_CUT_OFF] + inp[FILTER_CUT_OFF], contr[FILTER_RESONANCE] + inp[FILTER_RESONANCE],
		contr[FILTER_SIGNAL] + inp[FILTER_SIGNAL], sp.smps, buf);
	return out;
}

double ODriveModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	double g;
	g = contr[O_DRIVE_GAIN] + inp[O_DRIVE_GAIN];
	if (g > 1)
		g = 1;
	out = AudioFns::oDrive(g, contr[O_DRIVE_SIGNAL] + inp[O_DRIVE_SIGNAL]);
	return out;
}

double BitCrushModule::fn(double inp[], SynthPrms sp, VoicePrms vp)
{
	int n;
	n = AudioFns::getCrushBits(contr[BIT_CRUSH_DEPTH] + inp[BIT_CRUSH_DEPTH]);
	out = AudioFns::bitCrush(contr[BIT_CRUSH_SIGNAL] + inp[BIT_CRUSH_SIGNAL], n);
	return out;
}