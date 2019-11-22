/*
voice_prms.h
*/

#include "syn_prms.h"

class VoicePrms
{
	public:
		double tm; // time, starts at zero when note first sounds
		double lev;  // level
		double off_tm; // note off time
		double off_lev; // note off level
		double pitch;  // pitch
		double gain; // gain
		bool note_on; // note on
		void init(double d);
		void noteOff();
		void upd(SynthPrms sp);
		double vol(SynthPrms sp);
		bool envFin(SynthPrms sp);
};