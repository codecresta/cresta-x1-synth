/*
audio_fns.h
*/

#define DBL_PI 6.283185307179586
#define SLOPE 0.01
#define MIN_CRUSH_BITS 4
#define MAX_CRUSH_BITS 14

class AudioFns
{
	private:
		static void filter(double f, double r, double &x, double s, double b[]);
	public:
		static double zOClip(double x);
		static double clip(double x);
        static double sawTri(double p, double c);
        static double sine(double p);
        static double pulse(double p, double c);
		static double noise();
		static double updPos(double p, double f, double r);
        static double freq(double p);
        static double ramp(double p, double sv, double ev);
        static double aDSR(bool on, double ot, double ol, double t, double at, double dt, double sl, double rt);
        static bool aDSRFin(bool on, double ot, double t, double rt);
        static double crossFade(double a, double x0, double x1);
        static double multiEnv(int n, double x, double ya[], double yb[]);
		static double lPF(double f, double r, double x, double s, double b[]);
		static double hPF(double f, double r, double x, double s, double b[]);
		static double bPF(double f, double r, double x, double s, double b[]);
		static double oDrive(double g, double x);
		static int AudioFns::rndInt(double x);
		static int getCrushBits(double x);
		static double bitCrush(double x, int n);
};