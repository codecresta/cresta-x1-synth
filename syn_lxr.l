%x include_state

%{
	#include "syn_prs_ifc.h"
	#include "syn_prs.h"
	#include <stdio.h>

	#define MAX_INCLUDES 32
	char* fname_stk[MAX_INCLUDES];
	int lnum_stk[MAX_INCLUDES];
%}

%option outfile="syn_lxr.c" header-file="syn_lxr.h"
%option prefix="syn"
%option warn reentrant noyywrap never-interactive nounistd bison-bridge
%option debug

%%

"modules"|"MODULES" { return modules; }
"parameters"|"PARAMETERS" { return parameters; }
"connections"|"CONNECTIONS" { return connections; }
"sequence"|"SEQUENCE" { return sequence; }

"mixer"|"MIXER" { return mixer; }
"saw_tri_osc"|"SAW_TRI_OSC" { return saw_tri_osc; }
"pulse_osc"|"PULSE_OSC" { return pulse_osc; }
"sine_osc"|"SINE_OSC" { return sine_osc; }
"saw_tri_lfo"|"SAW_TRI_LFO" { return saw_tri_lfo; }
"pulse_lfo"|"PULSE_LFO" { return pulse_lfo; }
"sine_lfo"|"SINE_LFO" { return sine_lfo; }
"noise_gen"|"NOISE_GEN" { return noise_gen; }
"ramp_env"|"RAMP_ENV" { return ramp_env; }
"multi_env"|"MULTI_ENV" { return multi_env; }
"x_fade"|"X_FADE" { return x_fade; }
"env_shaper"|"ENV_SHAPER" { return env_shaper; }
"lp_filter"|"LP_FILTER" { return lp_filter; }
"hp_filter"|"HP_FILTER" { return hp_filter; }
"bp_filter"|"BP_FILTER" { return bp_filter; }
"o_drive"|"O_DRIVE" { return o_drive; }
"bit_crush"|"BIT_CRUSH" { return bit_crush; }

"atk"|"ATK" { return atk; }
"dec"|"DEC" { return dec; }
"sus"|"SUS" { return sus; }
"rel"|"REL" { return rel; }
"bpm"|"BPM" { return bpm; }
"meter"|"METER" { return meter; }
"range"|"RANGE" { return range; }

"signal"|"SIGNAL" { return signal; }
"fine"|"FINE" { return fine; }
"tune"|"TUNE" { return tune; }
"shape"|"SHAPE" { return shape; }
"rate"|"RATE" { return rate; }
"start_level"|"START_LEVEL" { return start_level; }
"end_level"|"END_LEVEL" { return end_level; }
"amt_tm"|"AMT_TM" { return amt_tm; }
"level0"|"LEVEL0" { return level0; }
"level1"|"LEVEL1" { return level1; }
"level2"|"LEVEL2" { return level2; }
"level3"|"LEVEL3" { return level3; }
"level4"|"LEVEL4" { return level4; }
"level5"|"LEVEL5" { return level5; }
"level6"|"LEVEL6" { return level6; }
"amt"|"AMT" { return amt; }
"cut_off"|"CUT_OFF" { return cut_off; }
"resonance"|"RESONANCE" { return resonance; }
"gain"|"GAIN" { return gain; }
"signal1"|"SIGNAL1" { return signal1; }
"signal2"|"SIGNAL2" { return signal2; }
"depth"|"DEPTH" { return depth; }

"c"|"C" { return c_n; }
"c#"|"C#" { return c_sh_n; }
"d~"|"D~" { return c_sh_n; }
"d"|"D" { return d_n; }
"d#"|"D#" { return d_sh_n; }
"e~"|"E~" { return d_sh_n; }
"e"|"E" { return e_n; }
"f"|"F" { return f_n; }
"f#"|"F#" { return f_sh_n; }
"g~"|"G~" { return f_sh_n; }
"g"|"G" { return g_n; }
"g#"|"G#" { return g_sh_n; }
"a~"|"A~" { return g_sh_n; }
"a"|"A" { return a_n; }
"a#"|"A#" { return a_sh_n; }
"b~"|"B~" { return a_sh_n; }
"b"|"B" { return b_n; }

"{" { return l_bracket; }
"}" { return r_bracket; }
";" { return semicolon; }
"=" { return equals; }
"," { return comma; }

\"([^\\\"\n]|\\.)+\" {
	yylval->str = (char*)malloc(yyleng - 1);
	strncpy(yylval->str, &yytext[1], yyleng - 2);
	yylval->str[yyleng - 2] = '\0';
	return quoted_str;
}
"-"(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+)"."|([0-9]+)) { yylval->dbl = atof(yytext); return value; }
([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+)"."|([0-9]+) { yylval->dbl = atof(yytext); return value; }

[ \t] { }
[\r\n] { syn_lnum++; }

include[ \t]+\" { BEGIN(include_state); }
<include_state>([^\\\"\n]|\\.)+ {
	if (stk_ptr == MAX_INCLUDES) {
		printf("Error maximum includes exceeded.\n");
		return 1;
	}
	yyin = fopen(yytext, "r");
	if (!yyin) {
		printf("Error opening include file: %s\n", yytext);
		return 1;
	}
	fname_stk[stk_ptr] = _strdup(syn_fname);
	lnum_stk[stk_ptr++] = syn_lnum;
	free(syn_fname);
	syn_fname = _strdup(yytext);
	syn_lnum = 1;
	yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE, yyscanner), yyscanner);
	BEGIN(INITIAL);
}
<include_state>\" { BEGIN(INITIAL); }
<<EOF>> {
	yypop_buffer_state(yyscanner);
	free(syn_fname);
	if (stk_ptr > 0)
	{
		syn_fname = _strdup(fname_stk[--stk_ptr]);
		free(fname_stk[stk_ptr]);
		syn_lnum = lnum_stk[stk_ptr];
		BEGIN(include_state);
	}
	if (!YY_CURRENT_BUFFER)
		yyterminate();
}

%%
int synerror(yyscan_t scanner, const char* msg)
{
	_snprintf(syn_err, MAX_SYN_ERR, "Error in %s on line %d.", syn_fname, syn_lnum);
	while (stk_ptr > 0)
		free(fname_stk[--stk_ptr]);
	return 0;
}