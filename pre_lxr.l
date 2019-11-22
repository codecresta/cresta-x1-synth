%{
	#include "pre_prs_ifc.h"
	#include "pre_prs.h"
	#include <stdio.h>
%}

%option outfile="pre_lxr.c" header-file="pre_lxr.h"
%option prefix="pre"
%option warn reentrant noyywrap never-interactive nounistd bison-bridge
%option debug

%%

"banks"|"BANKS" { return banks; }
"presets"|"PRESETS" { return presets; }

"{" { return l_bracket; }
"}" { return r_bracket; }
";" { return semicolon; }

\"([^\\\"\n]|\\.)+\" {
	yylval->str = (char*)malloc(yyleng - 1);
	strncpy(yylval->str, &yytext[1], yyleng - 2);
	yylval->str[yyleng - 2] = '\0';
	return quoted_str;
}

[ \t] { }
[\r\n] { pre_lnum++; }

%%
int preerror(yyscan_t scanner, const char *msg)
{
	_snprintf(pre_err, MAX_PRE_ERR, "Error in %s on line %d.", pre_fname, pre_lnum);
	return 0;
}