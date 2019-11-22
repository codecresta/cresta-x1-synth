/*
syn_prms.h
*/

#include "syn_defs.h"

class SynthPrms
// parameters and variables
{
	public:
		double bpm; // beats per minute (adjusted according to the meter)
		int meter; // no. of sequencer events in a bar
		int range; // range
		double atk; // attack (factor not time)
		double dec; // decay (factor)
		double sus; // sustain level
		double rel; // release (factor)
		int smps; // 44100 or 96000 samples per second
		double tm_step; // 1/samps
		int step_smps; // no. of samples in a step
		int tot_smps; // total no. of sample steps in sequence
		double note_tm; // time of one note or one sequencer step
		double tm; // zero at start of sequence
		int smp_pos; // current sample position
		int step_pos; // current sequencer step position
		double aux[MAX_AUXS]; // auxiliary controllers
};
