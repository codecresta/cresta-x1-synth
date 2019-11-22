/*
voice.cpp
*/

#include "voice.h"
#include "audio_fns.h"
#include <stddef.h>

Voice::Voice()
// constructor
{
	int i;
	for (i = 0; i < MAX_MODS; i++)
		mod[i] = NULL;
	n_mods = 0;
}

void Voice::clrMods()
// clears modules from memory
{
	int i;
	for (i = 0; i < n_mods; i++)
	{
		delete mod[i];
		mod[i] = NULL;
	}
	n_mods = 0;
}

Voice::~Voice()
// destructor
{
	clrMods();
}

void Voice::appMod(int ty)
// appends a module
{
	switch(ty)
	{
		case MIXER :
			mod[n_mods] = new MixerModule();
			break;
		case SAW_TRI_OSC :
			mod[n_mods] = new SawTriOscModule();
			break;
		case PULSE_OSC :
			mod[n_mods] = new PulseOscModule();
			break;
		case SINE_OSC :
			mod[n_mods] = new SineOscModule();
			break;
		case SAW_TRI_LFO :
			mod[n_mods] = new SawTriLFOModule();
			break;
		case PULSE_LFO :
			mod[n_mods] = new PulseLFOModule();
			break;
		case SINE_LFO :
			mod[n_mods] = new SineLFOModule();
			break;
		case NOISE_GEN :
			mod[n_mods] = new NoiseModule();
			break;
		case RAMP_ENV :
			mod[n_mods] = new RampEnvModule();
			break;
		case MULTI_ENV :
			mod[n_mods] = new MultiEnvModule();
			break;
		case X_FADE :
			mod[n_mods] = new XFadeModule();
			break;
		case ENV_SHAPER :
			mod[n_mods] = new EnvShaperModule();
			break;
		case LP_FILTER :
			mod[n_mods] = new LPFilterModule();
			break;
		case HP_FILTER :
			mod[n_mods] = new HPFilterModule();
			break;
		case BP_FILTER :
			mod[n_mods] = new BPFilterModule();
			break;
		case O_DRIVE :
			mod[n_mods] = new ODriveModule();
			break;
		case BIT_CRUSH :
			mod[n_mods] = new BitCrushModule();
			break;
		default :
			mod[n_mods] = NULL;
			break;
	}
	mod[n_mods]->ty = ty;
	n_mods++;
}

void Voice::zeroVals()
// sets the controllers and source amounts to zero
{
	int i;
	for (i = 0; i < n_mods; i++)
	{
		mod[i]->clrContrs();
		mod[i]->clrSrcAmts();
	}
}

void Voice::initSeq()
// initialises seq_init modules
{
	int i;
	for (i = 0; i < n_mods; i++)
		if (mod[i]->seq_init)
		{
			mod[i]->out = 0;
			mod[i]->init();
		}
};

void Voice::init(double d)
// initialises other modules
{
	int i;
	vp.init(d);
	for (i = 0; i < n_mods; i++)
		if (!mod[i]->seq_init)
		{
			mod[i]->out = 0;
			mod[i]->init();
		}
};

double Voice::out(int k, SynthPrms sp)
// recursively calculates the output from kth module by computing the inputs and calling fn for the module
{
    double inp_vals[MOD_MAX_INPS];
    int i, j, l, p, n;
    double x, y;
	if (mod[k]->mark)
		return mod[k]->out;
	else
	{
		mod[k]->mark = true;
		l = mod[k]->lastInp();
		for (i = 0; i <= l; i++)
		{
			n = mod[k]->n_conns[i];
			if (n == 0)
				inp_vals[i] = 0;
			else
			{
				x = 0;
				j = 0;
				while (j < n)
				{
					p = mod[k]->src_cd[i][j];
					if (p < 0)
						x += sp.aux[-1 - p];
					else
						x += mod[k]->src_amt[i][j] * out(p, sp);
					j++;
				}
				if (mod[k]->symInp(i))
					inp_vals[i] = AudioFns::clip(x);
				else
					inp_vals[i] = AudioFns::zOClip(x);
			}
		}
		y = AudioFns::clip(mod[k]->fn(inp_vals, sp, vp));
		mod[k]->upd(inp_vals, sp, vp);
		return y;
	}
}

double Voice::proc(bool note_on, SynthPrms sp)
// unmarks the modules, calculates the output starting at the last module and updates the modules and parameters
{
	int i;
	double x;
	for (i = 0; i < n_mods; i++)
		mod[i]->mark = false;
	if (!note_on)
		vp.noteOff();
	x = vp.vol(sp) * out(n_mods - 1, sp);
	vp.upd(sp);
	return x;
}

bool Voice::envFin(SynthPrms sp)
// returns true if the envelope has finished
{
	return vp.envFin(sp);
}