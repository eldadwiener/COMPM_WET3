/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "part3.ypp" /* yacc.c:339  */

#include <iostream>
#include <fstream>
#include "part3_helpers.hpp"

extern int yylex();
extern char* yytext;
extern int yylineno;
extern FILE *yyin;

void yyerror(const char*);
void semanticError(string msg);
void operationalError(string msg);

using namespace std;


#line 84 "part3.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "part3.tab.hpp".  */
#ifndef YY_YY_PART3_TAB_HPP_INCLUDED
# define YY_YY_PART3_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    int_tok = 258,
    float_tok = 259,
    void_tok = 260,
    return_tok = 261,
    volatile_tok = 262,
    write_tok = 263,
    read_tok = 264,
    id_tok = 265,
    num_tok = 266,
    str_tok = 267,
    while_tok = 268,
    do_tok = 269,
    if_tok = 270,
    then_tok = 271,
    else_tok = 272,
    assign_tok = 273,
    or_tok = 274,
    and_tok = 275,
    relop_tok = 276,
    addop_tok = 277,
    mulop_tok = 278,
    not_tok = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PART3_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 160 "part3.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,     2,
      25,    27,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    32,
       2,     2,     2,    29,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    47,    87,   120,   124,   142,   181,   187,
     194,   207,   222,   222,   222,   228,   239,   249,   253,   257,
     261,   265,   270,   275,   281,   297,   300,   303,   307,   310,
     313,   316,   320,   326,   344,   356,   365,   391,   414,   450,
     523,   535,   550,   558,   564,   572,   579,   586,   591,   677,
     683,   729,   775,   779,   802,   825,   836,   847,   865,   873,
     976,   981,   988,   998,  1010,  1016
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "int_tok", "float_tok", "void_tok",
  "return_tok", "volatile_tok", "write_tok", "read_tok", "id_tok",
  "num_tok", "str_tok", "while_tok", "do_tok", "if_tok", "then_tok",
  "else_tok", "assign_tok", "or_tok", "and_tok", "relop_tok", "addop_tok",
  "mulop_tok", "not_tok", "'('", "'{'", "')'", "'}'", "'?'", "','", "':'",
  "';'", "'&'", "'@'", "$accept", "PROGRAM", "FDEFS", "FUNC_ENTRY",
  "FUNC_API", "FUNC_ARGS", "FUNC_ARGLIST", "BLK", "$@1", "$@2", "DCL",
  "TYPE", "STLIST", "STMT", "RETURN", "WRITE", "READ", "ASSN", "ASSN_C",
  "LVAL", "CNTRL", "BEXP", "EXP", "CALL", "CALL_ARGS", "CALL_ARGLIST", "M",
  "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,   123,    41,   125,    63,
      44,    58,    59,    38,    64
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -42

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,    10,    23,   -92,   160,     0,   -92,   -92,    35,    13,
      41,   -92,   -92,   -92,    34,    37,   -92,   -92,    61,   -92,
      12,    49,    50,   -92,    51,    61,   160,   -92,    61,    68,
     119,   -92,   -92,   -92,   -92,    25,    73,    77,   -13,   -92,
     -92,    53,    90,    56,    56,   -92,    72,   -92,   -92,   -92,
     -92,   -92,   -92,    95,   -92,    -8,   -92,    94,   -92,    56,
      60,   106,    -6,    56,    53,    53,    22,   122,   147,   116,
      99,   -92,   115,   -92,    53,    56,    56,   -92,   -92,   -92,
     129,   139,   -92,    56,   131,   -16,   144,   142,   140,   -92,
      87,   128,   -92,   -92,   -92,    56,    56,   -92,    91,   114,
     150,   -92,   143,   145,   -16,   146,   -92,    56,   -92,   -92,
     119,    53,    53,   -16,   -92,   -92,   -92,   -92,   -92,   -92,
     -16,   119,   157,   156,   -92,    56,   -92,   -92,   -16,   -92,
     148,   119,   -92,   -92,    56,   125,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    64,     1,     0,    17,    18,    19,     0,     6,
       0,    20,    21,     4,     0,     0,    12,     3,     9,    23,
       0,     0,     8,    11,    64,     0,     0,     7,     0,     0,
       0,    16,    15,    10,    14,     0,     0,     0,    54,    57,
      64,     0,     0,     0,     0,    31,     0,    22,    30,    29,
      28,    25,    32,     0,    27,     0,    58,    54,    34,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    24,     0,     0,     0,    26,    56,    33,
       0,     0,    40,     0,     0,    63,     0,    60,     0,    47,
       0,     0,    64,    64,    64,     0,     0,    52,     0,     0,
      50,    51,     0,     0,    41,     0,    59,     0,    64,    49,
       0,     0,     0,    48,    53,    64,    38,    36,    35,    37,
      62,     0,    43,    45,    46,     0,    44,    65,    65,    64,
       0,     0,    64,    42,     0,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   166,   -92,   -92,
      47,     5,   -92,   -91,   -92,   -92,   -92,   -92,   -92,   120,
     -92,   -63,   -22,   -92,   -92,   -92,   -24,    55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,     9,    21,    22,    45,    19,    29,
      46,    69,    24,    47,    48,    49,    50,    51,    52,    53,
      54,    67,    68,    56,    86,    87,     4,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    88,    89,    90,    82,   -40,    75,    76,    55,    10,
       3,    98,    63,    60,    75,    76,    64,    25,    26,   122,
      70,    71,    72,    -2,    77,     5,     6,     7,    83,     8,
     126,    32,    57,    39,    11,    57,    39,    78,    12,    81,
     133,    85,    25,    26,    91,    13,    65,    66,   123,   124,
      42,    15,    99,   100,   101,    43,    59,    58,    43,    59,
      16,   104,    18,    57,    39,    23,    57,    39,   110,   111,
     112,    20,    31,   113,   114,    33,    27,    65,    66,   -13,
      28,    42,    75,    76,   121,   120,    43,    59,    55,    43,
      59,   125,    79,     5,     6,     7,    34,     8,    61,    55,
      57,    39,    62,   128,    73,   131,    93,    94,   134,    55,
      93,    94,   135,    74,   109,    42,    57,    39,    80,    63,
     115,    75,    76,    43,    59,    35,    97,    36,    37,    38,
      39,    42,    40,   -41,    41,    95,    75,    76,    92,    43,
      59,    93,    94,    96,    42,    16,   116,    75,    76,    95,
      75,    76,    43,    44,   108,    97,   102,   136,   105,    93,
      94,    75,    76,     5,     6,     7,   103,     8,    95,    75,
      76,   106,   107,    76,   127,   117,    94,   118,   119,   132,
      17,     0,    84,   130
};

