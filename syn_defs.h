/*
syn_defs.h
Defines various constants.

Inputs to the modules are as follows:
MIXER: (0) signal
SAW_TRI_OSC, PULSE_OSC: (0) signal (1) fine tune (2) tune (3) shape
SINE_OSC: (0) signal (1) fine tune (2) tune 
SAW_TRI_LFO, PULSE_LFO: (0) signal (1) rate (2) shape 
SINE_LFO: (0) signal (1) rate
NOISE_GEN: (0) signal
RAMP_ENV: (0) start level (1) end level (2) amount of gate time
MULTI_ENV: (0..6) levels
X_FADE: (0) amount (1) signal 1 (2) signal 2
ENV_SHAPER: (0..6) levels (7) signal 
LP_FILTER, HP_FILTER, BP_FILTER: (0) signal (1) cut off (2) resonance
O_DRIVE: (0) signal (1) gain 
BIT_CRUSH: (0) signal (1) depth bits
*/

#ifndef SYNTH_DEFS
#define SYNTH_DEFS

#define MAX_VOICES 8
#define MAX_MODS 32
#define MAX_PRMS 6
#define MAX_CONTRS 512
#define MAX_CONNS 64
#define MAX_AUXS 8
#define MAX_SLDS 8
#define MAX_EVNTS 1024
#define MOD_MAX_CONNS 4
#define MOD_MAX_INPS 8

// module types
#define MIXER 0
#define SAW_TRI_OSC 1
#define PULSE_OSC 2
#define SINE_OSC 3
#define SAW_TRI_LFO 4
#define PULSE_LFO 5
#define SINE_LFO 6
#define NOISE_GEN 7
#define RAMP_ENV 8
#define MULTI_ENV 9
#define X_FADE 10
#define ENV_SHAPER 11
#define LP_FILTER 12
#define HP_FILTER 13
#define BP_FILTER 14
#define O_DRIVE 15
#define BIT_CRUSH 16

// parameters
#define P_BPM 0
#define P_METER 1
#define P_RANGE 2
#define P_ATK 3
#define P_DEC 4
#define P_SUS 5
#define P_REL 6

// input indices
#define MIXER_SIGNAL 0

#define SHP_OSC_SIGNAL 0
#define SHP_OSC_FINE 1
#define SHP_OSC_TUNE 2
#define SHP_OSC_SHAPE 3

#define OSC_SIGNAL 0
#define OSC_FINE 1
#define OSC_TUNE 2

#define SHP_LFO_SIGNAL 0
#define SHP_LFO_RATE 1
#define SHP_LFO_SHAPE 2

#define LFO_SIGNAL 0
#define LFO_RATE 1

#define NOISE_GEN_SIGNAL 0

#define RAMP_ENV_START_LEVEL 0
#define RAMP_ENV_END_LEVEL 1
#define RAMP_ENV_AMT_TM 2

#define MULTI_ENV_LEVEL0 0
#define MULTI_ENV_LEVEL1 1
#define MULTI_ENV_LEVEL2 2
#define MULTI_ENV_LEVEL3 3
#define MULTI_ENV_LEVEL4 4
#define MULTI_ENV_LEVEL5 5
#define MULTI_ENV_LEVEL6 6

#define X_FADE_AMT 0
#define X_FADE_SIGNAL1 1
#define X_FADE_SIGNAL2 2

#define ENV_SHAPER_LEVEL0 0
#define ENV_SHAPER_LEVEL1 1
#define ENV_SHAPER_LEVEL2 2
#define ENV_SHAPER_LEVEL3 3
#define ENV_SHAPER_LEVEL4 4
#define ENV_SHAPER_LEVEL5 5
#define ENV_SHAPER_LEVEL6 6
#define ENV_SHAPER_SIGNAL 7

#define FILTER_SIGNAL 0
#define FILTER_CUT_OFF 1
#define FILTER_RESONANCE 2

#define O_DRIVE_SIGNAL 0
#define O_DRIVE_GAIN 1

#define BIT_CRUSH_SIGNAL 0
#define BIT_CRUSH_DEPTH 1

// events
#define NOTE_EVENT 0

#define C_N 0
#define C_SH_N 1
#define D_N 2
#define D_SH_N 3
#define E_N 4
#define F_N 5
#define F_SH_N 6
#define G_N 7
#define G_SH_N 8
#define A_N 9
#define A_SH_N 10
#define B_N 11

// slider types
#define CONTR_SLDR 0
#define MOD_SLDR 1

#endif