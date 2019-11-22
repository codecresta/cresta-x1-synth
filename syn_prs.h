/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_SYN_SYN_PRS_H_INCLUDED
# define YY_SYN_SYN_PRS_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int syndebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 10 "syn_prs.y"

	#ifndef YYSCAN_T
		#define YYSCAN_T
		typedef void* yyscan_t;
	#endif


/* Line 2058 of yacc.c  */
#line 54 "syn_prs.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     modules = 258,
     parameters = 259,
     connections = 260,
     sequence = 261,
     mixer = 262,
     saw_tri_osc = 263,
     pulse_osc = 264,
     sine_osc = 265,
     saw_tri_lfo = 266,
     pulse_lfo = 267,
     sine_lfo = 268,
     noise_gen = 269,
     ramp_env = 270,
     multi_env = 271,
     x_fade = 272,
     env_shaper = 273,
     lp_filter = 274,
     hp_filter = 275,
     bp_filter = 276,
     o_drive = 277,
     bit_crush = 278,
     bpm = 279,
     meter = 280,
     range = 281,
     atk = 282,
     dec = 283,
     sus = 284,
     rel = 285,
     signal = 286,
     fine = 287,
     tune = 288,
     shape = 289,
     rate = 290,
     start_level = 291,
     end_level = 292,
     amt_tm = 293,
     level0 = 294,
     level1 = 295,
     level2 = 296,
     level3 = 297,
     level4 = 298,
     level5 = 299,
     level6 = 300,
     amt = 301,
     cut_off = 302,
     resonance = 303,
     gain = 304,
     signal1 = 305,
     signal2 = 306,
     depth = 307,
     c_n = 308,
     c_sh_n = 309,
     d_n = 310,
     d_sh_n = 311,
     e_n = 312,
     f_n = 313,
     f_sh_n = 314,
     g_n = 315,
     g_sh_n = 316,
     a_n = 317,
     a_sh_n = 318,
     b_n = 319,
     value = 320,
     l_bracket = 321,
     r_bracket = 322,
     semicolon = 323,
     equals = 324,
     comma = 325,
     quoted_str = 326
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 26 "syn_prs.y"

	int num;
	double dbl;
	char ch;
	char* str;


/* Line 2058 of yacc.c  */
#line 148 "syn_prs.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int synparse (void *YYPARSE_PARAM);
#else
int synparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int synparse (yyscan_t scanner);
#else
int synparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_SYN_SYN_PRS_H_INCLUDED  */
