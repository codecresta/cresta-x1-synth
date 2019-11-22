/*
syn_prs_ifc.c

Added _CRT_SECURE_NO_WARNINGS to preprocessor definitions for this file
*/

#include "syn_prs_ifc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

char syn_err[MAX_SYN_ERR];
int num_mods;
int num_prms;
int num_contrs;
int num_conns;
int num_slds;
int num_evnts;
int stk_ptr;
char* syn_fname;
int syn_lnum;
modStruct mod[MAX_MODS];
prmStruct prm[MAX_PRMS];
contrStruct contr[MAX_CONTRS];
connStruct conn[MAX_CONNS];
sldMapStruct sld_map[MAX_SLDS];
evntStruct evnt[MAX_EVNTS];

void initSynPrs()
// initialises parser variables
{
	syn_err[0] = 0;
	num_mods = 0;
	num_prms = 0;
	num_contrs = 0;
	num_conns = 0;
	num_slds = 0;
	num_evnts = 0;
	stk_ptr = 0;
	syn_lnum = 1;
}

// input index functions, returns the input index given the code, for each module type
int mixerII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return MIXER_SIGNAL;
		default: return -1;
	}
}

int shpOscII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return SHP_OSC_SIGNAL;
		case IC_FINE: return SHP_OSC_FINE;
		case IC_TUNE: return SHP_OSC_TUNE;
		case IC_SHAPE: return SHP_OSC_SHAPE;
		default: return -1;
	}
}

int oscII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return OSC_SIGNAL;
		case IC_FINE: return OSC_FINE;
		case IC_TUNE: return OSC_TUNE;
		default: return -1;
	}
}

int shpLFOII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return SHP_LFO_SIGNAL;
		case IC_RATE: return SHP_LFO_RATE;
		case IC_SHAPE: return SHP_LFO_SHAPE;
		default: return -1;
	}
}

int lfoII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return LFO_SIGNAL;
		case IC_RATE: return LFO_RATE;
		default: return -1;
	}
}

int noiseII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return NOISE_GEN_SIGNAL;
		default: return -1;
	}
}

int rampEnvII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_START_LEVEL: return RAMP_ENV_START_LEVEL;
		case IC_END_LEVEL: return RAMP_ENV_END_LEVEL;
		case IC_AMT_TM: return RAMP_ENV_AMT_TM;
		default: return -1;
	}
}

int multiEnvII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_LEVEL0:	return MULTI_ENV_LEVEL0;
		case IC_LEVEL1:	return MULTI_ENV_LEVEL1;
		case IC_LEVEL2:	return MULTI_ENV_LEVEL2;
		case IC_LEVEL3:	return MULTI_ENV_LEVEL3;
		case IC_LEVEL4:	return MULTI_ENV_LEVEL4;
		case IC_LEVEL5:	return MULTI_ENV_LEVEL5;
		case IC_LEVEL6:	return MULTI_ENV_LEVEL6;
		default: return -1;
	}
}

int xFadeII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_AMT: return X_FADE_AMT;
		case IC_SIGNAL1: return X_FADE_SIGNAL1;
		case IC_SIGNAL2: return X_FADE_SIGNAL2;
		default: return -1;
	}
}

int envShaperII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return ENV_SHAPER_SIGNAL;
		case IC_LEVEL0: return ENV_SHAPER_LEVEL0;
		case IC_LEVEL1: return ENV_SHAPER_LEVEL1;
		case IC_LEVEL2: return ENV_SHAPER_LEVEL2;
		case IC_LEVEL3: return ENV_SHAPER_LEVEL3;
		case IC_LEVEL4: return ENV_SHAPER_LEVEL4;
		case IC_LEVEL5: return ENV_SHAPER_LEVEL5;
		case IC_LEVEL6: return ENV_SHAPER_LEVEL6;
		default: return -1;
	}
}

int filterII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return FILTER_SIGNAL;
		case IC_CUT_OFF: return FILTER_CUT_OFF;
		case IC_RESONANCE: return FILTER_RESONANCE;
		default: return -1;
	}
}

int oDriveII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return O_DRIVE_SIGNAL;
		case IC_GAIN: return O_DRIVE_GAIN;
		default: return -1;
	}
}

int bitCrushII(int inp_cd)
{
	switch (inp_cd)
	{
		case IC_SIGNAL: return BIT_CRUSH_SIGNAL;
		case IC_DEPTH: return BIT_CRUSH_DEPTH;
		default: return -1;
	}
}

int inpIdx(int mod_idx, int inp_cd)
// returns the input index given the module index and input code
{
	int mod_ty;
	mod_ty = mod[mod_idx].ty;
	switch (mod_ty)
	{
		case MIXER:
			return mixerII(inp_cd);
		case SAW_TRI_OSC:
			return shpOscII(inp_cd);
		case PULSE_OSC:
			return shpOscII(inp_cd);
		case SINE_OSC:
			return oscII(inp_cd);
		case SAW_TRI_LFO:
			return shpLFOII(inp_cd);
		case PULSE_LFO:
			return shpLFOII(inp_cd);
		case SINE_LFO:
			return lfoII(inp_cd);
		case NOISE_GEN:
			return noiseII(inp_cd);
		case RAMP_ENV:
			return rampEnvII(inp_cd);
		case MULTI_ENV:
			return multiEnvII(inp_cd);
		case X_FADE:
			return xFadeII(inp_cd);
		case ENV_SHAPER:
			return envShaperII(inp_cd);
		case LP_FILTER:
			return filterII(inp_cd);
		case HP_FILTER:
			return filterII(inp_cd);
		case BP_FILTER:
			return filterII(inp_cd);
		case O_DRIVE:
			return oDriveII(inp_cd);
		case BIT_CRUSH:
			return bitCrushII(inp_cd);
		default:
			return -1;
	}
}