static const yytype_int16 yycheck[] =
{
      24,    64,    65,    66,    10,    18,    22,    23,    30,     4,
       0,    74,    25,    35,    22,    23,    40,    30,    31,   110,
      42,    43,    44,     0,    32,     3,     4,     5,    34,     7,
     121,    26,    10,    11,    34,    10,    11,    59,     3,    61,
     131,    63,    30,    31,    66,    32,    24,    25,   111,   112,
      25,    10,    74,    75,    76,    33,    34,    32,    33,    34,
      26,    83,    25,    10,    11,    18,    10,    11,    92,    93,
      94,    10,    25,    95,    96,    28,    27,    24,    25,    28,
      30,    25,    22,    23,   108,   107,    33,    34,   110,    33,
      34,   115,    32,     3,     4,     5,    28,     7,    25,   121,
      10,    11,    25,   125,    32,   129,    19,    20,   132,   131,
      19,    20,   134,    18,    27,    25,    10,    11,    12,    25,
      29,    22,    23,    33,    34,     6,    27,     8,     9,    10,
      11,    25,    13,    18,    15,    21,    22,    23,    16,    33,
      34,    19,    20,    27,    25,    26,    32,    22,    23,    21,
      22,    23,    33,    34,    14,    27,    27,    32,    27,    19,
      20,    22,    23,     3,     4,     5,    27,     7,    21,    22,
      23,    27,    30,    23,    17,    32,    20,    32,    32,    31,
      14,    -1,    62,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,    61,     3,     4,     5,     7,    39,
      46,    34,     3,    32,    38,    10,    26,    42,    25,    43,
      10,    40,    41,    45,    47,    30,    31,    27,    30,    44,
      61,    45,    46,    45,    28,     6,     8,     9,    10,    11,
      13,    15,    25,    33,    34,    42,    45,    48,    49,    50,
      51,    52,    53,    54,    55,    57,    58,    10,    32,    34,
      57,    25,    25,    25,    61,    24,    25,    56,    57,    46,
      57,    57,    57,    32,    18,    22,    23,    32,    57,    32,
      12,    57,    10,    34,    54,    57,    59,    60,    56,    56,
      56,    57,    16,    19,    20,    21,    27,    27,    56,    57,
      57,    57,    27,    27,    57,    27,    27,    30,    14,    27,
      61,    61,    61,    57,    57,    29,    32,    32,    32,    32,
      57,    61,    48,    56,    56,    61,    48,    17,    57,    62,
      62,    61,    31,    48,    61,    57,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    38,    39,    40,    40,
      41,    41,    43,    44,    42,    45,    45,    46,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    50,    50,    51,    52,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      59,    59,    60,    60,    61,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     4,     0,     0,     5,     1,     0,
       3,     1,     0,     0,     5,     3,     3,     1,     1,     1,
       2,     2,     3,     0,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     5,     5,     5,     4,    11,
       1,     2,     9,     5,     6,     4,     4,     2,     3,     3,
       3,     3,     3,     4,     1,     2,     2,     1,     1,     4,
       1,     0,     3,     1,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 41 "part3.ypp" /* yacc.c:1646  */
    {
					codeBuf.emit("HALT");
				}
#line 1337 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "part3.ypp" /* yacc.c:1646  */
    {
					//check for already implemented function
					if (implementedFunctions.find((yyvsp[-2]).name) != implementedFunctions.end()) {
						semanticError("function '" + (yyvsp[-2]).name + "' already implemented");
					}
					//create new FunctionInformation according to the FUNC_API info
					FunctionInformation funcInfo;
					funcInfo.argTypes = (yyvsp[-2]).argTypes;
					funcInfo.argNames = (yyvsp[-2]).argDefinitions;
					funcInfo.returnType = (yyvsp[-2]).type;
					funcInfo.locationInFile = funcStartingLine;

					//check if the function already declared
					std::map<string, FunctionInformation>::iterator itr = declaredFunctions.find((yyvsp[-2]).name);
					if (itr != declaredFunctions.end()) {
						FunctionInformation declaredFuncInfo = itr->second;
						//check for args names and types
						if ((funcInfo.argTypes != declaredFuncInfo.argTypes) || //args type check
							(funcInfo.argNames != declaredFuncInfo.argNames) || //args name check 
							(funcInfo.returnType != declaredFuncInfo.returnType)) { // return value type check
							semanticError("function '" + (yyvsp[-2]).name + "' already declared with another arguments");
						}
						// the declaration and ipmlementation are equals
						declaredFuncInfo.locationInFile = funcInfo.locationInFile;
						//do backPatch for all of the func calls until now
						codeBuf.backPatch(declaredFuncInfo.callLocations, (yyvsp[-3]).quad);
					}
					//insert the func-info to the implemeted-functions data base
					implementedFunctions.insert(std::pair<string, FunctionInformation>((yyvsp[-2]).name, funcInfo));
					//clear the symbol table
					symTable.clear();

					//do backPatch
					codeBuf.backPatch((yyvsp[0]).nextList, codeBuf.nextQuad());

					codeBuf.emit("COPYI I2 I1");
					codeBuf.emit("RETRN");
                }
#line 1380 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "part3.ypp" /* yacc.c:1646  */
    {
                    // the marker is here to fix shift/reduce conflicts with func definition
					//check for already declared function
					if (declaredFunctions.find((yyvsp[-1]).name) != declaredFunctions.end()) {
						semanticError("function '" + (yyvsp[-1]).name + "' already declared");
					}
					
					//create new FunctionInformation according to the FUNC_API info
					FunctionInformation funcInfo;
					funcInfo.argTypes = (yyvsp[-1]).argTypes;
					funcInfo.argNames = (yyvsp[-1]).argDefinitions;
					funcInfo.returnType = (yyvsp[-1]).type;
					funcInfo.locationInFile = -1;

					//check if the function already implemented
					std::map<string, FunctionInformation>::iterator itr = implementedFunctions.find((yyvsp[-1]).name);
					if (itr != implementedFunctions.end()) {
						FunctionInformation implemetedFuncInfo = itr->second;
						//check for args names and types
						if ((funcInfo.argTypes != implemetedFuncInfo.argTypes) || //args type check
							(funcInfo.argNames != implemetedFuncInfo.argNames) || //args name check 
							(funcInfo.returnType != implemetedFuncInfo.returnType)) { // return value type check
							semanticError("bad declaration for function named: '" + (yyvsp[-1]).name + "'");
						}
						// the declaration and ipmlementation are equals
						funcInfo.locationInFile = implemetedFuncInfo.locationInFile;
					}
					//insert the func-info to the declared-functions data base
					declaredFunctions.insert(std::pair<string, FunctionInformation>((yyvsp[-1]).name, funcInfo));
					//clear the symbol table
					symTable.clear();
				}
#line 1417 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "part3.ypp" /* yacc.c:1646  */
    {  }
#line 1423 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "part3.ypp" /* yacc.c:1646  */
    {
					//check if the func already implemented
					if (implementedFunctions.find(pendingFunc.first) != implementedFunctions.end()){
						semanticError("function '" + pendingFunc.first + "' already implemented");
					}
                    // make sure the current function is aware of itself, for recursion
                    funcStartingLine = codeBuf.nextQuad();
                    pendingFunc.second.locationInFile = funcStartingLine;
                    // update stack offset and regs for current function
                    currentStackOffset = 0;
                    nextFreeRegI = 3;
                    nextFreeRegF = 0;
                    functionReturnType = pendingFunc.second.returnType;
                }
#line 1442 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "part3.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[-4]).type == cmm_pint) {
                        semanticError("function with pointer return type");
                    }
                    if ((yyvsp[-4]).type == cmm_volatile) {
                        semanticError("function with volatile return type");
                    }
					//save the function's: name, type and arguments (name and type)
                    FunctionInformation func;
					func.argTypes = (yyvsp[-1]).argTypes;
					func.argNames = (yyvsp[-1]).argDefinitions;
					func.returnType = (yyvsp[-4]).type;
					func.locationInFile = -1;

                    pendingFunc.first = (yyvsp[-3]).name;
                    pendingFunc.second = func;

					(yyval).type = (yyvsp[-4]).type;
					(yyval).name = (yyvsp[-3]).name;
					(yyval).argDefinitions = (yyvsp[-1]).argDefinitions;
					(yyval).argTypes = (yyvsp[-1]).argTypes;

					//set new symbol table
					symTable.clear();
					symTable.enterBlock();

					//insert the argumets into the symbols-table
					int argsOffset = -8;

					for (int i = 0; i < (yyvsp[-1]).argDefinitions.size(); ++i) {
						Symbol arg(argsOffset, (yyvsp[-1]).argTypes[i]);
						symTable.putVar((yyvsp[-1]).argDefinitions[i], arg);
                        argsOffset -= 4;
					}
                }
