/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         synparse
#define yylex           synlex
#define yyerror         synerror
#define yylval          synlval
#define yychar          synchar
#define yydebug         syndebug
#define yynerrs         synnerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "syn_prs.y"

	#include "syn_prs_ifc.h"
	#include "syn_prs.h"
	#include "syn_lxr.h"
	int synerror(yyscan_t scanner, const char* msg);
	int curr_mod;

/* Line 371 of yacc.c  */
#line 83 "syn_prs.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syn_prs.h".  */
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
/* Line 387 of yacc.c  */
#line 10 "syn_prs.y"

	#ifndef YYSCAN_T
		#define YYSCAN_T
		typedef void* yyscan_t;
	#endif


/* Line 387 of yacc.c  */
#line 123 "syn_prs.c"

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
/* Line 387 of yacc.c  */
#line 26 "syn_prs.y"

	int num;
	double dbl;
	char ch;
	char* str;


/* Line 387 of yacc.c  */
#line 217 "syn_prs.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 244 "syn_prs.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      22,    23,    26,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    62,
      64,    69,    70,    73,    78,    80,    82,    84,    86,    88,
      90,    92,    93,    99,   100,   103,   108,   114,   116,   118,
     120,   122,   124,   126,   128,   130,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   154,   156,   158,
     163,   164,   167,   172,   179,   188,   193,   200,   202,   204,
     206,   208,   210,   212,   214,   216,   218,   220,   222,   224,
     229,   230,   233,   242,   253,   260,   269,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      73,     0,    -1,    -1,    73,    74,    -1,    75,    -1,    79,
      -1,    92,    -1,    83,    -1,    88,    -1,     3,    66,    76,
      67,    -1,    -1,    76,    77,    -1,    78,    71,    68,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,     4,    66,    80,    67,    -1,    -1,
      80,    81,    -1,    82,    69,    65,    68,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    -1,    71,    84,    66,    85,    67,    -1,    -1,
      85,    86,    -1,    87,    69,    65,    68,    -1,    87,    69,
      65,    71,    68,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,
      44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    52,    -1,     6,    66,
      89,    67,    -1,    -1,    89,    90,    -1,    91,    70,    65,
      68,    -1,    91,    70,    65,    70,    65,    68,    -1,    91,
      70,    65,    70,    65,    70,    65,    68,    -1,    65,    70,
      65,    68,    -1,    65,    70,    65,    70,    65,    68,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,     5,    66,    93,    67,    -1,    -1,
      93,    94,    -1,    71,    70,    71,    70,    87,    70,    65,
      68,    -1,    71,    70,    71,    70,    87,    70,    65,    70,
      71,    68,    -1,    71,    70,    71,    70,    87,    68,    -1,
      71,    70,    71,    70,    87,    70,    71,    68,    -1,    65,
      70,    71,    70,    87,    68,    -1,    65,    70,    71,    70,
      87,    70,    65,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    56,    58,    60,    62,    64,    68,
      71,    72,    76,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
     121,   124,   125,   129,   137,   139,   141,   143,   145,   147,
     149,   154,   153,   162,   163,   167,   173,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   225,   229,
     232,   233,   237,   243,   249,   255,   261,   269,   271,   273,
     275,   277,   279,   281,   283,   285,   287,   289,   291,   295,
     298,   299,   303,   311,   321,   329,   339,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "modules", "parameters", "connections",
  "sequence", "mixer", "saw_tri_osc", "pulse_osc", "sine_osc",
  "saw_tri_lfo", "pulse_lfo", "sine_lfo", "noise_gen", "ramp_env",
  "multi_env", "x_fade", "env_shaper", "lp_filter", "hp_filter",
  "bp_filter", "o_drive", "bit_crush", "bpm", "meter", "range", "atk",
  "dec", "sus", "rel", "signal", "fine", "tune", "shape", "rate",
  "start_level", "end_level", "amt_tm", "level0", "level1", "level2",
  "level3", "level4", "level5", "level6", "amt", "cut_off", "resonance",
  "gain", "signal1", "signal2", "depth", "c_n", "c_sh_n", "d_n", "d_sh_n",
  "e_n", "f_n", "f_sh_n", "g_n", "g_sh_n", "a_n", "a_sh_n", "b_n", "value",
  "l_bracket", "r_bracket", "semicolon", "equals", "comma", "quoted_str",
  "$accept", "cmds", "cmd", "mod_list", "mod_decls", "mod_decl",
  "mod_type", "prm_list", "prms", "prm", "prm_contr", "mod_hdr", "$@1",
  "settings", "setting", "input", "seq_hdr", "seqs", "seq", "note",
  "conn_list", "conn_decls", "conn_decl", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    74,    74,    74,    75,
      76,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    81,    82,    82,    82,    82,    82,    82,
      82,    84,    83,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      89,    89,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      93,    93,    94,    94,    94,    94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     4,
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     0,     2,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     2,     4,     6,     8,     4,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     2,     8,    10,     6,     8,     6,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,    41,     3,     4,
       5,     7,     8,     6,    10,    31,    90,    70,     0,     0,
       0,     0,     0,    43,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     9,    11,     0,    34,    35,    36,    37,    38,    39,
      40,    30,    32,     0,     0,    89,     0,    91,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,    69,    71,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    42,    44,     0,    12,     0,     0,     0,
       0,     0,     0,    33,     0,     0,    75,     0,    72,     0,
       0,     0,     0,     0,     0,    45,     0,    96,     0,    94,
       0,    76,    73,     0,    46,     0,     0,     0,     0,    97,
      92,     0,    95,    74,     0,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     8,     9,    19,    42,    43,    10,    20,    52,
      53,    11,    18,    74,   104,   105,    12,    22,    72,    73,
      13,    21,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int8 yypact[] =
{
     -70,     0,   -70,   -41,   -33,    28,    49,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    50,     1,
       2,    -9,    42,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -10,    47,   -70,    51,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
      52,   -70,   -70,    53,     3,    56,    55,    54,    57,    61,
      62,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,    60,   -70,    63,    64,    65,
      -7,    -4,    67,   -70,    41,    41,   -70,    68,   -70,    71,
     -11,    -3,    40,    69,    43,   -70,    70,   -70,    74,   -70,
     -64,   -70,   -70,    75,   -70,    73,    44,    76,    77,   -70,
     -70,    59,   -70,   -70,    78,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,     4,   -70,   -70,   -70,   -70,
     -70,   -70,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,   136,    75,     3,     4,     5,     6,   137,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    14,    44,    45,    46,    47,
      48,    49,    50,    15,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    54,   125,    55,    76,
     126,   116,    56,   117,   118,   127,   119,   128,    41,    51,
     103,     7,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    16,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   129,    71,
     130,   132,   140,   133,   141,    17,    23,    77,   121,   122,
     107,    78,    79,    80,   106,   108,   110,   111,   109,   112,
     144,   113,   120,   123,   114,   115,   124,   131,   134,   135,
     138,   139,     0,     0,   142,   143,   145
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       0,    65,    71,     3,     4,     5,     6,    71,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    66,    24,    25,    26,    27,
      28,    29,    30,    66,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    65,    68,    67,    69,
      71,    68,    71,    70,    68,    68,    70,    70,    67,    67,
      67,    71,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    66,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    68,    67,
      70,    68,    68,    70,    70,    66,    66,    70,   114,   115,
      65,    70,    70,    70,    68,    71,    65,    65,    71,    69,
      71,    68,    65,    65,    70,    70,    65,    68,    68,    65,
      65,    68,    -1,    -1,    68,    68,    68
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    73,     0,     3,     4,     5,     6,    71,    74,    75,
      79,    83,    88,    92,    66,    66,    66,    66,    84,    76,
      80,    93,    89,    66,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    67,    77,    78,    24,    25,    26,    27,    28,    29,
      30,    67,    81,    82,    65,    67,    71,    94,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    67,    90,    91,    85,    71,    69,    70,    70,    70,
      70,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    67,    86,    87,    68,    65,    71,    71,
      65,    65,    69,    68,    70,    70,    68,    70,    68,    70,
      65,    87,    87,    65,    65,    68,    71,    68,    70,    68,
      70,    68,    68,    70,    68,    65,    65,    71,    65,    68,
      68,    70,    68,    68,    71,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    yyscan_t scanner;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (scanner);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    yyscan_t scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
#else
static void
yy_reduce_print (yyvsp, yyrule, scanner)
    YYSTYPE *yyvsp;
    int yyrule;
    yyscan_t scanner;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, scanner); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    yyscan_t scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* modules */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1307 "syn_prs.c"
        break;
      case 4: /* parameters */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1314 "syn_prs.c"
        break;
      case 5: /* connections */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1321 "syn_prs.c"
        break;
      case 6: /* sequence */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1328 "syn_prs.c"
        break;
      case 7: /* mixer */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1335 "syn_prs.c"
        break;
      case 8: /* saw_tri_osc */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1342 "syn_prs.c"
        break;
      case 9: /* pulse_osc */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1349 "syn_prs.c"
        break;
      case 10: /* sine_osc */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1356 "syn_prs.c"
        break;
      case 11: /* saw_tri_lfo */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1363 "syn_prs.c"
        break;
      case 12: /* pulse_lfo */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1370 "syn_prs.c"
        break;
      case 13: /* sine_lfo */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1377 "syn_prs.c"
        break;
      case 14: /* noise_gen */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1384 "syn_prs.c"
        break;
      case 15: /* ramp_env */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1391 "syn_prs.c"
        break;
      case 16: /* multi_env */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1398 "syn_prs.c"
        break;
      case 17: /* x_fade */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1405 "syn_prs.c"
        break;
      case 18: /* env_shaper */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1412 "syn_prs.c"
        break;
      case 19: /* lp_filter */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1419 "syn_prs.c"
        break;
      case 20: /* hp_filter */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1426 "syn_prs.c"
        break;
      case 21: /* bp_filter */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1433 "syn_prs.c"
        break;
      case 22: /* o_drive */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1440 "syn_prs.c"
        break;
      case 23: /* bit_crush */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1447 "syn_prs.c"
        break;
      case 24: /* bpm */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1454 "syn_prs.c"
        break;
      case 25: /* meter */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1461 "syn_prs.c"
        break;
      case 26: /* range */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1468 "syn_prs.c"
        break;
      case 27: /* atk */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1475 "syn_prs.c"
        break;
      case 28: /* dec */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1482 "syn_prs.c"
        break;
      case 29: /* sus */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1489 "syn_prs.c"
        break;
      case 30: /* rel */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1496 "syn_prs.c"
        break;
      case 31: /* signal */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1503 "syn_prs.c"
        break;
      case 32: /* fine */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1510 "syn_prs.c"
        break;
      case 33: /* tune */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1517 "syn_prs.c"
        break;
      case 34: /* shape */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1524 "syn_prs.c"
        break;
      case 35: /* rate */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1531 "syn_prs.c"
        break;
      case 36: /* start_level */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1538 "syn_prs.c"
        break;
      case 37: /* end_level */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1545 "syn_prs.c"
        break;
      case 38: /* amt_tm */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1552 "syn_prs.c"
        break;
      case 39: /* level0 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1559 "syn_prs.c"
        break;
      case 40: /* level1 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1566 "syn_prs.c"
        break;
      case 41: /* level2 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1573 "syn_prs.c"
        break;
      case 42: /* level3 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1580 "syn_prs.c"
        break;
      case 43: /* level4 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1587 "syn_prs.c"
        break;
      case 44: /* level5 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1594 "syn_prs.c"
        break;
      case 45: /* level6 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1601 "syn_prs.c"
        break;
      case 46: /* amt */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1608 "syn_prs.c"
        break;
      case 47: /* cut_off */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1615 "syn_prs.c"
        break;
      case 48: /* resonance */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1622 "syn_prs.c"
        break;
      case 49: /* gain */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1629 "syn_prs.c"
        break;
      case 50: /* signal1 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1636 "syn_prs.c"
        break;
      case 51: /* signal2 */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1643 "syn_prs.c"
        break;
      case 52: /* depth */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1650 "syn_prs.c"
        break;
      case 53: /* c_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1657 "syn_prs.c"
        break;
      case 54: /* c_sh_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1664 "syn_prs.c"
        break;
      case 55: /* d_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1671 "syn_prs.c"
        break;
      case 56: /* d_sh_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1678 "syn_prs.c"
        break;
      case 57: /* e_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1685 "syn_prs.c"
        break;
      case 58: /* f_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1692 "syn_prs.c"
        break;
      case 59: /* f_sh_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1699 "syn_prs.c"
        break;
      case 60: /* g_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1706 "syn_prs.c"
        break;
      case 61: /* g_sh_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1713 "syn_prs.c"
        break;
      case 62: /* a_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1720 "syn_prs.c"
        break;
      case 63: /* a_sh_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1727 "syn_prs.c"
        break;
      case 64: /* b_n */
