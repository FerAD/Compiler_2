/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PARENI = 258,
     PAREND = 259,
     SUMA = 260,
     RESTA = 261,
     MULTI = 262,
     DIVIDE = 263,
     MAYORQ = 264,
     MENORQ = 265,
     IGUAL = 266,
     PTOYCOMA = 267,
     THEN = 268,
     DO = 269,
     BEG = 270,
     END = 271,
     UNTIL = 272,
     NUMENT = 273,
     NUMF = 274,
     INT = 275,
     FLOAT = 276,
     ASIGNACION = 277,
     IF = 278,
     WHILE = 279,
     REPEAT = 280,
     PRINT = 281,
     READ = 282,
     ID = 283
   };
#endif
/* Tokens.  */
#define PARENI 258
#define PAREND 259
#define SUMA 260
#define RESTA 261
#define MULTI 262
#define DIVIDE 263
#define MAYORQ 264
#define MENORQ 265
#define IGUAL 266
#define PTOYCOMA 267
#define THEN 268
#define DO 269
#define BEG 270
#define END 271
#define UNTIL 272
#define NUMENT 273
#define NUMF 274
#define INT 275
#define FLOAT 276
#define ASIGNACION 277
#define IF 278
#define WHILE 279
#define REPEAT 280
#define PRINT 281
#define READ 282
#define ID 283




/* Copy the first part of user declarations.  */
#line 1 "t4.y"

#include <stdio.h>
#include <string.h>
#include "tablaSimbolos.h"
#include "arbol.h"
//void recorreArbol();


/*se declara yytext como variable externa de este archivo*/
extern char * yytext;

/*extern int entero;
extern double doble;
extern char *str;	*/

/*inicializo la lista que utilizaremos para crear la tabla de simbolos*/
Lista *lista;

/*Datos en los que voy a guardar los valores*/
char *tipoID;	//guardo el tipo de la variable
char *nombreID;	//guardo el nomre de la variable
int datoEntero;	//guardo el valor entero
float datoFlotante;	//guardo el valor flotante
char *validaTipo;
float valorParaAsignar;	//guardo el valor de las sumas, restas, mult etc que se asignara a alguna variable



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "t4.y"
{
	int entero;
	float flotante;
	char *str;
   	struct Arbol *abb;
}
/* Line 193 of yacc.c.  */
#line 187 "t4.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 200 "t4.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   63

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNRULES -- Number of states.  */
#define YYNSTATES  64

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    10,    11,    15,    17,    20,    22,
      24,    28,    33,    38,    43,    47,    50,    53,    55,    56,
      60,    62,    66,    70,    74,    78,    82,    84,    88,    92,
      94,    98,   100,   102
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    31,    15,    36,    16,    -1,    32,    -1,
      -1,    32,    12,    33,    -1,    33,    -1,    34,    28,    -1,
      20,    -1,    21,    -1,    41,    22,    39,    -1,    23,    38,
      13,    35,    -1,    24,    38,    14,    35,    -1,    25,    35,
      17,    38,    -1,    15,    36,    16,    -1,    26,    39,    -1,
      27,    39,    -1,    37,    -1,    -1,    37,    12,    35,    -1,
      35,    -1,    39,    10,    39,    -1,    39,     9,    39,    -1,
      39,    11,    39,    -1,    39,     5,    40,    -1,    39,     6,
      40,    -1,    40,    -1,    40,     7,    41,    -1,    40,     8,
      41,    -1,    41,    -1,     3,    39,     4,    -1,    28,    -1,
      18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    79,    80,    83,    84,    87,    92,    93,
      96,   125,   133,   140,   147,   150,   157,   166,   169,   172,
     181,   186,   200,   214,   232,   266,   300,   303,   336,   369,
     374,   375,   391,   401
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PARENI", "PAREND", "SUMA", "RESTA",
  "MULTI", "DIVIDE", "MAYORQ", "MENORQ", "IGUAL", "PTOYCOMA", "THEN", "DO",
  "BEG", "END", "UNTIL", "NUMENT", "NUMF", "INT", "FLOAT", "ASIGNACION",
  "IF", "WHILE", "REPEAT", "PRINT", "READ", "ID", "$accept", "prg",
  "opt_decls", "decls", "dec", "tipo", "stmt", "opt_stmts", "stmt_lst",
  "expresion", "expr", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    33,    34,    34,
      35,    35,    35,    35,    35,    35,    35,    36,    36,    37,
      37,    38,    38,    38,    39,    39,    39,    40,    40,    40,
      41,    41,    41,    41
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     3,     1,     2,     1,     1,
       3,     4,     4,     4,     3,     2,     2,     1,     0,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     8,     9,     0,     0,     3,     6,     0,     1,    18,
       0,     7,     0,    18,    32,    33,     0,     0,     0,     0,
       0,    31,    20,     0,    17,     0,     5,     0,    26,    29,
       0,     0,     0,     0,     0,    15,    16,     2,     0,     0,
      30,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,    19,    10,    24,    25,    27,    28,    11,    22,
      21,    23,    12,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    22,    23,    24,    31,
      32,    28,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -19