#line 1482 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 181 "part3.ypp" /* yacc.c:1646  */
    { 
					(yyval).argDefinitions = (yyvsp[0]).argDefinitions;
					(yyval).argTypes = (yyvsp[0]).argTypes; 
				}
#line 1491 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 187 "part3.ypp" /* yacc.c:1646  */
    {
					(yyval).argDefinitions.clear();
					(yyval).argTypes.clear();
				}
#line 1500 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "part3.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[0]).type == cmm_volatile) {
                        semanticError("Functions cant accept volatile arguments");
                    }
					(yyval).argDefinitions = (yyvsp[-2]).argDefinitions;
					(yyval).argTypes = (yyvsp[-2]).argTypes;
					for (int i = 0; i < (yyvsp[0]).argDefinitions.size(); ++i) {
						//insert var to vars vector and update its type
						(yyval).argDefinitions.push_back((yyvsp[0]).argDefinitions[i]);
						(yyval).argTypes.push_back((yyvsp[0]).type);
					}
                 }
#line 1517 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 207 "part3.ypp" /* yacc.c:1646  */
    { 
                    if ((yyvsp[0]).type == cmm_volatile) {
                        semanticError("Functions cant accept volatile arguments");
                    }
                    (yyval).argDefinitions.clear();
                    (yyval).argTypes.clear();
					for (int i = 0; i < (yyvsp[0]).argDefinitions.size(); ++i) {
						//insert var to vars vector and update its type
						(yyval).argDefinitions.push_back((yyvsp[0]).argDefinitions[i]);
						(yyval).argTypes.push_back((yyvsp[0]).type);
					}
				}
#line 1534 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 222 "part3.ypp" /* yacc.c:1646  */
    {symTable.enterBlock();}
#line 1540 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 222 "part3.ypp" /* yacc.c:1646  */
    {symTable.leaveBlock();}
#line 1546 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 222 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList = (yyvsp[-2]).nextList;
                }
#line 1554 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 228 "part3.ypp" /* yacc.c:1646  */
    {
                    // make sure type is not void
                    if ((yyvsp[0]).type == cmm_void) {
                        semanticError("Cannot declare void variable");
                    }
                    (yyval).argDefinitions.clear();
                    // all definitions will be handled by STMT or the function
                    (yyval).type = (yyvsp[0]).type;
                    (yyval).argDefinitions.push_back((yyvsp[-2]).name);
                }