/* Line 1398 of yacc.c  */
#line 33 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1734 "syn_prs.c"
        break;
      case 65: /* value */
/* Line 1398 of yacc.c  */
#line 34 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1741 "syn_prs.c"
        break;
      case 66: /* l_bracket */
/* Line 1398 of yacc.c  */
#line 35 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1748 "syn_prs.c"
        break;
      case 67: /* r_bracket */
/* Line 1398 of yacc.c  */
#line 35 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1755 "syn_prs.c"
        break;
      case 68: /* semicolon */
/* Line 1398 of yacc.c  */
#line 35 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1762 "syn_prs.c"
        break;
      case 69: /* equals */
/* Line 1398 of yacc.c  */
#line 35 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1769 "syn_prs.c"
        break;
      case 70: /* comma */
/* Line 1398 of yacc.c  */
#line 35 "syn_prs.y"
        { };
/* Line 1398 of yacc.c  */
#line 1776 "syn_prs.c"
        break;
      case 71: /* quoted_str */
/* Line 1398 of yacc.c  */
#line 36 "syn_prs.y"
        { free(((*yyvaluep).str)); };
/* Line 1398 of yacc.c  */
#line 1783 "syn_prs.c"
        break;

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (yyscan_t scanner)
#else
int
yyparse (scanner)
    yyscan_t scanner;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:
