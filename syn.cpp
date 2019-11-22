/*
synth.cpp
*/

#include "syn.h"
#include "audio_fns.h"
#include <iostream>
#include <fstream>

#define SMP_RATE 44100
#define SMP_SCALE 32767.0

extern "C"
{
	#include "syn_prs_ifc.h"
	#include "syn_prs.h"
	#include "syn_lxr.h"
}

int yyparse(yyscan_t scanner);

Synth::Synth()
// constructor
{
	sp.smps = SMP_RATE;
	sp.tm_step = 1.0/sp.smps;
}

void Synth::clr()
// clears all voices
{
	int i;
	for (i = 0; i < MAX_VOICES; i++)
		voice[i].clrMods();
}

void Synth::defaPrms()
// sets the synth parameters to default values
{
	sp.bpm = DEFA_BPM;
	sp.meter = DEFA_METER;
	sp.range = DEFA_RANGE;
	sp.atk = DEFA_ATK;
	sp.dec = DEFA_DEC;
	sp.sus = DEFA_SUS;
	sp.rel = DEFA_REL;
}

void Synth::setPrm(int prm_idx, double value)
// sets the synth parameter based on the index passed
{
	switch (prm_idx)
	{
		case P_BPM: sp.bpm = value; break;
		case P_METER: sp.meter = value; break;
		case P_RANGE: sp.range = (int)value; break;
		case P_ATK: sp.atk = value; break;
		case P_DEC: sp.dec = value; break;
		case P_SUS: sp.sus = value; break;
		case P_REL: sp.rel = value; break;
		default: break;
	}
}

int Synth::fndConnIdx(int mod_idx, int inp_idx, int src_idx)
// finds the appropriate connection
{
	return voice[0].mod[mod_idx]->fndConnIdx(inp_idx, src_idx);
}

void Synth::appSld(int ty, int mod_idx, int zo_rng, int inp_idx, int src_idx, std::string name)
// appends the slider of the given index and type etc
{
	cus_sld[num_cus_slds].ty = ty;
	cus_sld[num_cus_slds].mod_idx = mod_idx;
	cus_sld[num_cus_slds].zo_rng = zo_rng;
	cus_sld[num_cus_slds].cus_idx = inp_idx;
	if (ty == CONTR_SLDR)
	{
		cus_sld[num_cus_slds].conn_idx = 0;
		cus_sld[num_cus_slds].src_idx = 0;
	}
	else
	{
		cus_sld[num_cus_slds].conn_idx = fndConnIdx(mod_idx, inp_idx, src_idx);
		cus_sld[num_cus_slds].src_idx = src_idx;
	}
	cus_sld[num_cus_slds++].name = name;
}

void Synth::appSeqEvnt(int ty, double data, double duration, int step)
// appends an event to the sequencer
{
	seq_evnt[seq_steps].ty = ty;
	seq_evnt[seq_steps].data = data;
	seq_evnt[seq_steps].duration = duration;
	seq_evnt[seq_steps].step = step;
	seq_evnt[seq_steps++].smp_pos = sp.step_pos * sp.step_smps;
	sp.step_pos += step;
}

void Synth::recalcPos()
// recalculates the sample positions
{
	int i, j;
	j = 0;
	for (i = 0; i < seq_steps; i++)
	{
		seq_evnt[i].smp_pos = j * sp.step_smps;
		j += seq_evnt[i].step;
	}
}

void Synth::calcPrms()
// calculates some parameters
{
	sp.note_tm = floor(60.0 * sp.smps / (sp.bpm * sp.meter / 4) + 0.5) / sp.smps;
	sp.step_smps = (int)(floor(sp.smps * sp.note_tm + 0.5));
}

void Synth::calcTot()
// calculates number of samples in the sequence
{
	int i, steps;
	steps = 0;
	for (i = 0; i < seq_steps; i++)
		steps += seq_evnt[i].step;
	sp.tot_smps = sp.step_smps * steps;
}