static const yytype_int8 yypact[] =
{
      10,   -19,   -19,     3,    -7,     8,   -19,   -18,   -19,    -2,
      10,   -19,    24,    -2,   -19,   -19,    24,    24,    -2,    24,
      24,   -19,   -19,    12,    21,    23,   -19,     1,     7,   -19,
      35,    26,    44,    46,    45,    51,    51,   -19,    -2,    24,
     -19,    24,    24,    24,    24,   -19,    -2,    24,    24,    24,
      -2,    24,   -19,    51,     7,     7,   -19,   -19,   -19,    51,
      51,    51,   -19,   -19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,   -19,   -19,    53,   -19,    -6,    48,   -19,   -15,
      -1,    17,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      25,    12,    33,     8,    25,    40,    41,    42,     9,    25,
      11,    27,    34,    13,    43,    44,    14,    15,    35,    36,
      10,    16,    17,    18,    19,    20,    21,    12,    37,    25,
       1,     2,    52,    38,    56,    57,    63,    25,    53,    46,
      58,    25,    14,    15,    62,    39,    59,    60,    61,    41,
      42,    45,    21,    47,    48,    49,    41,    42,    54,    55,
      50,    30,    51,    26
};

static const yytype_uint8 yycheck[] =
{
       9,     3,    17,     0,    13,     4,     5,     6,    15,    18,
      28,    12,    18,    15,     7,     8,    18,    19,    19,    20,
      12,    23,    24,    25,    26,    27,    28,     3,    16,    38,
      20,    21,    38,    12,    43,    44,    51,    46,    39,    13,
      46,    50,    18,    19,    50,    22,    47,    48,    49,     5,
       6,    16,    28,     9,    10,    11,     5,     6,    41,    42,
      14,    13,    17,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    30,    31,    32,    33,    34,     0,    15,
      12,    28,     3,    15,    18,    19,    23,    24,    25,    26,
      27,    28,    35,    36,    37,    41,    33,    39,    40,    41,
      36,    38,    39,    38,    35,    39,    39,    16,    12,    22,
       4,     5,     6,     7,     8,    16,    13,     9,    10,    11,
      14,    17,    35,    39,    40,    40,    41,    41,    35,    39,
      39,    39,    35,    38
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 2:
#line 65 "t4.y"
    {
			//interpreta el programa
			printf("\nSALIDA DEL PROGRAMA\n");
			interpreta((yyvsp[(3) - (4)].abb));
			//muestra la lista
			mostrarLista(lista);
			//recorre el arbol
			//printf("...::::ARBOL EN POSTORDEN::::...\n");
			//postorden($3);
			//al terminar imprime la tabla de simbolos y recorre el arbol mostrando los elementos
			printf("\nTERMINO\n");
		;}
    break;

  case 4:
#line 80 "t4.y"
    {;}
    break;

  case 7:
#line 87 "t4.y"
    {
copiaYYtext("ID",yytext);
agregarElemento(lista,nombreID,tipoID,0.0);;}
    break;

  case 8:
#line 92 "t4.y"
    {copiaYYtext("TIPO",yytext);/*tipoID = yytext; printf("tipo:%s",yytext);*/;}
    break;

  case 9:
#line 93 "t4.y"
    {copiaYYtext("TIPO",yytext);/*tipoID = yytext; printf("tipo:%s",yytext);*/;}
    break;

  case 10:
#line 96 "t4.y"
    {
			//controlador para ver si esta ID en la tabla de simbolos
			int control;
			//creo un nuevo arbol y guardo en el el valor de factor sino hago esto me marca error en $1
		   	Arbol aux2;
		   	aux2 = malloc(sizeof(NodoAbb));
		   	aux2 = (yyvsp[(1) - (3)].abb);
		   	//asgino a el arbol el valor de expr
		   	aux2->valor = valorParaAsignar;
		   	//guardo la variable de factor en nombreID
		   	copiaYYtext("ID",aux2->nombre);
		   	//asigno el valor ya sea 0 o 1, 0 si si esta y 1 si no esta 
		   	control = buscar(lista,nombreID); 
		   	//asigno el valor de expr a la lista ligada de la tabla de simbolos
		   	//buscarYasignar(lista,nombreID,aux2);
		   	if(control == 0){
		   		//creo un nuevo nodo y se lo asigno a factor
		   		//nuevo_nodo(1); ---1 es operando
		   		(yyval.abb) = nuevo_nodo(2,":=");
		   		//inserto
		   		inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
		   	}
	   		else{
	   			printf("*****ERROR %s no esta declarada\n",yytext);
	   			break;
	   		}


		;}
    break;

  case 11:
#line 125 "t4.y"
    {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"if");
     		inserta((yyvsp[(2) - (4)].abb),aux,(yyvsp[(4) - (4)].abb));
     		(yyval.abb) = aux;
     		
     	;}
    break;

  case 12:
