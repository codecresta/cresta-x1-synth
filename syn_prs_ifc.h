/*
syn_prs_ifc.h
Defines various structures used to describe a parsed synth file.
*/

#include "syn_defs.h"

#define MAX_SYN_ERR 120

// input codes
#define IC_SIGNAL 0
#define IC_FINE 1
#define IC_TUNE 2
#define IC_SHAPE 3
#define IC_RATE 4
#define IC_START_LEVEL 5
#define IC_END_LEVEL 6
#define IC_AMT_TM 7
#define IC_LEVEL0 8
#define IC_LEVEL1 9
#define IC_LEVEL2 10
#define IC_LEVEL3 11
#define IC_LEVEL4 12
#define IC_LEVEL5 13
#define IC_LEVEL6 14
#define IC_AMT 15
#define IC_CUT_OFF 16
#define IC_RESONANCE 17
#define IC_GAIN 18
#define IC_SIGNAL1 19
#define IC_SIGNAL2 20
#define IC_DEPTH 21

typedef struct
{
	int ty;
	char* name;
} modStruct;

typedef struct
{
	int prm_idx;
	double value;
} prmStruct;

typedef struct
{
	int mod_idx;
	int inp_idx;
	double value;
} contrStruct;

typedef struct
{
	int src_cd;
	int dest_mod_idx;
	int inp_idx;
	double amt;
} connStruct;

typedef struct
{
	int ty;
	int mod_idx;
	int inp_idx;
	int zo_rng;
	int src_idx;
	char* name;
} sldMapStruct;

typedef struct
{
	int ty;
	double data;
	double duration;
	int step;
} evntStruct;

void initSynPrs();
int modIdx(int line_num, const char* name);
void appMod(int line_num, int ty, const char* name);
void appPrm(int line_num, int prm_idx, double value);
void appContr(int line_num, int mod_idx, int inp_cd, double value);
void appConn(int line_num, int src_cd, int dest, int inp_cd, double amt);
void appSldMap(int line_num, int ty, int src, int dest, int cd, const char* name);
void appEvnt(int line_num, int ty, double data, double duration, int step);
void freeSynPrs();

extern char syn_err[MAX_SYN_ERR];
extern int num_mods;
extern int num_prms;
extern int num_contrs;
extern int num_conns;
extern int num_slds;
extern int num_evnts;
extern int stk_ptr;
extern char* syn_fname;
extern int syn_lnum;
extern modStruct mod[MAX_MODS];
extern prmStruct prm[MAX_PRMS];
extern contrStruct contr[MAX_CONTRS];
extern connStruct conn[MAX_CONNS];
extern sldMapStruct sld_map[MAX_SLDS];
extern evntStruct evnt[MAX_EVNTS];