/* Line 1792 of yacc.c  */
#line 77 "syn_prs.y"
    {
		fprintf(stderr, "append module %s\n", (yyvsp[(2) - (3)].str));
		appMod(syn_lnum, (yyvsp[(1) - (3)].num), (yyvsp[(2) - (3)].str));
		free((yyvsp[(2) - (3)].str));
	}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 85 "syn_prs.y"
    { (yyval.num) = MIXER; }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 87 "syn_prs.y"
    { (yyval.num) = SAW_TRI_OSC; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 89 "syn_prs.y"
    { (yyval.num) = PULSE_OSC; }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 91 "syn_prs.y"
    { (yyval.num) = SINE_OSC; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 93 "syn_prs.y"
    { (yyval.num) = SAW_TRI_LFO; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 95 "syn_prs.y"
    { (yyval.num) = PULSE_LFO; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 97 "syn_prs.y"
    { (yyval.num) = SINE_LFO; }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 99 "syn_prs.y"
    { (yyval.num) = NOISE_GEN; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 101 "syn_prs.y"
    { (yyval.num) = RAMP_ENV; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 103 "syn_prs.y"
    { (yyval.num) = MULTI_ENV; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 105 "syn_prs.y"
    { (yyval.num) = X_FADE; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 107 "syn_prs.y"
    { (yyval.num) = ENV_SHAPER; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 109 "syn_prs.y"
    { (yyval.num) = LP_FILTER; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 111 "syn_prs.y"
    { (yyval.num) = HP_FILTER; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 113 "syn_prs.y"
    { (yyval.num) = BP_FILTER; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 115 "syn_prs.y"
    { (yyval.num) = O_DRIVE; }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 117 "syn_prs.y"
    { (yyval.num) = BIT_CRUSH; }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 130 "syn_prs.y"
    {
		appPrm(syn_lnum, (yyvsp[(1) - (4)].num), (yyvsp[(3) - (4)].dbl));
		fprintf(stderr, "parameter index %d, value %f\n", (yyvsp[(1) - (4)].num), (yyvsp[(3) - (4)].dbl));
	}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 137 "syn_prs.y"
    { (yyval.num) = P_BPM; }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 139 "syn_prs.y"
    { (yyval.num) = P_METER; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 141 "syn_prs.y"
    { (yyval.num) = P_RANGE; }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 143 "syn_prs.y"
    { (yyval.num) = P_ATK; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 145 "syn_prs.y"
    { (yyval.num) = P_DEC; }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 147 "syn_prs.y"
    { (yyval.num) = P_SUS; }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 149 "syn_prs.y"
    { (yyval.num) = P_REL; }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 154 "syn_prs.y"
    {
		fprintf(stderr, "module %s\n", (yyvsp[(1) - (1)].str));
		curr_mod = modIdx(syn_lnum, (yyvsp[(1) - (1)].str));
		free((yyvsp[(1) - (1)].str));
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 168 "syn_prs.y"
    {
		fprintf(stderr, "setting %d, control %d, amount %f\n", curr_mod, (yyvsp[(1) - (4)].num), (yyvsp[(3) - (4)].dbl));
		appContr(syn_lnum, curr_mod, (yyvsp[(1) - (4)].num), (yyvsp[(3) - (4)].dbl));
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 174 "syn_prs.y"
    {
		fprintf(stderr, "setting %d, control %d, amount %f name %s\n", curr_mod, (yyvsp[(1) - (5)].num), (yyvsp[(3) - (5)].dbl), (yyvsp[(4) - (5)].str));
		appContr(syn_lnum, curr_mod, (yyvsp[(1) - (5)].num), (yyvsp[(3) - (5)].dbl));
		appSldMap(syn_lnum, CONTR_SLDR, 0, curr_mod, (yyvsp[(1) - (5)].num), (yyvsp[(4) - (5)].str));
		free((yyvsp[(4) - (5)].str));
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 183 "syn_prs.y"
    { (yyval.num) = IC_SIGNAL; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 185 "syn_prs.y"
    { (yyval.num) = IC_FINE; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 187 "syn_prs.y"
    { (yyval.num) = IC_TUNE; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 189 "syn_prs.y"
    { (yyval.num) = IC_SHAPE; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 191 "syn_prs.y"
    { (yyval.num) = IC_RATE; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 193 "syn_prs.y"
    { (yyval.num) = IC_START_LEVEL; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 195 "syn_prs.y"
    { (yyval.num) = IC_END_LEVEL; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 197 "syn_prs.y"
    { (yyval.num) = IC_AMT_TM; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 199 "syn_prs.y"
    { (yyval.num) = IC_LEVEL0; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 201 "syn_prs.y"
    { (yyval.num) = IC_LEVEL1; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 203 "syn_prs.y"
    { (yyval.num) = IC_LEVEL2; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 205 "syn_prs.y"
    { (yyval.num) = IC_LEVEL3; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 207 "syn_prs.y"
    { (yyval.num) = IC_LEVEL4; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 209 "syn_prs.y"
    { (yyval.num) = IC_LEVEL5; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 211 "syn_prs.y"
    { (yyval.num) = IC_LEVEL6; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 213 "syn_prs.y"
    { (yyval.num) = IC_AMT; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 215 "syn_prs.y"
    { (yyval.num) = IC_CUT_OFF; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 217 "syn_prs.y"
    { (yyval.num) = IC_RESONANCE; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 219 "syn_prs.y"
    { (yyval.num) = IC_GAIN; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 221 "syn_prs.y"
    { (yyval.num) = IC_SIGNAL1; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 223 "syn_prs.y"
    { (yyval.num) = IC_SIGNAL2; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 225 "syn_prs.y"
    { (yyval.num) = IC_DEPTH; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 238 "syn_prs.y"
    {
		fprintf(stderr, "note %d, octave %d\n", (yyvsp[(1) - (4)].num), (int)(yyvsp[(3) - (4)].dbl));
		appEvnt(syn_lnum, NOTE_EVENT, (int)((yyvsp[(1) - (4)].num) + (yyvsp[(3) - (4)].dbl)*12), 1, 1);
	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 244 "syn_prs.y"
    {
		fprintf(stderr, "note %d, octave %d, duration %f\n", (yyvsp[(1) - (6)].num), (int)(yyvsp[(3) - (6)].dbl), (yyvsp[(5) - (6)].dbl));
		appEvnt(syn_lnum, NOTE_EVENT, (int)((yyvsp[(1) - (6)].num) + (yyvsp[(3) - (6)].dbl)*12), (yyvsp[(5) - (6)].dbl), (int)(yyvsp[(5) - (6)].dbl));
	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 250 "syn_prs.y"
    {
		fprintf(stderr, "note %d, octave %d, duration %f, step %d\n", (yyvsp[(1) - (8)].num), (int)(yyvsp[(3) - (8)].dbl), (yyvsp[(5) - (8)].dbl), (int)(yyvsp[(7) - (8)].dbl));
		appEvnt(syn_lnum, NOTE_EVENT, (int)((yyvsp[(1) - (8)].num) + (yyvsp[(3) - (8)].dbl)*12), (yyvsp[(5) - (8)].dbl), (int)(yyvsp[(7) - (8)].dbl));
	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 256 "syn_prs.y"
    {
		fprintf(stderr, "aux %d, value %f\n", (yyvsp[(1) - (4)].dbl), (yyvsp[(3) - (4)].dbl));
		appEvnt(syn_lnum, (int)(yyvsp[(1) - (4)].dbl), (yyvsp[(3) - (4)].dbl), 0, 1);
	}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 262 "syn_prs.y"
    {
		fprintf(stderr, "aux %d, value %f, step %d\n", (yyvsp[(1) - (6)].dbl), (yyvsp[(3) - (6)].dbl), (yyvsp[(5) - (6)].dbl));
		appEvnt(syn_lnum, (int)(yyvsp[(1) - (6)].dbl), (yyvsp[(3) - (6)].dbl), 0, (int)(yyvsp[(5) - (6)].dbl));
	}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 269 "syn_prs.y"
    { (yyval.num) = C_N; }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 271 "syn_prs.y"
    { (yyval.num) = C_SH_N; }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 273 "syn_prs.y"
    { (yyval.num) = D_N; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 275 "syn_prs.y"
    { (yyval.num) = D_SH_N; }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 277 "syn_prs.y"
    { (yyval.num) = E_N; }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 279 "syn_prs.y"
    { (yyval.num) = F_N; }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 281 "syn_prs.y"
    { (yyval.num) = F_SH_N; }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 283 "syn_prs.y"
    { (yyval.num) = G_N; }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 285 "syn_prs.y"
    { (yyval.num) = G_SH_N; }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 287 "syn_prs.y"
    { (yyval.num) = A_N; }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 289 "syn_prs.y"
    { (yyval.num) = A_SH_N; }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 291 "syn_prs.y"
    { (yyval.num) = B_N; }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 304 "syn_prs.y"
    {
		fprintf(stderr, "connection src %s, dest %s, input code %d, amount %f\n", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].dbl));
		appConn(syn_lnum, modIdx(syn_lnum, (yyvsp[(1) - (8)].str)), modIdx(syn_lnum, (yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].dbl));
		free((yyvsp[(1) - (8)].str));
		free((yyvsp[(3) - (8)].str));
	}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 312 "syn_prs.y"
    {
		fprintf(stderr, "connection src %s, dest %s, input code %d, amount %f, name %s\n", (yyvsp[(1) - (10)].str), (yyvsp[(3) - (10)].str), (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].dbl), (yyvsp[(9) - (10)].str));
		appConn(syn_lnum, modIdx(syn_lnum, (yyvsp[(1) - (10)].str)), modIdx(syn_lnum, (yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].num), (yyvsp[(7) - (10)].dbl));
		appSldMap(syn_lnum, MOD_SLDR, modIdx(syn_lnum, (yyvsp[(1) - (10)].str)), modIdx(syn_lnum, (yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].num), (yyvsp[(9) - (10)].str));
		free((yyvsp[(1) - (10)].str));
		free((yyvsp[(3) - (10)].str));
		free((yyvsp[(9) - (10)].str));
	}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 322 "syn_prs.y"
    {
		fprintf(stderr, "connection src %s, dest %s, input code %d\n", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num));
		appConn(syn_lnum, modIdx(syn_lnum, (yyvsp[(1) - (6)].str)), modIdx(syn_lnum, (yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].num), 1);
		free((yyvsp[(1) - (6)].str));
		free((yyvsp[(3) - (6)].str));
	}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 330 "syn_prs.y"
    {
		fprintf(stderr, "connection src %s, dest %s, input code %d, name %s\n", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].str));
		appConn(syn_lnum, modIdx(syn_lnum, (yyvsp[(1) - (8)].str)), modIdx(syn_lnum, (yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].num), 1);
		appSldMap(syn_lnum, MOD_SLDR, modIdx(syn_lnum, (yyvsp[(1) - (8)].str)), modIdx(syn_lnum, (yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].str));
		free((yyvsp[(1) - (8)].str));
		free((yyvsp[(3) - (8)].str));
		free((yyvsp[(7) - (8)].str));
	}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 340 "syn_prs.y"
    {
		fprintf(stderr, "connection src %d, dest %s, input code %d\n", (int)(yyvsp[(1) - (6)].dbl), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].num));
		appConn(syn_lnum, -(int)(yyvsp[(1) - (6)].dbl), modIdx(syn_lnum, (yyvsp[(3) - (6)].str)), (yyvsp[(5) - (6)].num), 1);
		free((yyvsp[(3) - (6)].str));
	}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 347 "syn_prs.y"
    {
		fprintf(stderr, "connection src %d, dest %s, input code %d, amount %f\n", (int)(yyvsp[(1) - (8)].dbl), (yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].dbl));
		appConn(syn_lnum, -(int)(yyvsp[(1) - (8)].dbl), modIdx(syn_lnum, (yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].num), (yyvsp[(7) - (8)].dbl));
		free((yyvsp[(3) - (8)].str));
	}
    break;


/* Line 1792 of yacc.c  */
#line 2596 "syn_prs.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, scanner);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 354 "syn_prs.y"