bool Synth::read(std::string fname)
// reads the file using flex / bison, converts C data to the appropriate C++
{
	int err, i, j;
	yyscan_t scanner;
	FILE *src;
	std::string name_str;
	bool ret_val;
	syn_fname = _strdup(fname.c_str());
	if (synlex_init(&scanner))
	{
		err_str = "Error initialising scanner.";
        return false;
	}
	src = fopen(fname.c_str(), "r");
	if (src == NULL)
	{
		err_str = "Could not open file: " + fname;
		ret_val = false;
	}
	else
	{
		synset_in(src, scanner);
		initSynPrs();
		err = synparse(scanner);
		if (err)
		{
			err_str = syn_err;
			ret_val = false;
		}
		else
		{
			if (syn_err[0] == 0)
			{
				clr();
				seq_steps = 0;
				num_cus_slds = 0;
				defaPrms();
				for (i = 0; i < num_prms; i++)
					setPrm(prm[i].prm_idx, prm[i].value);
				calcPrms();
				for (i = 0; i < MAX_VOICES; i++)
				{
					for (j = 0; j < num_mods; j++)
					{
						voice[i].appMod(mod[j].ty);
						voice[i].mod[j]->clrInps();
					}
					voice[i].zeroVals();
					for (j = 0; j < num_conns; j++)
						voice[i].mod[conn[j].dest_mod_idx]->appInp(conn[j].inp_idx, conn[j].src_cd, conn[j].amt);  
					for (j = 0; j < num_contrs; j++)
						voice[i].mod[contr[j].mod_idx]->setContr(contr[j].inp_idx, contr[j].value);
				}
				for (i = 0; i < num_slds; i++)
				{
					name_str = sld_map[i].name;
					appSld(sld_map[i].ty, sld_map[i].mod_idx, sld_map[i].zo_rng, sld_map[i].inp_idx, sld_map[i].src_idx, name_str);
				}
				sp.step_pos = 0;
				for (i = 0; i < num_evnts; i++)
					appSeqEvnt(evnt[i].ty, evnt[i].data, evnt[i].duration, evnt[i].step);
				calcTot();
				ret_val = true;
			}
			else
			{
				err_str = syn_err;
				ret_val = false;
			}
		}
		fclose(src);
	}
    syn_delete_buffer(0, scanner);
    synlex_destroy(scanner);
	freeSynPrs();
	return ret_val;
}

void Synth::setSldVal(int idx, double value)
// sets the specified slider (pot) value for all voices
{
	int i;
	for (i = 0; i < MAX_VOICES; i++)
		if (cus_sld[idx].ty == CONTR_SLDR)
			voice[i].mod[cus_sld[idx].mod_idx]->setContr(cus_sld[idx].cus_idx, value);
		else
			voice[i].mod[cus_sld[idx].mod_idx]->setSrcAmt(cus_sld[idx].cus_idx, cus_sld[idx].conn_idx, value);
}

bool Synth::isZORng(int idx)
// return true if the slider has a zero to one range
{
	return cus_sld[idx].zo_rng == 1;
}

double Synth::getSldVal(int idx)
// gets the specified slider value
{
	if (cus_sld[idx].ty == CONTR_SLDR)
		return voice[0].mod[cus_sld[idx].mod_idx]->getContr(cus_sld[idx].cus_idx);
	else
		return voice[0].mod[cus_sld[idx].mod_idx]->getSrcAmt(cus_sld[idx].cus_idx, cus_sld[idx].conn_idx);
}

void Synth::initSeq()
// initialises the synth before sequencing
{
	int i;
	sp.tm = 0;
	sp.smp_pos = 0;
	sp.step_pos = 0;
	seq_cnt = 0;
    for (i = 0; i < MAX_VOICES; i++)
    {
        voice[i].act = false;
        voice[i].initSeq();
    }
	for (i = 0; i < MAX_AUXS; i++)
		sp.aux[i] = 0;
}

double Synth::slew(double x, double y, double r)
// slew rate limiter, x is current value, y is target value and r is rate (max change)
{
	if (x <= y)
	{
		if (y - x >= r)
			return x + r;
		else
			return y;
	}
	else
	{
		if (x - y >= r)
			return x - r;
		else
			return y;
	}
}