#line 1569 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).argDefinitions.clear();
                    (yyval).type = (yyvsp[0]).type;
                    (yyval).argDefinitions.push_back((yyvsp[-2]).name);
					(yyval).argDefinitions.insert((yyval).argDefinitions.end() ,(yyvsp[0]).argDefinitions.begin(), (yyvsp[0]).argDefinitions.end());
                }
#line 1580 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 249 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).type = cmm_int;
                }
#line 1588 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 253 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).type = cmm_float;
                }
#line 1596 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 257 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).type = cmm_void;
                }
#line 1604 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 261 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).type = cmm_pint;
                }
#line 1612 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 265 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).type = cmm_volatile;
                }
#line 1620 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 270 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList = (yyvsp[0]).nextList;
                    codeBuf.backPatch((yyvsp[-2]).nextList, (yyvsp[-1]).quad);
                }
#line 1629 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "part3.ypp" /* yacc.c:1646  */
    {
               }
#line 1636 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 281 "part3.ypp" /* yacc.c:1646  */
    {
                    // go over all declarations, and allocate space for them
                    for (int i=0; i<(yyvsp[-1]).argDefinitions.size(); ++i) {
                        Symbol newVar(currentStackOffset, (yyvsp[-1]).type);
                        bool success = symTable.putVar((yyvsp[-1]).argDefinitions[i], newVar);
                        // check if the id was already declared in this block
                        if (!success) {
                            semanticError("Duplicate variable declaration in the same block");
                        }
                        currentStackOffset += 4;
                    }
                    
                    // all variables were successfully added, update stack pointer
                    codeBuf.emit("ADD2I I2 I2 " + intToString(4*(yyvsp[-1]).argDefinitions.size()));
                }
#line 1656 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "part3.ypp" /* yacc.c:1646  */
    {
                }
#line 1663 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 300 "part3.ypp" /* yacc.c:1646  */
    {
                }
#line 1670 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 303 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList = (yyvsp[0]).nextList;
                }
#line 1678 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 307 "part3.ypp" /* yacc.c:1646  */
    {
                }
#line 1685 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 310 "part3.ypp" /* yacc.c:1646  */
    {
                }
#line 1692 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "part3.ypp" /* yacc.c:1646  */
    {
                }
#line 1699 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 316 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList = (yyvsp[0]).nextList;
                }
#line 1707 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 320 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList = (yyvsp[0]).nextList;
                }
#line 1715 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 326 "part3.ypp" /* yacc.c:1646  */
    {
                    if (functionReturnType != (yyvsp[-1]).type) {
                        semanticError("Bad return type");
                    }
                    // save return value to stack (last value before our frame)
                    if (functionReturnType == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF F" + intToString((yyvsp[-1]).place) + " F" + intToString(nextFreeRegF) + " -4");
                    }
                    else {
                        codeBuf.emit("STORI I" + intToString((yyvsp[-1]).place) + " I1 -4");
                    }

                    // do function end semantics
                    codeBuf.emit("COPYI I2 I1");
                    codeBuf.emit("RETRN");
                }
#line 1737 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 344 "part3.ypp" /* yacc.c:1646  */
    {
                    if (functionReturnType != cmm_void) {
                        semanticError("missing return value in non-void function");
                    }
                    // do function end semantics
                    codeBuf.emit("COPYI I2 I1");
                    codeBuf.emit("RETRN");
                }
#line 1750 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 356 "part3.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[-2]).type == cmm_float) {
                        codeBuf.emit("PRNTF F" + intToString((yyvsp[-2]).place));
                    }
                    else {
                        codeBuf.emit("PRNTI I" + intToString((yyvsp[-2]).place));
                    }
                }
#line 1763 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 365 "part3.ypp" /* yacc.c:1646  */
    {
                    string str = (yyvsp[-2]).name;
                    for (int i = 0; i < str.size(); ++i) {
                        char toPrint;
                        if (str[i] != '\\') {
                            toPrint = str[i];
                        }
                        else { 
                            // from lex, we know this char must be one of: n, \, "
                            ++i;
                            if (str[i] == 'n') {
                                toPrint = '\n';
                            }
                            else if (str[i] == '\\') {
                                toPrint = '\\';
                            }
                            else {
                                toPrint = '\"';
                            }
                        }
                        codeBuf.emit("PRNTC " + intToString( static_cast<int>(toPrint)) );
                    }
                }
#line 1791 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 391 "part3.ypp" /* yacc.c:1646  */
    {
				if ((yyvsp[-2]).type == cmm_float) {
					codeBuf.emit("READF F" + intToString(nextFreeRegF));
					codeBuf.emit("CITOF F" + intToString(nextFreeRegF+1) + " I1");
					codeBuf.emit("STORF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF + 1) + " " + intToString((yyvsp[-2]).offset));
				}
				else if ((yyvsp[-2]).type == cmm_int || (yyvsp[-2]).type == cmm_volatile) {
					codeBuf.emit("READI I" + intToString(nextFreeRegI));
                    if ((yyvsp[-2]).dereferencedPtr == true) {
                        codeBuf.emit("STORI I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[-2]).offsetReg) + " 0");
                    }
                    else {
                        codeBuf.emit("STORI I" + intToString(nextFreeRegI) + " I1" + " " + intToString((yyvsp[-2]).offset));
                    }
				}
				else {
					// id does not exist
					semanticError("variable can not be written from IO");
				}
			}
#line 1816 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 414 "part3.ypp" /* yacc.c:1646  */
    {
                    // check if types are compatible
                    string typeChar[] = {"I", "F", "I", "", "I"}; // used to convert the "types" enum to string for easier use
                    string Ltype = typeChar[(yyvsp[-3]).type];
                    string Rtype = typeChar[(yyvsp[-1]).type];
                    if (Ltype == "" || Rtype == "") {
                        semanticError("Can't assign void type");
                    }
                    if (Ltype != Rtype || ((yyvsp[-3]).type == cmm_pint && (yyvsp[-1]).type != cmm_pint) || ((yyvsp[-3]).type != cmm_pint && (yyvsp[-1]).type == cmm_pint)) {
                        semanticError ("Bad assignment, type mismatch");
                    }

                    if ((yyvsp[-3]).type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF F" + intToString((yyvsp[-1]).place) + " F" + intToString(nextFreeRegF) + " " + intToString((yyvsp[-3]).offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ((yyvsp[-1]).type == cmm_volatile) {
                            codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-1]).offset));
                            (yyvsp[-1]).place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ((yyvsp[-3]).dereferencedPtr == true) {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-1]).place) + " I" + intToString((yyvsp[-3]).offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-1]).place) + " I1 " + intToString((yyvsp[-3]).offset));
                        }
                    }

                }