// slider control range functions
int shpOscR(int inp_idx)
{
	return inp_idx == SHP_OSC_SHAPE;
}

int shpLFOR(int inp_idx)
{
	return (inp_idx == SHP_LFO_RATE) || (inp_idx == SHP_LFO_SHAPE);
}

int filterR(int inp_idx)
{
	return (inp_idx == FILTER_CUT_OFF) || (inp_idx == FILTER_RESONANCE);
}

int zORng(int mod_idx, int inp_idx)
// returns true if control requires 0 to 1 range, false if it requires -1 to +1 range
{
	int mod_ty;
	mod_ty = mod[mod_idx].ty;
	switch (mod_ty)
	{
		case MIXER:
			return false;
		case SAW_TRI_OSC:
			return shpOscR(inp_idx);
		case PULSE_OSC:
			return shpOscR(inp_idx);
		case SINE_OSC:
			return false;
		case SAW_TRI_LFO:
			return shpLFOR(inp_idx);
		case PULSE_LFO:
			return shpLFOR(inp_idx);
		case SINE_LFO:
			return inp_idx == SHP_LFO_RATE;
		case NOISE_GEN:
			return false;
		case RAMP_ENV:
			return inp_idx == RAMP_ENV_AMT_TM;
		case MULTI_ENV:
			return false;
		case X_FADE:
			return inp_idx == X_FADE_AMT;
		case ENV_SHAPER:
			return false;
		case LP_FILTER:
			return filterR(inp_idx);
		case HP_FILTER:
			return filterR(inp_idx);
		case BP_FILTER:
			return filterR(inp_idx);
		case O_DRIVE:
			return inp_idx == O_DRIVE_GAIN;
		case BIT_CRUSH:
			return inp_idx == BIT_CRUSH_DEPTH;
		default:
			return -1;
	}
}

int modIdx(int line_num, const char* name)
// returns the module index given the name
{
	int i;
	i = 0;
	while (i < num_mods)
	{
		if (strcmp(name, mod[i].name) == 0)
			return i;
		i++;
	}
	sprintf(syn_err, "Error on line %d: module %s not found.", line_num, name);
	return -1;
}

void appMod(int line_num, int ty, const char* name)
// appends a module by storing its type and name
{
	if (num_mods < MAX_MODS)
	{
		mod[num_mods].ty = ty;
		mod[num_mods++].name = _strdup(name);
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of modules exceeded.", line_num);
}

void appPrm(int line_num, int prm_idx, double value)
// appends a paremeter setting by storing its index and value
{
	if (num_prms < MAX_PRMS)
	{
		prm[num_prms].prm_idx = prm_idx;
		prm[num_prms++].value = value;
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of parameters exceeded.", line_num);
}

void appContr(int line_num, int mod_idx, int inp_cd, double value)
// appends a controller by storing the module index, input index and value
{
	if (num_contrs < MAX_CONTRS)
	{
		contr[num_contrs].mod_idx = mod_idx;
		contr[num_contrs].inp_idx = inpIdx(mod_idx, inp_cd);
		if (contr[num_contrs].inp_idx == -1)
			sprintf(syn_err, "Unrecognised input on line %d.", line_num);
		contr[num_contrs++].value = value;
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of controllers exceeded.", line_num);
}

void appConn(int line_num, int src_cd, int dest, int inp_cd, double amt)
// appends a connection by storing the source code, destination module index, controller index and amount
{
	if (num_conns < MAX_CONNS)
	{
		if ((src_cd < 0) && (src_cd < -MAX_AUXS))
			sprintf(syn_err, "Maximum auxillary index exceeded on line %d.", line_num);
		conn[num_conns].src_cd = src_cd;
		conn[num_conns].dest_mod_idx = dest;
		conn[num_conns].inp_idx = inpIdx(dest, inp_cd);
		if (conn[num_conns].inp_idx == -1)
			sprintf(syn_err, "Unrecognised input on line %d.", line_num);
		conn[num_conns++].amt = amt;
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of connections exceeded.", line_num);
}

void appSldMap(int line_num, int ty, int src, int dest, int cd, const char* name)
// appends a potentiometer by storing the type, module index and controller index or input index
{
	if (num_slds < MAX_SLDS)
	{
		sld_map[num_slds].ty = ty;
		sld_map[num_slds].mod_idx = dest;
		sld_map[num_slds].inp_idx = inpIdx(dest, cd);
		if (sld_map[num_slds].inp_idx == -1)
			sprintf(syn_err, "Unrecognised input on line %d.", line_num);
		else
			sld_map[num_slds].zo_rng = zORng(sld_map[num_slds].mod_idx, sld_map[num_slds].inp_idx);
		sld_map[num_slds].src_idx = src;
		sld_map[num_slds++].name = _strdup(name);
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of potentiometers exceeded.", line_num);
}

void appEvnt(int line_num, int ty, double data, double duration, int step)
// appends a sequencer event
{
	if (num_evnts < MAX_EVNTS)
	{
		evnt[num_evnts].ty = ty;
		evnt[num_evnts].data = data;
		evnt[num_evnts].duration = duration;
		evnt[num_evnts++].step = step;
	}
	else
		sprintf(syn_err, "Error on line %d: maximum number of events exceeded.", line_num);
}

void freeSynPrs()
// frees parser variables
{
	int i;
	for (i = 0; i < num_mods; i++)
		free(mod[i].name);
	for (i = 0; i < num_slds; i++)
		free(sld_map[i].name);
}