#line 133 "t4.y"
    {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"while");
     		inserta((yyvsp[(2) - (4)].abb),aux,(yyvsp[(4) - (4)].abb));
     		(yyval.abb) = aux;
     	;}
    break;

  case 13:
#line 140 "t4.y"
    {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"repeat");
     		inserta((yyvsp[(2) - (4)].abb),aux,(yyvsp[(4) - (4)].abb));
     		(yyval.abb) = aux;
     	;}
    break;

  case 14:
#line 147 "t4.y"
    {
     		(yyval.abb) = (yyvsp[(2) - (3)].abb);
     	;}
    break;

  case 15:
#line 150 "t4.y"
    {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"print");
     		inserta((yyvsp[(2) - (2)].abb),aux,NULL);
     		(yyval.abb) = aux;
     	;}
    break;

  case 16:
#line 157 "t4.y"
    {
     		Arbol aux;
     		aux = malloc(sizeof(NodoAbb));
     		aux = nuevo_nodo(3,"read");
     		inserta((yyvsp[(2) - (2)].abb),aux,NULL);
     		(yyval.abb) = aux;
     	;}
    break;

  case 17:
#line 166 "t4.y"
    {
				(yyval.abb) = (yyvsp[(1) - (1)].abb)
			;}
    break;

  case 18:
#line 169 "t4.y"
    {;}
    break;

  case 19:
#line 172 "t4.y"
    {
				//creo un nuevo nodo con valor de nombre ;
				Arbol aux;
				aux = malloc(sizeof(NodoAbb));
				aux = nuevo_nodo(2,";");
				(yyval.abb) = aux;
				inserta((yyvsp[(1) - (3)].abb),aux,(yyvsp[(3) - (3)].abb));
	 			
		 	;}
    break;

  case 20:
#line 181 "t4.y"
    {
		 		(yyval.abb) = (yyvsp[(1) - (1)].abb);
		 	;}
    break;

  case 21:
#line 186 "t4.y"
    {
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			(yyval.abb) = nuevo_nodo(2,"<");
		 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			;}
    break;

  case 22:
#line 200 "t4.y"
    {
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			(yyval.abb) = nuevo_nodo(2,">");
		 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			;}
    break;

  case 23:
#line 214 "t4.y"
    {
				//variable de control para ver si los tipos son iguales o no
		 		int control;
		 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
		 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
		 		if(control == 0){
		 			//se crea un nuevo nodo Operador
		 			(yyval.abb) = nuevo_nodo(2,"=");
		 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
		 			
		 		}else{
		 			printf("*****Error, Conflicto de tipos\n");
		 		}
			;}
    break;

  case 24:
