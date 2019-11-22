%{
	#include "syn_prs_ifc.h"
	#include "syn_prs.h"
	#include "syn_lxr.h"
	int synerror(yyscan_t scanner, const char* msg);
	int curr_mod;
%}

%code requires
{
	#ifndef YYSCAN_T
		#define YYSCAN_T
		typedef void* yyscan_t;
	#endif
}

%output  "syn_prs.c"
%defines "syn_prs.h"
%name-prefix "syn"
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%error-verbose

%union
{
	int num;
	double dbl;
	char ch;
	char* str;
}

%destructor { } <num>
%destructor { } <dbl>
%destructor { } <ch>
%destructor { free($$); } <str>

%token<num> modules parameters connections sequence
%token<num> mixer saw_tri_osc pulse_osc sine_osc saw_tri_lfo pulse_lfo sine_lfo noise_gen
%token<num> ramp_env multi_env x_fade env_shaper lp_filter hp_filter bp_filter o_drive bit_crush
%token<num> bpm meter range atk dec sus rel
%token<num> signal fine tune shape rate start_level end_level amt_tm
%token<num> level0 level1 level2 level3 level4 level5 level6
%token<num> amt cut_off resonance gain signal1 signal2 depth
%token<num> c_n c_sh_n d_n d_sh_n e_n f_n f_sh_n g_n g_sh_n a_n a_sh_n b_n
%token<dbl> value
%token<ch> l_bracket r_bracket semicolon equals comma
%token<str> quoted_str

%%
cmds:
	| cmds cmd
	;

cmd:
	mod_list
	|
	prm_list
	|
	conn_list
	|
	mod_hdr
	|
	seq_hdr
	;

mod_list:
	modules	l_bracket mod_decls r_bracket
	;

mod_decls:
	| mod_decls mod_decl
	;

mod_decl:
	mod_type quoted_str semicolon
	{
		fprintf(stderr, "append module %s\n", $2);
		appMod(syn_lnum, $<num>1, $2);
		free($2);
	}
	;

mod_type:
	mixer { $<num>$ = MIXER; }
	|
	saw_tri_osc { $<num>$ = SAW_TRI_OSC; }
	|
	pulse_osc { $<num>$ = PULSE_OSC; }
	|
	sine_osc { $<num>$ = SINE_OSC; }
	|
	saw_tri_lfo { $<num>$ = SAW_TRI_LFO; }
	|
	pulse_lfo { $<num>$ = PULSE_LFO; }
	|
	sine_lfo { $<num>$ = SINE_LFO; }
	|
	noise_gen { $<num>$ = NOISE_GEN; }
	|
	ramp_env { $<num>$ = RAMP_ENV; }
	|
	multi_env { $<num>$ = MULTI_ENV; }
	|
	x_fade { $<num>$ = X_FADE; }
	|
	env_shaper { $<num>$ = ENV_SHAPER; }
	|
	lp_filter { $<num>$ = LP_FILTER; }
	|
	hp_filter { $<num>$ = HP_FILTER; }
	|
	bp_filter { $<num>$ = BP_FILTER; }
	|
	o_drive { $<num>$ = O_DRIVE; }
	|
	bit_crush { $<num>$ = BIT_CRUSH; }
	;

prm_list:
	parameters l_bracket prms r_bracket
	;

prms:
	| prms prm
	;

prm:
	prm_contr equals value semicolon
	{
		appPrm(syn_lnum, $<num>1, $3);
		fprintf(stderr, "parameter index %d, value %f\n", $<num>1, $3);
	}
	;

prm_contr:
	bpm { $<num>$ = P_BPM; }
	|
	meter { $<num>$ = P_METER; }
	|
	range { $<num>$ = P_RANGE; }
	|
	atk { $<num>$ = P_ATK; }
	|
	dec { $<num>$ = P_DEC; }
	|
	sus { $<num>$ = P_SUS; }
	|
	rel { $<num>$ = P_REL; }
	;

mod_hdr:
	quoted_str
	{
		fprintf(stderr, "module %s\n", $1);
		curr_mod = modIdx(syn_lnum, $1);
		free($1);
	}
	l_bracket settings r_bracket
	;

settings:
	| settings setting
	;

setting:
	input equals value semicolon
	{
		fprintf(stderr, "setting %d, control %d, amount %f\n", curr_mod, $<num>1, $3);
		appContr(syn_lnum, curr_mod, $<num>1, $3);
	}
	|
	input equals value quoted_str semicolon
	{
		fprintf(stderr, "setting %d, control %d, amount %f name %s\n", curr_mod, $<num>1, $3, $4);
		appContr(syn_lnum, curr_mod, $<num>1, $3);
		appSldMap(syn_lnum, CONTR_SLDR, 0, curr_mod, $<num>1, $4);
		free($4);
	}
	;