#line 1853 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 450 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList.clear();
                    // check if types are compatible
                    string typeChar[] = {"I", "F", "P", "", "I"}; // used to convert the "types" enum to string for easier use
                    string Ltype = typeChar[(yyvsp[-10]).type];
                    string Rtype1 = typeChar[(yyvsp[-5]).type];
                    string Rtype2 = typeChar[(yyvsp[-1]).type];
                    if (Ltype == "" || Rtype1 == "" || Rtype2 == "") {
                        semanticError("Can't assign void type");
                    }
                    if (Ltype != Rtype1 || Ltype != Rtype2) {
                        semanticError ("Bad assignment, type mismatch");
                    }
                    // change type char from P to I for ease of programming
                    if (Ltype == "P") {
                        Ltype = "I";
                        Rtype1 = "I";
                        Rtype2 = "I";
                    }
                    // patch BEXP lists
                    codeBuf.backPatch((yyvsp[-8]).trueList, (yyvsp[-6]).quad);
                    codeBuf.backPatch((yyvsp[-8]).falseList, (yyvsp[-2]).quad);

                    // start with assignment of second EXP
                    if ((yyvsp[-10]).type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF F" + intToString((yyvsp[-1]).place) + " F" + intToString(nextFreeRegF) + " " + intToString((yyvsp[-10]).offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ((yyvsp[-1]).type == cmm_volatile) {
                            codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-1]).offset));
                            (yyvsp[-1]).place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ((yyvsp[-10]).dereferencedPtr == true) {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-1]).place) + " I" + intToString((yyvsp[-10]).offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-1]).place) + " I1 " + intToString((yyvsp[-10]).offset));
                        }
                    }
                    
                    // done assignment, need "goto next"
                    (yyval).nextList.push_back(codeBuf.nextQuad());
                    codeBuf.emit("UJUMP");
                    
                    // done with assignment code for EXP2, we can patch to make EXP1 code jump here
                    codeBuf.backPatch((yyvsp[-4]).nextList, codeBuf.nextQuad());

                    // start assignment code for first EXP
                    if ((yyvsp[-10]).type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("STORF F" + intToString((yyvsp[-5]).place) + " F" + intToString(nextFreeRegF) + " " + intToString((yyvsp[-10]).offset));
                    }
                    else {
                        // if the exp is volatile, we need to read it first
                        if ((yyvsp[-5]).type == cmm_volatile) {
                            codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I0 " + intToString((yyvsp[-5]).offset));
                            (yyvsp[-5]).place = nextFreeRegI;
                            ++nextFreeRegI;
                        }
                        if ((yyvsp[-10]).dereferencedPtr == true) {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-5]).place) + " I" + intToString((yyvsp[-10]).offsetReg) + " 0");
                        }
                        else {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-5]).place) + " I1 " + intToString((yyvsp[-10]).offset));
                        }
                    }
                }
#line 1928 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 523 "part3.ypp" /* yacc.c:1646  */
    {
					Symbol idSymbol = symTable.getVar((yyvsp[0]).name);
					// make sure the id exists
					if (idSymbol.offset == -1) {
						// id does not exist
						semanticError("variable '" + (yyvsp[0]).name + "' is not declared");
					}
					(yyval).type = idSymbol.type;
					(yyval).offset = idSymbol.offset;
                    (yyval).dereferencedPtr = false;
				}
#line 1944 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 535 "part3.ypp" /* yacc.c:1646  */
    {
					// make sure the EXP is a pointer
					if ((yyvsp[0]).type != cmm_pint) {
						semanticError("Trying to dereference a non-pointer variable");
					}
					codeBuf.emit("COPYI I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[0]).place));
                    (yyval).offsetReg = nextFreeRegI;
					++nextFreeRegI;
					(yyval).type = cmm_volatile;
                    (yyval).dereferencedPtr = true;
				}
#line 1960 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 550 "part3.ypp" /* yacc.c:1646  */
    {
					codeBuf.backPatch((yyvsp[-7]).trueList, (yyvsp[-5]).quad);
					codeBuf.backPatch((yyvsp[-7]).falseList, (yyvsp[-1]).quad);
					//merge STMT1.nextList, N.nextList and STMT2.nextList into CNTRL.nextList
					codeBuf.merge((yyvsp[-4]).nextList, (yyvsp[-2]).nextList, (yyval).nextList);
					codeBuf.merge((yyvsp[0]).nextList, (yyval).nextList, (yyval).nextList);
                 }
#line 1972 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 558 "part3.ypp" /* yacc.c:1646  */
    {
					codeBuf.backPatch((yyvsp[-3]).trueList, (yyvsp[-1]).quad);
					//merge STMT.nextList and BEXP.falseList into CNTRL.nextList
					codeBuf.merge((yyvsp[0]).nextList, (yyvsp[-3]).falseList, (yyval).nextList);  
                 }
#line 1982 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 564 "part3.ypp" /* yacc.c:1646  */
    {
					codeBuf.backPatch((yyvsp[-3]).trueList, (yyvsp[-1]).quad);
					codeBuf.backPatch((yyvsp[0]).nextList, (yyvsp[-4]).quad);
					(yyval).nextList = (yyvsp[-3]).falseList;
					codeBuf.emit("UJUMP " + intToString((yyvsp[-4]).quad));
                 }
#line 1993 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 572 "part3.ypp" /* yacc.c:1646  */
    {
					//if BEXP1 == false go to BEXP2
					codeBuf.backPatch((yyvsp[-3]).falseList, (yyvsp[-1]).quad); 
					codeBuf.merge((yyvsp[-3]).trueList, (yyvsp[0]).trueList, (yyval).trueList);
					(yyval).falseList = (yyvsp[0]).falseList;
                }
#line 2004 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 579 "part3.ypp" /* yacc.c:1646  */
    {
					//if BEXP1 == true go to BEXP2
					codeBuf.backPatch((yyvsp[-3]).trueList, (yyvsp[-1]).quad); 
					codeBuf.merge((yyvsp[-3]).falseList, (yyvsp[0]).falseList, (yyval).falseList);
					(yyval).trueList = (yyvsp[0]).trueList;
                }
#line 2015 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 586 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).trueList = (yyvsp[0]).falseList;
                    (yyval).falseList = (yyvsp[0]).trueList;
                }