#line 232 "t4.y"
    {
			//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			(yyval.abb) = nuevo_nodo(2,"+");
	 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
     				valorParaAsignar = aux1->valor + aux2->valor;
	 			}
	 			if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
     				valorParaAsignar = aux1->valor + aux2->valor;
	 			}

	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 		
		;}
    break;

  case 25:
#line 266 "t4.y"
    {
	 		//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			(yyval.abb) = nuevo_nodo(2,"-");
	 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));

	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor - aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor - aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 	;}
    break;

  case 26:
#line 300 "t4.y"
    {(yyval.abb) = (yyvsp[(1) - (1)].abb);;}
    break;

  case 27:
#line 303 "t4.y"
    {
			//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			(yyval.abb) = nuevo_nodo(2,"*");
	 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor * aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor * aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
		;}
    break;

  case 28:
#line 336 "t4.y"
    {
	 		//variable de control para ver si los tipos son iguales o no
	 		int control;
	 		//asigno el valor, ya sea 0 si son iguales o 1 si son diferentes
	 		control = validaTipos((yyvsp[(1) - (3)].abb),(yyvsp[(3) - (3)].abb));
	 		if(control == 0){
	 			//se crea un nuevo nodo Operador
	 			(yyval.abb) = nuevo_nodo(2,"/");
	 			inserta((yyvsp[(1) - (3)].abb),(yyval.abb),(yyvsp[(3) - (3)].abb));
	 			//checo si es entero o flotante para hacer la suma y guardar el valor
	 			if(validaTipo == "int"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor / aux2->valor;
	 			}else if(validaTipo == "float"){
	 				Arbol aux1;
	 				Arbol aux2;
     				aux1 = malloc(sizeof(NodoAbb));
     				aux2 = malloc(sizeof(NodoAbb));
     				aux1 = (yyvsp[(1) - (3)].abb);
     				aux2 = (yyvsp[(3) - (3)].abb);
	 				valorParaAsignar = aux1->valor / aux2->valor;
	 			}

	 			
	 		}else{
	 			printf("*****Error, Conflicto de tipos\n");
	 		}
	 	;}
    break;

  case 29:
#line 369 "t4.y"
    {
	 				(yyval.abb) = (yyvsp[(1) - (1)].abb);
	 			;}
    break;

  case 30:
#line 374 "t4.y"
    {(yyval.abb) = (yyvsp[(2) - (3)].abb);}
    break;

  case 31:
#line 375 "t4.y"
    {
	   		//variable d econtrol para ver si esta o no la variable dentro de la tabla de simbolos
		   	int control;
		   	//asigno el valor ya sea 0 o 1, 0 si si esta y 1 si no esta 
		   	control = buscar(lista,yytext); 
		   	if(control == 0){
		   		//creo un nuevo nodo y se lo asigno a factor
		   		//nuevo_nodo(1); ---1 es operando
		   		(yyval.abb) = nuevo_nodo(1,nombreID);
		   		inserta(NULL,(yyval.abb),NULL);
		   	}
	   		else{
	   			printf("*****ERROR %s no esta declarada\n",yytext);
	   			break;
	   		}
   		;}
    break;

  case 32:
#line 391 "t4.y"
    {

	   		//guardo el valor de yytext en una variable global entera 
	   		copiaYYtext("NUMENT",yytext);
	   		//creo un nodo 
	   		//nuevo_nodo(1); ---1 es operando
	   		(yyval.abb) = nuevo_nodo(1,nombreID);
	   		inserta(NULL,(yyval.abb),NULL);
	   		
		;}
    break;

  case 33:
#line 401 "t4.y"
    {
	   		//guardo el valor de yytext en una variable golbal flotante 
	   		copiaYYtext("NUMF",yytext);
	   		//creo el nodo
	   		//nuevo_nodo(1); ---1 es operando
	   		(yyval.abb) = nuevo_nodo(1,nombreID);
	   		inserta(NULL,(yyval.abb),NULL);
	   		
		;}
    break;


/* Line 1267 of yacc.c.  */
#line 1876 "t4.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 412 "t4.y"


int yyerror(char const * s) {
  fprintf(stderr, "%s\n", s);
}