input:
	signal { $<num>$ = IC_SIGNAL; }
	|
	fine { $<num>$ = IC_FINE; }
	|
	tune { $<num>$ = IC_TUNE; }
	|
	shape { $<num>$ = IC_SHAPE; }
	|
	rate { $<num>$ = IC_RATE; }
	|
	start_level { $<num>$ = IC_START_LEVEL; }
	|
	end_level { $<num>$ = IC_END_LEVEL; }
	|
	amt_tm { $<num>$ = IC_AMT_TM; }
	|
	level0 { $<num>$ = IC_LEVEL0; }
	|
	level1 { $<num>$ = IC_LEVEL1; }
	|
	level2 { $<num>$ = IC_LEVEL2; }
	|
	level3 { $<num>$ = IC_LEVEL3; }
	|
	level4 { $<num>$ = IC_LEVEL4; }
	|
	level5 { $<num>$ = IC_LEVEL5; }
	|
	level6 { $<num>$ = IC_LEVEL6; }
	|
	amt { $<num>$ = IC_AMT; }
	|
	cut_off { $<num>$ = IC_CUT_OFF; }
	|
	resonance { $<num>$ = IC_RESONANCE; }
	|
	gain { $<num>$ = IC_GAIN; }
	|
	signal1 { $<num>$ = IC_SIGNAL1; }
	|
	signal2 { $<num>$ = IC_SIGNAL2; }
	|
	depth { $<num>$ = IC_DEPTH; } 
	;

seq_hdr:
	sequence l_bracket seqs r_bracket
	;

seqs:
	| seqs seq
	;

seq:
	note comma value semicolon
	{
		fprintf(stderr, "note %d, octave %d\n", $<num>1, (int)$3);
		appEvnt(syn_lnum, NOTE_EVENT, (int)($<num>1 + $3*12), 1, 1);
	}
	|
	note comma value comma value semicolon
	{
		fprintf(stderr, "note %d, octave %d, duration %f\n", $<num>1, (int)$3, $5);
		appEvnt(syn_lnum, NOTE_EVENT, (int)($<num>1 + $3*12), $5, (int)$5);
	}
	|
	note comma value comma value comma value semicolon
	{
		fprintf(stderr, "note %d, octave %d, duration %f, step %d\n", $<num>1, (int)$3, $5, (int)$7);
		appEvnt(syn_lnum, NOTE_EVENT, (int)($<num>1 + $3*12), $5, (int)$7);
	}
	|
	value comma value semicolon
	{
		fprintf(stderr, "aux %d, value %f\n", $1, $3);
		appEvnt(syn_lnum, (int)$1, $3, 0, 1);
	}
	|
	value comma value comma value semicolon
	{
		fprintf(stderr, "aux %d, value %f, step %d\n", $1, $3, $5);
		appEvnt(syn_lnum, (int)$1, $3, 0, (int)$5);
	}
	;

note:
	c_n { $<num>$ = C_N; }
	|
	c_sh_n { $<num>$ = C_SH_N; }
	|
	d_n { $<num>$ = D_N; }
	|
	d_sh_n { $<num>$ = D_SH_N; }
	|
	e_n { $<num>$ = E_N; }
	|
	f_n { $<num>$ = F_N; }
	|
	f_sh_n { $<num>$ = F_SH_N; }
	|
	g_n { $<num>$ = G_N; }
	|
	g_sh_n { $<num>$ = G_SH_N; }
	|
	a_n { $<num>$ = A_N; }
	|
	a_sh_n { $<num>$ = A_SH_N; }
	|
	b_n { $<num>$ = B_N; }
	;

conn_list:
	connections	l_bracket conn_decls r_bracket
	;

conn_decls:
	| conn_decls conn_decl
	;

conn_decl:
	quoted_str comma quoted_str comma input comma value semicolon
	{
		fprintf(stderr, "connection src %s, dest %s, input code %d, amount %f\n", $1, $3, $<num>5, $7);
		appConn(syn_lnum, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, $7);
		free($1);
		free($3);
	}
	|
	quoted_str comma quoted_str comma input comma value comma quoted_str semicolon
	{
		fprintf(stderr, "connection src %s, dest %s, input code %d, amount %f, name %s\n", $1, $3, $<num>5, $7, $9);
		appConn(syn_lnum, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, $7);
		appSldMap(syn_lnum, MOD_SLDR, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, $9);
		free($1);
		free($3);
		free($9);
	}
	|
	quoted_str comma quoted_str comma input semicolon
	{
		fprintf(stderr, "connection src %s, dest %s, input code %d\n", $1, $3, $<num>5);
		appConn(syn_lnum, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, 1);
		free($1);
		free($3);
	}
	|
	quoted_str comma quoted_str comma input comma quoted_str semicolon
	{
		fprintf(stderr, "connection src %s, dest %s, input code %d, name %s\n", $1, $3, $<num>5, $7);
		appConn(syn_lnum, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, 1);
		appSldMap(syn_lnum, MOD_SLDR, modIdx(syn_lnum, $1), modIdx(syn_lnum, $3), $<num>5, $7);
		free($1);
		free($3);
		free($7);
	}
	|
	value comma quoted_str comma input semicolon
	{
		fprintf(stderr, "connection src %d, dest %s, input code %d\n", (int)$1, $3, $<num>5);
		appConn(syn_lnum, -(int)$1, modIdx(syn_lnum, $3), $<num>5, 1);
		free($3);
	}
	|
	value comma quoted_str comma input comma value semicolon
	{
		fprintf(stderr, "connection src %d, dest %s, input code %d, amount %f\n", (int)$1, $3, $<num>5, $7);
		appConn(syn_lnum, -(int)$1, modIdx(syn_lnum, $3), $<num>5, $7);
		free($3);
	}
	;

%%