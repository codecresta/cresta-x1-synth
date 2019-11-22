/*
syn.h
*/

#include "voice.h"
#include <string>

#define DEFA_BPM 120
#define DEFA_METER 4
#define DEFA_RANGE 12
#define DEFA_ATK 0.1
#define DEFA_DEC 0.1
#define DEFA_SUS 1
#define DEFA_REL 0.1

class SeqEvnt
{
	public:
		int ty;
        double data;
		double duration;
		int step;
		int smp_pos;
};

class CusSld
{
	public:
		int ty;
		int mod_idx;
		int zo_rng;
		int cus_idx;
		int conn_idx;
		int src_idx;
		std::string name;
};

class Synth
// an array of voices with a sequencer and sliders (pots)
{
	public:
		Synth();
		~Synth() { }
		int seq_steps;
		int num_cus_slds;
		int seq_cnt;
		std::string err_str;
		SynthPrms sp;
        Voice voice[MAX_VOICES]; // voices
        SeqEvnt seq_evnt[MAX_EVNTS]; // event sequence in order
		CusSld cus_sld[MAX_SLDS];
		bool read(std::string fname);
		void setSldVal(int idx, double value);
		bool isZORng(int idx);
		double getSldVal(int idx);
		void initSeq();
		static double slew(double x, double y, double r);
		double rend(bool new_note);
		void clr();
		void defaPrms();
		void calcPrms();
		void calcTot();
		void recalcPos();
		void rendFile(std::string fname, int num_seqs);
	private:
		void setPrm(int prm_idx, double value);
		void appSld(int ty, int mod_idx, int zo_rng, int inp_idx, int src_idx, std::string name);
		int fndConnIdx(int mod, int inp, int src);
		void appSeqEvnt(int ty, double data, double duration, int step);
		int totSmps(int num_seqs);
};