/*********METODOS DE LA LISTA**********/

//***Metodo para inicializar la lista de la tabla de simbolos***
void inicializar(Lista *lista){
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tamanio = 0;
}

//***Metodo para agregar un elemento a la lista de la tabla de simbolos****
int agregarElemento(Lista *lista, char *nomb,char *tip, double val){
	//Creo un nuevo elemento
	Elemento *e;
	//Asigno espacio a dicho elemento nuevo
	if((e = (Elemento *) malloc(sizeof(Elemento))) == NULL){
		printf("Error asignar espacio a un nuevo elemento de la tabla de simbolos\n");
		//error al asignar memoria regresa 1
		return 1;	
	}else{
		//asigno a ese nuevo elemento, el nombre, el tipo y el valor
		e->nombre = nomb;
		e->tipo = tip;
		e->valor = val;
		//si es el primer elemento de la lista entre en el if
		if(lista->inicio == NULL){
			e->siguiente = NULL;
			lista->inicio = e;
			lista->fin = e;
			lista->tamanio++;
			return 0;
		}
		//si no es el primer elemento de la lista entrea en el else
		else{	
			e->siguiente = lista->inicio;
			lista->inicio = e;
			lista->tamanio++;
			return 0;

		}
		
	}
}
/****Metodo que muestra la lista de la tabla de simbolos***/
void mostrarLista(Lista *lista){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//encabezado de la tabla de simbolos
	printf("******TABLA DE SIMBOLOS******\nTIPO\tNOMBRE\tVALOR\n");
	//mientras haya valores imprime el tipo,nombre y valor de cada elemento y avanza
	while(aux != NULL){
		printf("%s\t%s\t%.f\n",aux->tipo,aux->nombre,aux->valor);
		aux = aux->siguiente;
	}
}

/****Metodo que copia el valor de yytext en cualquiera de las variables globales
 dependiendo que es ya que si lo hago sin este metodo copia todo el codigo***/
void copiaYYtext(char * x,char * valorActual){
	int tamanio;	//variable en la que guardo el tamaño de el valor acutal de yytext
	tamanio = strlen(valorActual);	
	if(x == "ID"){	//si es un ID reservo memoria y copio yytext(valor actual) a nombreID
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);	
	}else if(x == "TIPO"){	//si es un tipo reservo memoria y copio yytext(valor actual) a tipoID
		tipoID = (char *) malloc(sizeof(tamanio));
		strcpy(tipoID,valorActual);
	}else if(x == "NUMENT"){	//si es un entero convierto el valorActual a entero y lo guardo en datoEntero y tambien en nombreID y en tipoID
		datoEntero = atoi(valorActual);
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);
		tipoID = "int";

	}else if(x == "NUMF"){	//si es un flotante convierto el valorActual a float y lo guardo en datoFlotante, tambien guardo su nombre y su tipo como string
		datoFlotante = atof(valorActual);
		nombreID = (char *) malloc(sizeof(tamanio));
		strcpy(nombreID,valorActual);
		tipoID = "float";
	}
	
}
/***Metodo que busca la variable dentro de la tabla de simbolos***/
int buscar(Lista * lista, char * variable){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(variable,aux->nombre)==0){
			//guardo el nombre del dato buscado en la variable global nombreID
			nombreID = aux->nombre;	
			//guardo el tipo del dato buscado en la variable global tipoID
			tipoID = aux->tipo;
			return 0;
		}else{
			aux = aux->siguiente;	
		}
		
	}

	return 1;	//si no encuentra un valor con el mismo nombre regresa 1
}

int buscarYasignar(Lista * lista, char * variable, Arbol a){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(variable,aux->nombre)==0){
			//guardo el valor del arbol en el valor de la variable
			aux->valor = a->valor;
			lista = aux;	
			return 0;
		}else{
			aux = aux->siguiente;	
		}
		
	}

	return 1;	//si no encuentra un valor con el mismo nombre regresa 1
}

/***********METODOS DEL ARBOL***********/