#line 2024 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 591 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).trueList.clear();
                    (yyval).falseList.clear();
                    
                    string type = "";
                    if ( (yyvsp[-2]).type == cmm_volatile && ((yyvsp[0]).type == cmm_volatile || (yyvsp[0]).type == cmm_int)) {
                        type = "I";
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-2]).offset));
                        (yyvsp[-2]).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    if ( (yyvsp[0]).type == cmm_volatile && ((yyvsp[-2]).type == cmm_volatile || (yyvsp[-2]).type == cmm_int)) {
                        type = "I";
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[0]).offset));
                        (yyvsp[0]).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    if ( (yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_int ) {
                        type = "I";
                    }
                    if ( (yyvsp[-2]).type == cmm_float && (yyvsp[0]).type == cmm_float ) {
                        type = "F";
                    }
                    if (type == "") {
                        semanticError("relop between incompatible types");
                    }

                    // perform the check, and do the jumps
                    if (type == "I") {
                        (yyval).trueList.push_back(codeBuf.nextQuad() + 1);
                        (yyval).falseList.push_back(codeBuf.nextQuad() + 2);
                        (yyval).place = nextFreeRegI;
                    }
                    else {
                        (yyval).trueList.push_back(codeBuf.nextQuad() + 2);
                        (yyval).falseList.push_back(codeBuf.nextQuad() + 3);
                        (yyval).place = nextFreeRegF;
                    }

                    if ((yyvsp[-1]).name == "==") {
                        codeBuf.emit("SEQU" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ((yyvsp[-1]).name == "<>") {
                        codeBuf.emit("SNEQ" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ((yyvsp[-1]).name == "<") {
                        codeBuf.emit("SLET" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ((yyvsp[-1]).name == "<=") {
                        codeBuf.emit("SGRT" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BREQZ I" + intToString(nextFreeRegI));
                    }
                    else if ((yyvsp[-1]).name == ">") {
                        codeBuf.emit("SGRT" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BNEQZ I" + intToString(nextFreeRegI));
                    }
                    else if ((yyvsp[-1]).name == ">=") {
                        codeBuf.emit("SLET" + type + " " + type + intToString((yyval).place) + " " + type + intToString((yyvsp[-2]).place) + " " + type + intToString((yyvsp[0]).place));
                        if (type == "F") {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyval).place));
                        }
                        codeBuf.emit("BREQZ I" + intToString(nextFreeRegI));
                    }

                    codeBuf.emit("UJUMP");

                }
#line 2114 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 677 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).trueList = (yyvsp[-1]).trueList;
                    (yyval).falseList = (yyvsp[-1]).falseList;
                }
#line 2123 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 683 "part3.ypp" /* yacc.c:1646  */
    {
                    // check if add or sub
                    string op;
                    if ((yyvsp[-1]).name == "+") {
                        op = "ADD2";
                    }
                    else {
                        op = "SUBT";
                    }

                    // check if types are compatible (2 ints/ 2 floats)
                    if ((yyvsp[-2]).type == cmm_float && (yyvsp[0]).type == cmm_float) {
                        codeBuf.emit(op + "F F" + intToString((yyvsp[-2]).place) + " F" + intToString((yyvsp[-2]).place) + " F" + intToString((yyvsp[0]).place));
                        (yyval) = (yyvsp[-2]);
                    }
                    else if ((yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_int) {
                        codeBuf.emit(op + "I I" + intToString((yyvsp[-2]).place) + " I" + intToString((yyvsp[-2]).place) + " I" + intToString((yyvsp[0]).place));
                        (yyval) = (yyvsp[-2]);
                    }
                    else if ((yyvsp[-2]).type == cmm_volatile && (yyvsp[0]).type == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-2]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[0]).place));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ((yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[0]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[-2]).place));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ((yyvsp[-2]).type == cmm_volatile && (yyvsp[0]).type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-2]).offset));
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI + 1) + " I1 " + intToString((yyvsp[0]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI + 1));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else {
                        semanticError("ADDOP between different types");
                    }
                }
#line 2173 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 729 "part3.ypp" /* yacc.c:1646  */
    {
                    // check if mult or div
                    string op;
                    if ((yyvsp[-1]).name == "*") {
                        op = "MULT";
                    }
                    else {
                        op = "DIVD";
                    }

                    // check if types are compatible (2 ints/ 2 floats)
                    if ((yyvsp[-2]).type == cmm_float && (yyvsp[0]).type == cmm_float) {
                        codeBuf.emit(op + "F F" + intToString((yyvsp[-2]).place) + " F" + intToString((yyvsp[-2]).place) + " F" + intToString((yyvsp[0]).place));
                        (yyval) = (yyvsp[-2]);
                    }
                    else if ((yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_int) {
                        codeBuf.emit(op + "I I" + intToString((yyvsp[-2]).place) + " I" + intToString((yyvsp[-2]).place) + " I" + intToString((yyvsp[0]).place));
                        (yyval) = (yyvsp[-2]);
                    }
                    else if ((yyvsp[-2]).type == cmm_volatile && (yyvsp[0]).type == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-2]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[0]).place));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ((yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[0]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString((yyvsp[-2]).place));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else if ((yyvsp[-2]).type == cmm_volatile && (yyvsp[0]).type == cmm_volatile) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[-2]).offset));
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI + 1) + " I1 " + intToString((yyvsp[0]).offset));
                        codeBuf.emit(op + "I I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI) + " I" + intToString(nextFreeRegI + 1));
                        (yyval).type = cmm_int;
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                    else {
                        semanticError("MULOP between different types");
                    }
                }
