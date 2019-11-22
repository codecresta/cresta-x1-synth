%{
	#include "pre_prs_ifc.h"
	#include "pre_prs.h"
	#include "pre_lxr.h"
	int preerror(yyscan_t scanner, const char *msg);
%}

%code requires
{
	#ifndef YYSCAN_T
		#define YYSCAN_T
		typedef void* yyscan_t;
	#endif
}

%output  "pre_prs.c"
%defines "pre_prs.h"
%name-prefix "pre"
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%error-verbose

%union
{
	char ch;
	char* str;
}

%destructor { free($$); } <str>

%token<ch> l_bracket r_bracket semicolon
%token<str> quoted_str
%token<num> banks presets

%%
cmds:
	| cmds cmd
	;

cmd:
	bank_list
	|
	pre_list
	;

bank_list:
	banks l_bracket bank_decls r_bracket
	;

bank_decls:
	| bank_decls bank_decl
	;

bank_decl:
	quoted_str semicolon
	{
		fprintf(stderr, "append bank %s\n", $1);
		appBank(pre_lnum, $1);
		free($1);
	}
	;

pre_list:
	presets l_bracket pre_decls r_bracket
	;

pre_decls:
	| pre_decls pre_decl
	;

pre_decl:
	quoted_str quoted_str semicolon
	{
		fprintf(stderr, "append preset, bank %s, name %s\n", $1, $2);
		appPre(pre_lnum, $1, $2);
		free($1);
		free($2);
	}
	;

%%