/***Metodo que agrega un nuevo nodo dependiendo si es operador, operando o sentencia***/
Arbol nuevo_nodo(int tipoN,char *n){

	Arbol nodo;
	nodo = malloc(sizeof(NodoAbb));
	
	switch(tipoN){
		//caso de que sean operando no uso la variable n porque ya esta el nombre y el tipo guardadas en nombreID y en tipoID
		case 1:
			nodo->nombre = nombreID;
			nodo->tipoNodo = "Operando";
			nodo->tipoDato = tipoID;
			if(nodo->tipoDato == "int"){
				nodo->valor = datoEntero;
			}else if(nodo->tipoDato == "float"){
				nodo->valor = datoFlotante;
			}
			nodo->izq = NULL;
			nodo->der = NULL;
			return nodo;
			break;
		//caso de que sean operadores si uso la variable n
		case 2:
			nodo->nombre = n;
			nodo->tipoNodo = "Operador";
			nodo->tipoDato = tipoID;
			nodo->izq = NULL;
			nodo->der = NULL;
			break;
		case 3:
			nodo->nombre = n;
			nodo->tipoNodo = "Sentencia";
			nodo->tipoDato = tipoID;
			nodo->izq = NULL;
			nodo->der = NULL;
			break;
	}
	
}
/***Metodo que inserta un arbol con sus respectivas ramas arboles***/
void inserta(Arbol i, Arbol c, Arbol d){
	//ligo los arboles
	c->izq = i;
	c->der = d;
}
/***Metodo que recorre el arbol en postorden***/
void postorden(Arbol a){

	if(a != NULL){
		postorden(a->izq);
		postorden(a->der);
		printf("%s => ",a->nombre);
	}
	
}
/***Metodo que valida los tipos de datos de dos arboles diferentes***/
int validaTipos(Arbol a, Arbol b){
	if(strcmp(a->tipoDato,b->tipoDato) == 0){
		validaTipo = a->tipoDato;
		return 0;
	}
		
			
	return 1;
}
/***Metodo que interpreta el programa***/
void interpreta(Arbol a){
	if(a!=NULL){
		//si lo que lee es un ; recorre el arbol en postorden 
		if(strcmp (a->nombre,";") == 0){
			interpreta(a->izq);
			interpreta(a->der);
		//si lo que lee es un := entonces se manda la funcion asigna para asignar valores
		}else if(strcmp(a->nombre,":=") == 0){
			asigna(a);
		//si lo que se lele es un if entonces manda a llamar a la funcion miif que regresa 0 si es correcto y 1 si es incorrecto
		}else if(strcmp( a->nombre,"if") == 0){
			int res;
			res = miif(a);
			
		}else if(strcmp(a->nombre,"while") == 0){
			int res;
			res = miwhile(a);
			
		}else if(strcmp(a->nombre, "repeat" )==0){
			int res;
			res = mirepeat(a);
			
		}else if(strcmp(a->nombre, "print" )==0){
			int res;
			res = miprint(a);

		}else if(strcmp(a->nombre, "read" )==0){
			int res;
			res = miread(a);
		}
				
		
	}
}

/*Metodo que recupera el valor de un elemento de la lista o tabla de simbolos*/
float recuperaValorDeLista(Lista * lista, char * nombre){
	//creo un elemento auxiliar para recorrer la lista
	Elemento *aux;
	//lo igualo a el nodo de inicio
	aux = lista->inicio;
	//Mientras aux recorre revisa si hay o no un ID con ese nombre
	while(aux != NULL){
		//si hay un valor con ese nombre en la tabla de simbolos regresa 0
		if(strcmp(nombre,aux->nombre)==0){
			return aux->valor;
		}else{
			aux = aux->siguiente;	
		}
		
		
	}

	return 1.0;	//si no encuentra un valor con el mismo nombre regresa 1
}
/*Metodo que guarda un valor leeido de teclado en una variable*/
int miread(Arbol a){
	//variable auxiliar para saber que variable resivira el valor
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//variable auxiliar para guardar el valor leeido
	float val;

	aux = a->izq;
	printf("Read %s...\n",aux->nombre);
	x("%d",&val);
	aux->valor = val;
	buscarYasignar(lista,aux->nombre,aux);
	
	return 0;
}

/*Metodo que imprime*/
int miprint(Arbol a){
	//variable donde se almacenara el valor
	float x;
	//variable arbol auxiliar
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//igualo aux al valor que se imprimira
	aux = a->izq;
	//se recupera el valor del resultado
	x = recuperaValorDeLista(lista,aux->nombre);
	//imprimo
	printf("%.2f\n",x);
}