#line 2223 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 775 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval) = (yyvsp[-1]);
                }
#line 2231 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 779 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval) = (yyvsp[0]);
                    if ( (yyvsp[-2]).type != (yyvsp[0]).type ) {
                        // TODO: is there casting to void?
                        if ( (yyvsp[-2]).type == cmm_int && (yyvsp[0]).type == cmm_float ) {
                            codeBuf.emit("CFTOI I" + intToString(nextFreeRegI) + " F" + intToString((yyvsp[0]).place));
                            (yyval).place = nextFreeRegI;
                            ++nextFreeRegI;
                            (yyval).type = cmm_int;
                        }

                        else if ( (yyvsp[-2]).type == cmm_float && (yyvsp[0]).type == cmm_int ) {
                            codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I" + intToString((yyvsp[0]).place));
                            (yyval).place = nextFreeRegF;
                            ++nextFreeRegF;
                            (yyval).type = cmm_float;
                        }
                        else {
                            semanticError("Cast unsupported");
                        }
                    }
                }
#line 2258 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 802 "part3.ypp" /* yacc.c:1646  */
    {
                    Symbol idSymbol = symTable.getVar((yyvsp[0]).name);
                    // make sure the id exists
                    if (idSymbol.offset == -1) {
                        // id does not exist
                        semanticError("variable '" + (yyvsp[0]).name + "' is not declared");
                    }
                    (yyval).type = idSymbol.type;
                    (yyval).offset = idSymbol.offset;
                    if ((yyval).type == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I1");
                        codeBuf.emit("LOADF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF) + " " + intToString(idSymbol.offset));
                        (yyval).place = nextFreeRegF;
                        ++nextFreeRegF;
                    }
                    else { // int/volatile/pint
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I1 " + intToString(idSymbol.offset));
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }

                }
#line 2285 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 825 "part3.ypp" /* yacc.c:1646  */
    {
                    // make sure EXP is a volatile int
                    if ((yyvsp[0]).type != cmm_volatile) {
                        semanticError("Trying to reference a non-volatile variable");
                    }
                    codeBuf.emit("ADD2I I" + intToString(nextFreeRegI) + " I1 " + intToString((yyvsp[0]).offset));
                    (yyval).place = nextFreeRegI;
                    ++nextFreeRegI;
                    (yyval).type = cmm_pint;
                }
#line 2300 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 836 "part3.ypp" /* yacc.c:1646  */
    {
                    // make sure the EXP is a pointer
                    if ( (yyvsp[0]).type != cmm_pint ) {
                        semanticError("Trying to dereference a non-pointer variable");
                    }
                    codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " 0 I" + intToString((yyvsp[0]).place) );
                    (yyval).place = nextFreeRegI;
                    ++nextFreeRegI;
                    (yyval).type = cmm_int;
                    }
#line 2315 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 847 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).name = (yyvsp[0]).name;
                    if ( (yyval).name.find('.') != std::string::npos ) {
                        // the number is a floating point
                        codeBuf.emit("COPYF F" + intToString(nextFreeRegF) + " " + (yyval).name);
                        (yyval).place = nextFreeRegF;
                        (yyval).type = cmm_float;
                        ++nextFreeRegF;
                    } 
                    else {
                        // the number is a normal int
                        codeBuf.emit("COPYI I" + intToString(nextFreeRegI) + " " + (yyval).name);
                        (yyval).place = nextFreeRegI;
                        (yyval).type = cmm_int;
                        ++nextFreeRegI;
                    }
                }
#line 2337 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 865 "part3.ypp" /* yacc.c:1646  */
    { 
                    (yyval).place = (yyvsp[0]).place;
                    (yyval).type = (yyvsp[0]).type;
                }
