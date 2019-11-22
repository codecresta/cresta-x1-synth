/*
voice.h
*/

#include "module.h"

class Voice
{
	public:
		void clrMods();
		Voice();
		~Voice();
		void initSeq();
		void init(double d);
		void unmark();
		double out(int k, SynthPrms sp);
		double proc(bool note_on, SynthPrms sp);
		bool envFin(SynthPrms sp);
		int n_mods;
		bool act; // active?
		double off_tm; // off time (relative to start of sequence)
		BaseModule* mod[MAX_MODS];
		VoicePrms vp;
		void appMod(int ty);
		void zeroVals();
};