/*Metodo que simula un if*/
int miif(Arbol a){
	int res;	
	//alido la expresion del lado izquierdo del if
	res = validaExpresion(a->izq);
	//si es correcto entonces interpreto el lado derecho 
	if(res == 0){
		interpreta(a->der);
		return 0;
	//si no es correcto entonces me salgo de la funcion
	}else{
		return 1;
	}
}
/*Ciclo que hace el repeat*/
int mirepeat(Arbol a){
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));

	aux = a->izq;
	int res;
	res = validaExpresion(a->der);
	while (res == 1){
		interpreta(aux);
		res = validaExpresion(a->der);
	}
}
/*Ciclo que hace el while*/
int miwhile(Arbol a){
	//creo un arbol auxiliar
	Arbol aux;
	aux = malloc(sizeof(NodoAbb));
	//lo igualo a la expr del while
	aux = a->der;
	//variable donde voy a guardar si cumple o no la expresion
	int res;
	//valido la expresion del while 
	res = validaExpresion(a->izq);
	while (res == 0){
		interpreta(aux);
		res = validaExpresion(a->izq);
	}
	return res;
}

/*Metodo que valida una expresion*/
int validaExpresion(Arbol a){
	//declaro las variables donde guardare los valores si son ID
	float v1,v2;
	//se crean dos arboles auxiliares
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	//se guardan los valores del lado izquierdo y derecho del > o < o =
	val1 = a->izq;
	val2 = a->der;
	//declaro las variables para saber si es o no un id
	int res1, res2;
	//busco si el val1 se encuentra en la lista para saber si es un id o un numero
	//si si regesa 0 si no regresa 1
	res1 = buscar(lista,val1->nombre);
	if(res1 == 0){
		//si si es un id recupero su valor de la lsita y lo guardo en v1
		v1 = recuperaValorDeLista(lista, val1->nombre);
	}else if(res1 == 1){
		//si no es un id recupero el valor directamente de val1->valor
		v1 = val1->valor;
	}
	//busco si el val2 se encuentra en la lista para saber si es un id o un numero
	res2 = buscar(lista,val2->nombre);
	//si es un id regresa 0 sino regresa 1
	if(res2 == 0){
		//si es un id entonces recupero su valor de la lista (tabla de simbolos)
		v2 = recuperaValorDeLista(lista,val2->nombre);
	}else if(res2 == 1){
		//si es un numero entonces simplemente lo asigno a v2
		v2 = val2->valor;
	}	

	//si el operador es un <
	if(strcmp(a->nombre,"<") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 < v2)
			return 0;
		else return 1;
	//si el operador es un >
	}else if(strcmp(a->nombre,">") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 > v2)
			return 0;
		else return 1;
	//si el operador es un =
	}else if(strcmp(a->nombre,"=") == 0){
		//se evaluan los dos valores si es correcto regresa 0 sino 1
		if(v1 == v2)
			return 0;
		else return 1;
	}
}