#line 2346 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 873 "part3.ypp" /* yacc.c:1646  */
    {
                    map<string, FunctionInformation>::iterator itr = implementedFunctions.find((yyvsp[-3]).name);
                    bool implemented = false;
                    FunctionInformation *tmpfunc;
                    if ( itr != implementedFunctions.end()) {
                        implemented = true;
                        tmpfunc = &itr->second;
                    }
                    else if ( pendingFunc.first == (yyvsp[-3]).name) {
                        // this is a recursive call
                        implemented = true;
                        tmpfunc = &pendingFunc.second;
                    }
                    else {
                        itr = declaredFunctions.find((yyvsp[-3]).name);
                        if (itr == declaredFunctions.end()) {
                            semanticError("undeclared function '" + (yyvsp[-3]).name + "'");
                        }
                        tmpfunc = &itr->second;
                    }
                    FunctionInformation &func = *tmpfunc;
                    /* found a function implementation/declaration */
                    if ( func.argTypes != (yyvsp[-1]).argTypes ) {
                        semanticError("bad function call, argument types don't match");
                    }

                    /* start function call procedure */
                    
                    int savedStateOffset = 0;
                    // save local registers
                    for (int i=0; i < nextFreeRegI; ++i) {
                        codeBuf.emit("STORI I" + intToString(i) + " I2 " + intToString(savedStateOffset));
                        savedStateOffset += 4;
                    }

                    // store a float representation of I2 for use in all STORF operations
                    codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I2");

                    for (int i=0; i < nextFreeRegF; ++i) {
                        codeBuf.emit("STORF F" + intToString(i) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset));
                        savedStateOffset += 4;
                    }

                    // store arguments for callee
                    for (int i=(yyvsp[-1]).argRegs.size() - 1; i >= 0; --i) {
                        if ( (yyvsp[-1]).argTypes[i] == cmm_float) {
                            codeBuf.emit("STORF F" + intToString((yyvsp[-1]).argRegs[i]) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset));
                        }
                        else {
                            codeBuf.emit("STORI I" + intToString((yyvsp[-1]).argRegs[i]) + " I2 " + intToString(savedStateOffset));
                        }
                        savedStateOffset += 4;
                    }

                    // save space for return value
                    savedStateOffset += 4;

                    // update frame and stack pointers to start of callee's frame
                    codeBuf.emit("ADD2I I2 I2 " + intToString(savedStateOffset));
                    codeBuf.emit("COPYI I1 I2");

                    // finally we can call the poor fella, good luck mate
                    if ( !implemented ) { 
                        func.callLocations.push_back(codeBuf.nextQuad());
                    }
                    codeBuf.emit("JLINK " + intToString(func.locationInFile));

                    // now we have returned, need to restore our state and save the return value

                    codeBuf.emit("SUBTI I2 I2 " + intToString(savedStateOffset));

                    int restoredStateOffset = 0;
                    for (int i=0; i < nextFreeRegI; ++i) {
                        codeBuf.emit("LOADI I" + intToString(i) + " I2 " + intToString(restoredStateOffset));
                        restoredStateOffset += 4;
                    }

                    // float representation of I2 for use in loadf, in case we need to restore any float regs
                    if (nextFreeRegF > 0 || func.returnType == cmm_float) {
                        codeBuf.emit("CITOF F" + intToString(nextFreeRegF) + " I2");
                    }

                    for (int i=0; i < nextFreeRegF; ++i) {
                        codeBuf.emit("LOADF F" + intToString(i) + " F" + intToString(nextFreeRegF) + " " + intToString(restoredStateOffset));
                        restoredStateOffset += 4;
                    }

                    // save the return value
                    (yyval).type = func.returnType;
                    if (func.returnType == cmm_float) {
                        codeBuf.emit("LOADF F" + intToString(nextFreeRegF) + " F" + intToString(nextFreeRegF) + " " + intToString(savedStateOffset - 4)); 
                        (yyval).place = nextFreeRegF;
                        ++nextFreeRegF;
                    }
                    else if (func.returnType == cmm_int) {
                        codeBuf.emit("LOADI I" + intToString(nextFreeRegI) + " I2" + " " + intToString(savedStateOffset - 4));
                        (yyval).place = nextFreeRegI;
                        ++nextFreeRegI;
                    }
                }
#line 2451 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 976 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).argTypes = (yyvsp[0]).argTypes;
                    (yyval).argRegs = (yyvsp[0]).argRegs;
                }
#line 2460 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 981 "part3.ypp" /* yacc.c:1646  */
    { 
                    (yyval).argTypes.clear();
                    (yyval).argRegs.clear();
                }
#line 2469 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 988 "part3.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[0]).type == cmm_volatile) {
                        semanticError("Functions cant accept volatile arguments");
                    }
					(yyval).argTypes = (yyvsp[-2]).argTypes;
					(yyval).argRegs = (yyvsp[-2]).argRegs;
					(yyval).argTypes.push_back((yyvsp[0]).type);
					(yyval).argRegs.push_back((yyvsp[0]).place);       
                }
#line 2483 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 998 "part3.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[0]).type == cmm_volatile) {
                        semanticError("Functions cant accept volatile arguments");
                    }
                    (yyval).argTypes.clear();
                    (yyval).argRegs.clear();
					(yyval).argTypes.push_back((yyvsp[0]).type); 
                    (yyval).argRegs.push_back((yyvsp[0]).place); 
                 }
#line 2497 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1010 "part3.ypp" /* yacc.c:1646  */
    {
					(yyval).quad = codeBuf.nextQuad();
				}
#line 2505 "part3.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1016 "part3.ypp" /* yacc.c:1646  */
    {
                    (yyval).nextList.clear();
                    (yyval).nextList.push_back(codeBuf.nextQuad());
                    codeBuf.emit("UJUMP");
				}
#line 2515 "part3.tab.cpp" /* yacc.c:1646  */
    break;


#line 2519 "part3.tab.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1022 "part3.ypp" /* yacc.c:1906  */


int main(int argc, char* argv[]){
	// check if arguments are good
	if (argc != 2) {
		operationalError("bad arguments");
    }
	yyin = fopen(argv[1], "r");
	if (yyin == NULL) {
		operationalError("failed reading the cmm file");
    }
    // make sure the file ends with .cmm
	string fileName = argv[1];
    if (fileName.size() < 4 || fileName.substr(fileName.size() - 4) != ".cmm") {
		operationalError("input file must be a .cmm file");
    }
	
	yyparse();
	
    // create the header for the file
	string unimplementedHeader = "<unimplemented>";
	string implementedHeader = "<implemented>";
	map<string, FunctionInformation>:: iterator itr;
	// create headed line for the implemented and unimplemented functions
	itr = implementedFunctions.begin();
	while (itr != implementedFunctions.end()) {
		FunctionInformation currentFunc = itr->second;
		implementedHeader = implementedHeader + " " + itr->first + "," + intToString(currentFunc.locationInFile);
		++itr;
	}
	itr = declaredFunctions.begin();
	while (itr != declaredFunctions.end()) {
		FunctionInformation currentFunc = itr->second;
		if (currentFunc.locationInFile == -1) {
			// function is unimplemented
			unimplementedHeader += " " + itr->first;
			for (int i=0; i < currentFunc.callLocations.size(); ++i) {
				unimplementedHeader += "," + intToString(currentFunc.callLocations[i]);
			}
		}
		++itr;
	}

	ofstream output;
	string outfileName = fileName.substr(0, fileName.size() - 3) + "rsk";

	output.open(outfileName.c_str());
    output << "<header>" << endl;
    output << unimplementedHeader << endl;
    output << implementedHeader << endl;
    output << "</header>" << endl;
	output << codeBuf.getCodeString();
	output.close();
	
	return 0;
	
}

void yyerror(const char* msg) {
    cerr << "Syntax error: " << yytext << " in line number " << yylineno << endl;
    exit(2);
}

void semanticError(string msg) {
    cerr << "Semantic error: " << msg << " in line number " << yylineno << endl;
    exit(3);
}

void operationalError(string msg) {
    cerr << "Operational error: " << msg << endl;
    exit(9);
}