double Synth::rend(bool new_note)
// renders a single sample
{
	double x;
	int i, s1;
	if (new_note && (seq_evnt[sp.step_pos].smp_pos == sp.smp_pos))
	{
		s1 = sp.step_pos;
		while ((s1 < seq_steps) && (seq_evnt[s1].smp_pos == sp.smp_pos))
		{
			if (seq_evnt[s1].ty == NOTE_EVENT)
			{
				i = 0;
				while ((i < MAX_VOICES) && voice[i].act)
					i++;
				if (i != MAX_VOICES)
				{
					voice[i].act = true;
					voice[i].off_tm = sp.tm + seq_evnt[s1].duration * sp.note_tm;
					voice[i].init(seq_evnt[s1].data);
				}
			}
			else
				sp.aux[seq_evnt[s1].ty] = seq_evnt[s1].data;
			s1++;
		}
		if (s1 == seq_steps)
			seq_cnt++;
		sp.step_pos = s1 % seq_steps;
	}
	x = 0;
	i = 0;
	while (i < MAX_VOICES)
	{
		if (voice[i].act)
		{
			x += voice[i].proc(voice[i].off_tm >= sp.tm, sp);
			if (voice[i].envFin(sp))
				voice[i].act = false;
		}
        i++;
	}
	sp.smp_pos = (sp.smp_pos + 1) % sp.tot_smps;
	sp.tm += sp.tm_step;
	return AudioFns::clip(x);
}

int Synth::totSmps(int num_seqs)
// first calculates the total number of sequencer steps, then calculates the total time using
// the release time, then calculates the total number of samples
{
	int i;
	double step_pos, end_step, max_step;
	step_pos = 0;
	max_step = 0;
	for (i = 0; i < seq_steps; i++)
	{
		end_step = step_pos + seq_evnt[i].duration;
		if (end_step > max_step)
			max_step = end_step;
		step_pos += seq_evnt[i].step;
	}
	return (int)(((num_seqs - 1) * step_pos + max_step + sp.rel ) * sp.note_tm / sp.tm_step + 0.5);
}

void Synth::rendFile(std::string fname, int num_seqs)
// renders sequences to wav file
{
	std::ofstream sfile(fname, std::ios::out | std::ios::binary);
	int tot_smps, i;
	short smp;
	char u, l;
	tot_smps = totSmps(num_seqs);
	initSeq();
	int smps_per_sec = sp.smps;
	int riff = 0x46464952;
	int wave = 0x45564157;
	int fmt_chnk_sz = 16;
	int hdr_sz = 8;
	int fmt = 0x20746D66;
	short fmt_ty = 1;
	short tracks = 2;
	short bits_per_smp = 16;
	short frm_sz = (short)(tracks * ((bits_per_smp + 7) / 8));
	int bytes_per_sec = smps_per_sec * frm_sz;
	int wave_sz = 4;
	int data = 0x61746164;
	int data_chnk_sz = tot_smps * frm_sz;
	int file_sz = wave_sz + hdr_sz + fmt_chnk_sz + hdr_sz + data_chnk_sz;
	sfile.write((char*)&riff, sizeof(int));
	sfile.write((char*)&file_sz, sizeof(int));
	sfile.write((char*)&wave, sizeof(int));
	sfile.write((char*)&fmt, sizeof(int));
	sfile.write((char*)&fmt_chnk_sz, sizeof(int));
	sfile.write((char*)&fmt_ty, sizeof(short));
	sfile.write((char*)&tracks, sizeof(short));
	sfile.write((char*)&smps_per_sec, sizeof(int));
	sfile.write((char*)&bytes_per_sec, sizeof(int));
	sfile.write((char*)&frm_sz, sizeof(short));
	sfile.write((char*)&bits_per_smp, sizeof(short));
	sfile.write((char*)&data, sizeof(int));
	sfile.write((char*)&data_chnk_sz, sizeof(int));
	for (i = 0; i < tot_smps; i++)
	{
		smp = (short)(rend(seq_cnt < num_seqs) * SMP_SCALE);
		l = smp & 0xff;
		u = smp >> 8;
		sfile.write((char*)&l, sizeof(char));
		sfile.write((char*)&u, sizeof(char));
		sfile.write((char*)&l, sizeof(char));
		sfile.write((char*)&u, sizeof(char));
	}
	sfile.close();
}