/*Metodo que recorre el lado derecho de una asignacion 
para sacar el valor de la variable ENTERA*/
int iExpr(Arbol a){
	//creo dos arboles auxiliares donde guardare el valor izquierdo y el valor derecho
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	Arbol operador;
	operador = malloc(sizeof(NodoAbb));
		//guardo los valores del operador, el valor izquierdo y el valor derecho
		operador = a;
		val1 = a->izq;
		val2 = a->der;
		// si dentro del valor existe otra expresion entonces hace recursion 
		if(strcmp(val1->tipoNodo,"operador") == 0){
			iExpr(val1);
		}else {
			int res = -1;
			//si no hay mas expresiones entonces busca en la lista para ver si es un ID o un numero 
			res = buscar(lista,val1->nombre);
			//si es un id entonces recupero el valor de ese ID y lo guardo en valorParaAsignar
			if(res == 0){
				int x = (int) recuperaValorDeLista(lista, val1->nombre);
				valorParaAsignar = (float)x;
			}else if(res == 1){
			//si no es un ID entonces simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = val1->valor;
			}

		}	
		//pasamos con el segundo valor, hago un if para saber si el lado derecho tiene una expr
		if(strcmp(val2->tipoNodo,"operador") == 0){
			//si si hago recursion
			iExpr(val2);
		//si no entonces si el operado es una suma
		}else if(strcmp(operador->nombre,"+") == 0){	
			//checo que el segundo valore no sea un ID
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0 
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar + (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar + val2->valor;
			}
			//retorno el valor
			return (int)valorParaAsignar;
		//si el operador es una resta
		}else if(strcmp(operador->nombre,"-") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar - (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar - val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una multiplicacion
		}else if(strcmp(operador->nombre,"*") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar * (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar *  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una div
		}else if(strcmp(operador->nombre,"/") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				int x = (int) recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar / (float)x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar / val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
		}

	return 1;
}

/*Metodo que recorre el lado derecho de una asignacion 
para sacar el valor de la variable FLOTANTE*/
float fExpr(Arbol a){
	//creo 3 variables arbol auxiliares
	Arbol val1;
	val1 = malloc(sizeof(NodoAbb));
	Arbol val2;
	val2 = malloc(sizeof(NodoAbb));
	Arbol operador;
	operador = malloc(sizeof(NodoAbb));

		//guardo los valores que me importan 
		operador = a;
		val1 = a->izq;
		val2 = a->der;
		//si el valor del lado izquierdo es una expresion hago recursion
		if(strcmp(val1->tipoNodo,"operador") == 0){
			iExpr(val1);
		}else {
			int res = -1;
			//si no hay mas expresiones entonces busca en la lista para ver si es un ID o un numero 
			res = buscar(lista,val1->nombre);
			//si es un id entonces recupero el valor de ese ID y lo guardo en valorParaAsignar
			if(res == 0){
				float x =  recuperaValorDeLista(lista, val1->nombre);
				valorParaAsignar = x;
			}else if(res == 1){
			//si no es un ID entonces simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = val1->valor;
			}
		}
		
		if(strcmp(val2->tipoNodo,"operador") == 0){
			iExpr(val2);
		}else if(strcmp(operador->nombre,"+") == 0){
			//checo que el segundo valore no sea un ID
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0 
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar + x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar + val2->valor;
			}
			//retorno el valor
			return (int)valorParaAsignar;
		//si el operador es una resta
		}else if(strcmp(operador->nombre,"-") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar - x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar -=  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una multiplicacion
		}if(strcmp(operador->nombre,"*") == 0){
						//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar * x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar *  val2->valor;
			}
			//retorno el valor
			return (int) valorParaAsignar;
			//si el operador es una div
		}if(strcmp(operador->nombre,"/") == 0){
			//checo si el valor es un id o no
			int res = -1;
			res = buscar(lista,val2->nombre);
			//si si es un id buscar regresa 0
			if(res == 0){
				//recupero el valor de dicho ID y lo guardo en valorParaAsignar
				float x = recuperaValorDeLista(lista, val2->nombre);
				valorParaAsignar = valorParaAsignar / x;
			}else{
				//si no es un ID simplemente guardo el valor en valorParaAsignar
				valorParaAsignar = valorParaAsignar / val2->valor;
			}
			//retorno el valor
			return valorParaAsignar;
		}

	
	
	return 1.0;
}

/*Metodo que asigna una expresion a una variable*/
void asigna(Arbol a){
	valorParaAsignar = 0;
	Arbol variable;	//variable Arbol en la que guardo el valor de la variable 
	variable = malloc(sizeof(NodoAbb));
	if(a->izq != NULL){
		variable = a->izq;
		//si es una expresion de tipo entero 
		if(strcmp(a->tipoDato,"int") == 0){
			int x;
			x = iExpr(a->der);
			variable->valor = x;
		//si es una expresion de tipo flotante
		}else if(strcmp(a->tipoDato,"float") == 0){
			float x;
			x = fExpr(a->der);
			variable->valor = x;
		}

		buscarYasignar(lista,variable->nombre,variable);

	}
	
}



int main(){
	
	if((lista = (Lista *) malloc(sizeof(Lista))) == NULL)
		return -1;
	inicializar(lista);

	yyparse();
}
