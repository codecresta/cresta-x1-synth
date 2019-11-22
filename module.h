/*
module.h

Implements various types of modules.  See syn_defs.h for input / controller details.
*/

#include "voice_prms.h"
#include "syn_defs.h"
#include <iostream>

#define FILTER_BUF_SZ 5

class BaseModule
{
	public:
		BaseModule() { seq_init = false; }
		virtual ~BaseModule() { }
		int ty; // module type index
        double out; // memorize output
		int src_cd[MOD_MAX_INPS][MOD_MAX_CONNS]; // indices of source modules (for each connector of each input)
		double src_amt[MOD_MAX_INPS][MOD_MAX_CONNS]; // amount of input
		double contr[MOD_MAX_INPS]; // controllers
		int n_conns[MOD_MAX_INPS]; // number of connectors
        bool mark; // used to control recursion
		bool seq_init; // set to true if module needs sequencer initialisation e.g. for an LFO
		void clrInps();
		void appInp(int inp, int src, double amt);
		void setContr(int idx, double value);
		double getContr(int idx);
		void clrContrs();
		void setSrcAmt(int inp, int conn, double amt);
		void clrSrcAmts();
		double getSrcAmt(int inp, int conn);
		int fndConnIdx(int inp, int src);
		virtual int lastInp() = 0;
		virtual bool symInp(int j) = 0;
		virtual void init() { }
		virtual double fn(double inp[], SynthPrms sp, VoicePrms vp) = 0;
		virtual void upd(double inp[], SynthPrms sp, VoicePrms vp) { }
};

class BaseOscModule: public BaseModule
{
	public:
		virtual ~BaseOscModule() { }
		void init() { pos = 0; }
		double pos; // wave position
};

class MixerModule: public BaseModule
{
	public:
		~MixerModule() { }
		int lastInp() { return MIXER_SIGNAL; }
		bool symInp(int j) { return true; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class ShpOscModule: public BaseOscModule
{
	public:
		virtual ~ShpOscModule() { }
		int lastInp() { return SHP_OSC_SHAPE; }
		bool symInp(int j) { return j != SHP_OSC_SHAPE; }
		void upd(double inp[], SynthPrms sp, VoicePrms vp);
	private:
		double offset; // wave form offset
};

class SawTriOscModule: public ShpOscModule
{
	public:
		~SawTriOscModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class PulseOscModule: public ShpOscModule
{
	public:
		~PulseOscModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class SineOscModule: public BaseOscModule
{
	public:
		~SineOscModule() { }
		int lastInp() { return OSC_TUNE; }
		bool symInp(int j) { return true; }
		void upd(double inp[], SynthPrms sp, VoicePrms vp);
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class LFOModule: public BaseOscModule
{
	public:
		LFOModule() { seq_init = true; }
		virtual ~LFOModule() { }
		static const double RATE_CONST() { return 480.0/60.0; }
};

class ShpLFOModule: public LFOModule
{
	public:
		virtual ~ShpLFOModule() { }
		int lastInp() { return SHP_LFO_SHAPE; }
		bool symInp(int j) { return j == SHP_LFO_SIGNAL; }
		void upd(double inp[], SynthPrms sp, VoicePrms vp);
	private:
		double freq; // cycle step size
		double offset; // wave form offset
};

class SawTriLFOModule: public ShpLFOModule
{
	public:
		~SawTriLFOModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class PulseLFOModule: public ShpLFOModule
{
	public:
		~PulseLFOModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class SineLFOModule: public LFOModule
{
	public:
		~SineLFOModule() { }
		int lastInp() { return LFO_RATE; }
		bool symInp(int j) { return j == LFO_SIGNAL; }
		void upd(double inp[], SynthPrms sp, VoicePrms vp);
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class NoiseModule: public BaseModule
{
	public:
		~NoiseModule() { }
		int lastInp() { return NOISE_GEN_SIGNAL; }
		bool symInp(int j) { return true; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class RampEnvModule: public BaseModule
{
	public:
		~RampEnvModule() { }
		int lastInp() { return RAMP_ENV_AMT_TM; }
		bool symInp(int j) { return false; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class MultiEnvModule: public BaseModule
{
	public:
		~MultiEnvModule() { }
		int lastInp() { return MULTI_ENV_LEVEL6; }
		bool symInp(int j) { return false; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class XFadeModule: public BaseModule
{
	public:
		~XFadeModule() { }
		int lastInp() { return X_FADE_SIGNAL2; }
		bool symInp(int j) { return j != X_FADE_AMT; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class EnvShaperModule: public BaseModule
{
	public:
		~EnvShaperModule() { }
		int lastInp() { return ENV_SHAPER_SIGNAL; }
		bool symInp(int j) { return j == ENV_SHAPER_SIGNAL; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class FilterModule: public BaseModule
{
	public:
		virtual ~FilterModule() { }
		double buf[FILTER_BUF_SZ];
		int lastInp() { return FILTER_RESONANCE; }
		bool symInp(int j) { return j == FILTER_SIGNAL; }
		void init() { buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = 0; }
};

class LPFilterModule: public FilterModule
{
	public:
		~LPFilterModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class HPFilterModule: public FilterModule
{
	public:
		~HPFilterModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class BPFilterModule: public FilterModule
{
	public:
		~BPFilterModule() { }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class ODriveModule: public BaseModule
{
	public:
		~ODriveModule() { }
		int lastInp() { return O_DRIVE_GAIN; }
		bool symInp(int j) { return j == O_DRIVE_SIGNAL; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};

class BitCrushModule: public BaseModule
{
	public:
		~BitCrushModule() { }
		int lastInp() { return BIT_CRUSH_DEPTH; }
		bool symInp(int j) { return j == BIT_CRUSH_SIGNAL; }
		double fn(double inp[], SynthPrms sp, VoicePrms vp);
};
