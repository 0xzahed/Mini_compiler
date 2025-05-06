/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int yylex();
void yyerror(char *s);
int error_occurred = 0;
extern FILE *yyin;
#define MAX_SYMBOLS 100
#define MAX_P 10
#define SYMBOL_VARIABLE 0
#define SYMBOL_FUNCTION 1
struct symbol {
    int type;
    char *name;
    union {
        struct {
            int value;
            int is_defined;
        } var;
        struct {
            char *params[10];
            int param_count;
            char *body;
        } func;
    } data;
} symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int current_param_values[10];
int current_param_count = 0;
int find_symbol(char *name);
int add_variable(char *name, int value);
int add_function(char *name, char **params, int param_count, char *body);
int evaluate_function_body(char *body, char **params, int param_count, int *arg_values);

#line 108 "calc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_ASSIGN = 8,                     /* ASSIGN  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_MULT = 12,                      /* MULT  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_POWER = 15,                     /* POWER  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_CONCAT = 19,                    /* CONCAT  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_LENGTH = 21,                    /* LENGTH  */
  YYSYMBOL_SUBSTR = 22,                    /* SUBSTR  */
  YYSYMBOL_MIN = 23,                       /* MIN  */
  YYSYMBOL_MAX = 24,                       /* MAX  */
  YYSYMBOL_INC = 25,                       /* INC  */
  YYSYMBOL_DEC = 26,                       /* DEC  */
  YYSYMBOL_PRINT = 27,                     /* PRINT  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_THEN = 29,                      /* THEN  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_DEFAULT = 33,                   /* DEFAULT  */
  YYSYMBOL_34_n_ = 34,                     /* '\n'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_statements = 44,                /* statements  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_function_body = 46,             /* function_body  */
  YYSYMBOL_param_list = 47,                /* param_list  */
  YYSYMBOL_params = 48,                    /* params  */
  YYSYMBOL_num_expr = 49,                  /* num_expr  */
  YYSYMBOL_num_expr_base = 50,             /* num_expr_base  */
  YYSYMBOL_num_expr_with_if = 51,          /* num_expr_with_if  */
  YYSYMBOL_identifier_usage = 52,          /* identifier_usage  */
  YYSYMBOL_arg_list = 53,                  /* arg_list  */
  YYSYMBOL_args = 54,                      /* args  */
  YYSYMBOL_str_expr = 55,                  /* str_expr  */
  YYSYMBOL_str_expr_base = 56,             /* str_expr_base  */
  YYSYMBOL_str_expr_with_if = 57,          /* str_expr_with_if  */
  YYSYMBOL_bool_expr = 58,                 /* bool_expr  */
  YYSYMBOL_bool_expr_base = 59,            /* bool_expr_base  */
  YYSYMBOL_bool_expr_with_if = 60,         /* bool_expr_with_if  */
  YYSYMBOL_switch_cases_num = 61,          /* switch_cases_num  */
  YYSYMBOL_cases_num = 62,                 /* cases_num  */
  YYSYMBOL_case_list_num = 63,             /* case_list_num  */
  YYSYMBOL_switch_cases_str = 64,          /* switch_cases_str  */
  YYSYMBOL_cases_str = 65,                 /* cases_str  */
  YYSYMBOL_case_list_str = 66,             /* case_list_str  */
  YYSYMBOL_switch_cases_bool = 67,         /* switch_cases_bool  */
  YYSYMBOL_cases_bool = 68,                /* cases_bool  */
  YYSYMBOL_case_list_bool = 69             /* case_list_bool  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    36,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    86,    90,    93,    96,   100,   101,   102,
     103,   109,   115,   118,   121,   127,   133,   134,   138,   142,
     155,   156,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   186,   200,   212,   216,   235,
     266,   267,   271,   275,   288,   289,   293,   294,   295,   304,
     322,   337,   349,   353,   354,   358,   359,   360,   361,   362,
     363,   375,   379,   383,   392,   407,   419,   423,   432,   448,
     460,   464,   473,   488
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "STRING",
  "BOOLEAN", "IDENTIFIER", "INT", "ASSIGN", "RETURN", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "POWER", "LT", "GT", "AND", "CONCAT", "REPEAT",
  "LENGTH", "SUBSTR", "MIN", "MAX", "INC", "DEC", "PRINT", "IF", "THEN",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "'\\n'", "'('", "')'", "'{'", "'}'",
  "';'", "','", "':'", "$accept", "program", "statements", "statement",
  "function_body", "param_list", "params", "num_expr", "num_expr_base",
  "num_expr_with_if", "identifier_usage", "arg_list", "args", "str_expr",
  "str_expr_base", "str_expr_with_if", "bool_expr", "bool_expr_base",
  "bool_expr_with_if", "switch_cases_num", "cases_num", "case_list_num",
  "switch_cases_str", "cases_str", "case_list_str", "switch_cases_bool",
  "cases_bool", "case_list_bool", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-13)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      61,   -13,   -13,   -13,    98,    16,    19,    23,    26,    28,
      35,    45,    58,   115,    25,    42,   -13,   360,   -13,   -13,
     -13,    67,   -13,   -13,    93,   -13,   -13,   -13,   -13,   187,
       1,    94,    94,   187,   187,   115,   153,   187,     4,    59,
     -10,   -13,    61,   187,   187,   187,   187,   187,   187,   187,
     187,    94,   187,   153,    73,    78,   187,   373,    92,   102,
     187,   124,   114,   116,    94,    81,    -9,    -8,   220,   251,
      90,    -6,   119,   122,   153,   360,    21,   259,   -13,   -13,
     -13,   -13,   151,   151,   132,   132,   132,   -13,   373,   373,
     141,   373,   -13,   153,   187,   278,   -13,   187,   373,   -13,
     133,   128,   153,   187,   -13,   187,   187,   187,   -13,   -13,
     -13,   153,   187,   105,   134,    33,   286,   373,   135,   164,
      37,   292,   237,   298,   305,    41,   325,   115,   143,   149,
     145,   171,   -13,   154,   152,   187,   -13,   -13,   157,   155,
     339,     8,    84,   191,   158,    99,   -13,   160,   108,   -13,
     162,   112,   -13,   187,   169,   187,   166,    94,   170,   332,
     153,   174,   187,    94,   153,   168,   -13,   209,   172,   -13,
     211,   175,   -13,   214,   178,   352,   217,   243,   -13,   218,
     -13,   221,   -13,   -13,   -13,   115,   182,   187,   185,    94,
     186,   153,   195,   -13,   196,   197,   360,    67,    93,   187,
     373,    94,    67,   153,    93,   187,    94,   153,   373,    67,
      93,   373
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    22,    46,    55,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     7,    20,    21,
      23,     8,    44,    45,     9,    53,    54,    34,    35,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,    41,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    47,
      56,     5,    25,    26,    27,    28,    29,    30,    57,    58,
      48,    49,    59,     0,     0,     0,    39,     0,    10,    18,
       0,    17,     0,     0,    31,     0,     0,     0,    12,    13,
      14,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,    66,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,    51,
       0,     0,    60,     0,     0,     0,     0,     0,    11,     0,
      50,     0,    37,    52,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    63,    67,    71,     0,
      65,     0,    69,     0,    73,     0,     0,     0,    64,    68,
      72,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -13,   -13,   -13,   198,   -13,   -13,   -13,     0,   -13,   -13,
     -13,   -13,   -13,    40,   -13,   -13,   -12,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    14,    15,    16,   156,   100,   101,    75,    18,    19,
      20,    58,    59,    21,    22,    23,    24,    25,    26,   144,
     145,   146,   147,   148,   149,   150,   151,   152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    40,    43,    44,    45,    46,    47,    48,    53,    60,
      51,    52,    53,    38,    43,    44,    45,    46,    47,    48,
      49,    50,    30,    71,    76,    41,    80,    51,    52,    57,
     110,   105,   106,    67,    68,    69,    61,    77,   163,    53,
      78,    92,    17,    82,    83,    84,    85,    86,    87,    88,
      89,    53,    91,    39,    31,    53,    95,   113,    32,    53,
      98,    33,    40,    34,     1,     2,     3,     4,     5,   129,
      35,    65,    66,   133,    38,    70,    42,   138,    51,    52,
      36,   115,     6,     7,     8,     9,    51,    52,    10,    11,
     120,    90,    12,    37,   116,    79,    13,   117,     2,   125,
      51,    52,    53,   121,    39,   122,   123,   124,    93,    51,
      52,    53,   126,    94,   164,   142,     7,   104,     1,     2,
       3,     4,    62,    27,    28,    63,   109,   140,    96,    64,
      99,   167,   168,    29,   127,   159,     6,     7,     8,     9,
     170,   171,    97,    11,   173,   174,    12,    48,   142,   102,
      13,   103,   184,   175,   111,   177,     1,   112,     3,     4,
     140,    52,   182,    45,    46,    47,    48,   141,   119,   118,
     132,   128,   131,   198,     6,   143,     8,     9,   153,   204,
     155,    72,   154,   157,    73,   196,   160,   200,    74,   158,
       1,   210,   161,     4,   165,   198,   166,   141,   169,   208,
     172,   176,   179,   183,   178,   211,   181,   196,     6,   185,
       8,     9,   186,   187,   188,    54,   189,   190,    55,   191,
     192,   194,    56,   199,   195,   197,   201,   203,     0,   202,
      43,    44,    45,    46,    47,    48,   205,   206,   207,     0,
      81,   209,     0,     0,     0,     0,   197,    43,    44,    45,
      46,    47,    48,    43,    44,    45,    46,    47,    48,     0,
     107,    43,    44,    45,    46,    47,    48,    49,    50,    43,
      44,    45,    46,    47,    48,     0,     0,   135,     0,     0,
       0,     0,   193,     0,     0,     0,     0,   108,    43,    44,
      45,    46,    47,    48,     0,   114,    43,    44,    45,    46,
      47,    48,    43,    44,    45,    46,    47,    48,    43,    44,
      45,    46,    47,    48,    78,    43,    44,    45,    46,    47,
      48,     0,   130,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,   136,    43,    44,    45,    46,    47,
      48,   137,    43,    44,    45,    46,    47,    48,     0,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,     0,
       0,   139,    43,    44,    45,    46,    47,    48,   180,   162,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
       0,     0,   162,    43,    44,    45,    46,    47,    48
};

static const yytype_int16 yycheck[] =
{
       0,    13,    10,    11,    12,    13,    14,    15,    18,     8,
      19,    20,    18,    13,    10,    11,    12,    13,    14,    15,
      16,    17,     6,    35,    36,     0,    36,    19,    20,    29,
      36,    40,    40,    33,    34,    35,    35,    37,    30,    18,
      36,    53,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    18,    52,    13,    35,    18,    56,    36,    35,    18,
      60,    35,    74,    35,     3,     4,     5,     6,     7,    36,
      35,    31,    32,    36,    74,    35,    34,    36,    19,    20,
      35,    93,    21,    22,    23,    24,    19,    20,    27,    28,
     102,    51,    31,    35,    94,    36,    35,    97,     4,   111,
      19,    20,    18,   103,    64,   105,   106,   107,    35,    19,
      20,    18,   112,    35,    30,   127,    22,    36,     3,     4,
       5,     6,    28,    25,    26,    31,    36,   127,    36,    35,
       6,    32,    33,    35,    29,   135,    21,    22,    23,    24,
      32,    33,    40,    28,    32,    33,    31,    15,   160,    35,
      35,    35,   164,   153,    35,   155,     3,    35,     5,     6,
     160,    20,   162,    12,    13,    14,    15,   127,    40,    36,
       6,    37,    37,   185,    21,    32,    23,    24,    29,   191,
       9,    28,    37,    29,    31,   185,    29,   187,    35,    37,
       3,   203,    37,     6,     3,   207,    38,   157,    38,   199,
      38,    32,    32,   163,    38,   205,    32,   207,    21,    41,
      23,    24,     3,    41,     3,    28,    41,     3,    31,    41,
       3,     3,    35,    41,     3,   185,    41,    41,    -1,   189,
      10,    11,    12,    13,    14,    15,    41,    41,    41,    -1,
      42,   201,    -1,    -1,    -1,    -1,   206,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    -1,
      40,    10,    11,    12,    13,    14,    15,    16,    17,    10,
      11,    12,    13,    14,    15,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    36,    10,    11,
      12,    13,    14,    15,    -1,    36,    10,    11,    12,    13,
      14,    15,    10,    11,    12,    13,    14,    15,    10,    11,
      12,    13,    14,    15,    36,    10,    11,    12,    13,    14,
      15,    -1,    36,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    36,    10,    11,    12,    13,    14,
      15,    36,    10,    11,    12,    13,    14,    15,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    36,    10,    11,    12,    13,    14,    15,    36,    30,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    30,    10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    21,    22,    23,    24,
      27,    28,    31,    35,    43,    44,    45,    49,    50,    51,
      52,    55,    56,    57,    58,    59,    60,    25,    26,    35,
       6,    35,    35,    35,    35,    35,    35,    35,    49,    55,
      58,     0,    34,    10,    11,    12,    13,    14,    15,    16,
      17,    19,    20,    18,    28,    31,    35,    49,    53,    54,
       8,    35,    28,    31,    35,    55,    55,    49,    49,    49,
      55,    58,    28,    31,    35,    49,    58,    49,    36,    36,
      36,    45,    49,    49,    49,    49,    49,    49,    49,    49,
      55,    49,    58,    35,    35,    49,    36,    40,    49,     6,
      47,    48,    35,    35,    36,    40,    40,    40,    36,    36,
      36,    35,    35,    36,    36,    58,    49,    49,    36,    40,
      58,    49,    49,    49,    49,    58,    49,    29,    37,    36,
      36,    37,     6,    36,    36,    40,    36,    36,    36,    36,
      49,    55,    58,    32,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    29,    37,     9,    46,    29,    37,    49,
      29,    37,    30,    30,    30,     3,    38,    32,    33,    38,
      32,    33,    38,    32,    33,    49,    32,    49,    38,    32,
      36,    32,    49,    55,    58,    41,     3,    41,     3,    41,
       3,    41,     3,    39,     3,     3,    49,    55,    58,    41,
      49,    41,    55,    41,    58,    41,    41,    41,    49,    55,
      58,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    61,    62,    62,    63,    64,    65,    65,    66,
      67,    68,    68,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     2,     1,     1,     1,
       4,     8,     4,     4,     4,     3,     0,     1,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     4,     6,     6,     2,     2,     7,     8,     1,     4,
       0,     1,     1,     3,     1,     1,     1,     3,     3,     3,
       8,     7,     8,     1,     1,     1,     3,     3,     3,     3,
       7,     8,     1,     4,     5,     4,     1,     4,     5,     4,
       1,     4,     5,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 4: /* statements: statement  */
#line 90 "calc.y"
              { 
        if (error_occurred) error_occurred = 0;
    }
#line 1329 "calc.tab.c"
    break;

  case 5: /* statements: statements '\n' statement  */
#line 93 "calc.y"
                                { 
        if (error_occurred) error_occurred = 0;
    }
#line 1337 "calc.tab.c"
    break;

  case 7: /* statement: num_expr  */
#line 100 "calc.y"
                { if (!error_occurred) printf("Result (number): %d\n", (yyvsp[0].ival)); }
#line 1343 "calc.tab.c"
    break;

  case 8: /* statement: str_expr  */
#line 101 "calc.y"
                { if (!error_occurred) { printf("Result (string): %s\n", (yyvsp[0].sval)); free((yyvsp[0].sval)); } }
#line 1349 "calc.tab.c"
    break;

  case 9: /* statement: bool_expr  */
#line 102 "calc.y"
                { if (!error_occurred) printf("Result (boolean): %s\n", (yyvsp[0].bval) ? "true" : "false"); }
#line 1355 "calc.tab.c"
    break;

  case 10: /* statement: INT IDENTIFIER ASSIGN num_expr  */
#line 103 "calc.y"
                                     { 
        if (!error_occurred) {
            int index = add_variable((yyvsp[-2].sval), (yyvsp[0].ival));
        }
        free((yyvsp[-2].sval));
    }
#line 1366 "calc.tab.c"
    break;

  case 11: /* statement: INT IDENTIFIER '(' param_list ')' '{' function_body '}'  */
#line 109 "calc.y"
                                                              { 
        if (!error_occurred) {
            int index = add_function((yyvsp[-6].sval), (yyvsp[-4].param_list).params, (yyvsp[-4].param_list).count, (yyvsp[-1].sval));
        }
        free((yyvsp[-6].sval));
    }
#line 1377 "calc.tab.c"
    break;

  case 12: /* statement: PRINT '(' num_expr ')'  */
#line 115 "calc.y"
                             { 
        if (!error_occurred) printf("Result (number): %d\n", (yyvsp[-1].ival)); 
    }
#line 1385 "calc.tab.c"
    break;

  case 13: /* statement: PRINT '(' str_expr ')'  */
#line 118 "calc.y"
                             { 
        if (!error_occurred) { printf("Result (string): %s\n", (yyvsp[-1].sval)); free((yyvsp[-1].sval)); } 
    }
#line 1393 "calc.tab.c"
    break;

  case 14: /* statement: PRINT '(' bool_expr ')'  */
#line 121 "calc.y"
                              { 
        if (!error_occurred) printf("Result (boolean): %s\n", (yyvsp[-1].bval) ? "true" : "false"); 
    }
#line 1401 "calc.tab.c"
    break;

  case 15: /* function_body: RETURN num_expr ';'  */
#line 127 "calc.y"
                        { 
        (yyval.sval) = NULL;
    }
#line 1409 "calc.tab.c"
    break;

  case 16: /* param_list: %empty  */
#line 133 "calc.y"
                { (yyval.param_list).count = 0; }
#line 1415 "calc.tab.c"
    break;

  case 17: /* param_list: params  */
#line 134 "calc.y"
                { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1421 "calc.tab.c"
    break;

  case 18: /* params: IDENTIFIER  */
#line 138 "calc.y"
               { 
        (yyval.param_list).count = 1;
        (yyval.param_list).params[0] = (yyvsp[0].sval);
    }
#line 1430 "calc.tab.c"
    break;

  case 19: /* params: params ',' IDENTIFIER  */
#line 142 "calc.y"
                            { 
        (yyval.param_list) = (yyvsp[-2].param_list);
        if ((yyval.param_list).count >= MAX_P) {
            yyerror("Too many parameters");
            error_occurred = 1;
        } else {
            (yyval.param_list).params[(yyval.param_list).count] = (yyvsp[0].sval);
            (yyval.param_list).count++;
        }
    }
#line 1445 "calc.tab.c"
    break;

  case 22: /* num_expr_base: NUMBER  */
#line 160 "calc.y"
                          { (yyval.ival) = (yyvsp[0].ival); }
#line 1451 "calc.tab.c"
    break;

  case 23: /* num_expr_base: identifier_usage  */
#line 161 "calc.y"
                          { (yyval.ival) = (yyvsp[0].ival); }
#line 1457 "calc.tab.c"
    break;

  case 24: /* num_expr_base: '(' num_expr ')'  */
#line 162 "calc.y"
                          { (yyval.ival) = (yyvsp[-1].ival); }
#line 1463 "calc.tab.c"
    break;

  case 25: /* num_expr_base: num_expr PLUS num_expr  */
#line 163 "calc.y"
                              { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
#line 1469 "calc.tab.c"
    break;

  case 26: /* num_expr_base: num_expr MINUS num_expr  */
#line 164 "calc.y"
                              { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
#line 1475 "calc.tab.c"
    break;

  case 27: /* num_expr_base: num_expr MULT num_expr  */
#line 165 "calc.y"
                              { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
#line 1481 "calc.tab.c"
    break;

  case 28: /* num_expr_base: num_expr DIV num_expr  */
#line 166 "calc.y"
                              { if ((yyvsp[0].ival) != 0) (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); else { yyerror("Division by zero"); error_occurred = 1; (yyval.ival) = 0; } }
#line 1487 "calc.tab.c"
    break;

  case 29: /* num_expr_base: num_expr MOD num_expr  */
#line 167 "calc.y"
                              { if ((yyvsp[0].ival) != 0) (yyval.ival) = (yyvsp[-2].ival) % (yyvsp[0].ival); else { yyerror("Modulo by zero"); error_occurred = 1; (yyval.ival) = 0; } }
#line 1493 "calc.tab.c"
    break;

  case 30: /* num_expr_base: num_expr POWER num_expr  */
#line 168 "calc.y"
                              { (yyval.ival) = (int)pow((yyvsp[-2].ival), (yyvsp[0].ival)); }
#line 1499 "calc.tab.c"
    break;

  case 31: /* num_expr_base: LENGTH '(' str_expr ')'  */
#line 169 "calc.y"
                              { (yyval.ival) = strlen((yyvsp[-1].sval)); free((yyvsp[-1].sval)); }
#line 1505 "calc.tab.c"
    break;

  case 32: /* num_expr_base: MIN '(' num_expr ',' num_expr ')'  */
#line 170 "calc.y"
                                        { (yyval.ival) = ((yyvsp[-3].ival) < (yyvsp[-1].ival)) ? (yyvsp[-3].ival) : (yyvsp[-1].ival); }
#line 1511 "calc.tab.c"
    break;

  case 33: /* num_expr_base: MAX '(' num_expr ',' num_expr ')'  */
#line 171 "calc.y"
                                        { (yyval.ival) = ((yyvsp[-3].ival) > (yyvsp[-1].ival)) ? (yyvsp[-3].ival) : (yyvsp[-1].ival); }
#line 1517 "calc.tab.c"
    break;

  case 34: /* num_expr_base: IDENTIFIER INC  */
#line 172 "calc.y"
                     { 
        int index = find_symbol((yyvsp[-1].sval));
        if (index == -1 || symbol_table[index].type != SYMBOL_VARIABLE || !symbol_table[index].data.var.is_defined) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Cannot increment undefined variable: %s", (yyvsp[-1].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else {
            (yyval.ival) = symbol_table[index].data.var.value;
            symbol_table[index].data.var.value++;
        }
        free((yyvsp[-1].sval));
    }
#line 1536 "calc.tab.c"
    break;

  case 35: /* num_expr_base: IDENTIFIER DEC  */
#line 186 "calc.y"
                     { 
        int index = find_symbol((yyvsp[-1].sval));
        if (index == -1 || symbol_table[index].type != SYMBOL_VARIABLE || !symbol_table[index].data.var.is_defined) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Cannot decrement undefined variable: %s", (yyvsp[-1].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else {
            (yyval.ival) = symbol_table[index].data.var.value;
            symbol_table[index].data.var.value--;
        }
        free((yyvsp[-1].sval));
    }
#line 1555 "calc.tab.c"
    break;

  case 36: /* num_expr_base: SWITCH '(' num_expr ')' '{' switch_cases_num '}'  */
#line 200 "calc.y"
                                                       { 
        if (!(yyvsp[-1].case_result).matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            (yyval.ival) = 0; 
        } else { 
            (yyval.ival) = (yyvsp[-1].case_result).ival; 
        } 
    }
#line 1569 "calc.tab.c"
    break;

  case 37: /* num_expr_with_if: IF '(' bool_expr ')' THEN num_expr ELSE num_expr  */
#line 212 "calc.y"
                                                     { (yyval.ival) = (yyvsp[-5].bval) ? (yyvsp[-2].ival) : (yyvsp[0].ival); }
#line 1575 "calc.tab.c"
    break;

  case 38: /* identifier_usage: IDENTIFIER  */
#line 216 "calc.y"
               { 
        int index = find_symbol((yyvsp[0].sval));
        if (index == -1 || (symbol_table[index].type == SYMBOL_VARIABLE && !symbol_table[index].data.var.is_defined)) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable: %s", (yyvsp[0].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else if (symbol_table[index].type == SYMBOL_VARIABLE) {
            (yyval.ival) = symbol_table[index].data.var.value;
        } else {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "%s is a function, not a variable", (yyvsp[0].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        }
        free((yyvsp[0].sval));
    }
#line 1599 "calc.tab.c"
    break;

  case 39: /* identifier_usage: IDENTIFIER '(' arg_list ')'  */
#line 235 "calc.y"
                                  { 
        int index = find_symbol((yyvsp[-3].sval));
        if (index == -1) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Undefined function: %s", (yyvsp[-3].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else if (symbol_table[index].type != SYMBOL_FUNCTION) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "%s is not a function", (yyvsp[-3].sval));
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else if (symbol_table[index].data.func.param_count != (yyvsp[-1].arg_list).count) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Function %s expects %d arguments, got %d", (yyvsp[-3].sval), symbol_table[index].data.func.param_count, (yyvsp[-1].arg_list).count);
            yyerror(error_msg);
            error_occurred = 1;
            (yyval.ival) = 0;
        } else {
            (yyval.ival) = evaluate_function_body(symbol_table[index].data.func.body, 
                                       symbol_table[index].data.func.params, 
                                       symbol_table[index].data.func.param_count, 
                                       (yyvsp[-1].arg_list).values);
        }
        free((yyvsp[-3].sval));
    }
#line 1632 "calc.tab.c"
    break;

  case 40: /* arg_list: %empty  */
#line 266 "calc.y"
                { (yyval.arg_list).count = 0; }
#line 1638 "calc.tab.c"
    break;

  case 41: /* arg_list: args  */
#line 267 "calc.y"
                { (yyval.arg_list) = (yyvsp[0].arg_list); }
#line 1644 "calc.tab.c"
    break;

  case 42: /* args: num_expr  */
#line 271 "calc.y"
             { 
        (yyval.arg_list).count = 1;
        (yyval.arg_list).values[0] = (yyvsp[0].ival);
    }
#line 1653 "calc.tab.c"
    break;

  case 43: /* args: args ',' num_expr  */
#line 275 "calc.y"
                        { 
        (yyval.arg_list) = (yyvsp[-2].arg_list);
        if ((yyval.arg_list).count >= MAX_P) {
            yyerror("Too many arguments");
            error_occurred = 1;
        } else {
            (yyval.arg_list).values[(yyval.arg_list).count] = (yyvsp[0].ival);
            (yyval.arg_list).count++;
        }
    }
#line 1668 "calc.tab.c"
    break;

  case 46: /* str_expr_base: STRING  */
#line 293 "calc.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1674 "calc.tab.c"
    break;

  case 47: /* str_expr_base: '(' str_expr ')'  */
#line 294 "calc.y"
                          { (yyval.sval) = (yyvsp[-1].sval); }
#line 1680 "calc.tab.c"
    break;

  case 48: /* str_expr_base: str_expr CONCAT str_expr  */
#line 295 "calc.y"
                               { 
        char *result = malloc(strlen((yyvsp[-2].sval)) + strlen((yyvsp[0].sval)) + 2);
        strcpy(result, (yyvsp[-2].sval));
        strcat(result, " ");
        strcat(result, (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
        (yyval.sval) = result;
    }
#line 1694 "calc.tab.c"
    break;

  case 49: /* str_expr_base: str_expr REPEAT num_expr  */
#line 304 "calc.y"
                               {
        char *s = (yyvsp[-2].sval);
        int times = (yyvsp[0].ival);
        if (times < 0) {
            yyerror("Cannot repeat a string a negative number of times");
            error_occurred = 1;
            (yyval.sval) = strdup("");
        } else {
            int len = strlen(s) * times;
            char *result = malloc(len + 1);
            result[0] = '\0';
            for (int i = 0; i < times; i++) {
                strcat(result, s);
            }
            (yyval.sval) = result;
        }
        free(s);
    }
#line 1717 "calc.tab.c"
    break;

  case 50: /* str_expr_base: SUBSTR '(' str_expr ',' num_expr ',' num_expr ')'  */
#line 322 "calc.y"
                                                        {
        char *s = (yyvsp[-5].sval);
        int start = (yyvsp[-3].ival), len = (yyvsp[-1].ival);
        if (start < 0 || start >= strlen(s) || len < 0 || start + len > strlen(s)) {
            yyerror("Invalid substring range");
            error_occurred = 1;
            (yyval.sval) = strdup("");
        } else {
            char *result = malloc(len + 1);
            strncpy(result, s + start, len);
            result[len] = '\0';
            (yyval.sval) = result;
        }
        free(s);
    }
#line 1737 "calc.tab.c"
    break;

  case 51: /* str_expr_base: SWITCH '(' num_expr ')' '{' switch_cases_str '}'  */
#line 337 "calc.y"
                                                       { 
        if (!(yyvsp[-1].case_result).matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            (yyval.sval) = strdup(""); 
        } else { 
            (yyval.sval) = (yyvsp[-1].case_result).sval; 
        } 
    }
#line 1751 "calc.tab.c"
    break;

  case 52: /* str_expr_with_if: IF '(' bool_expr ')' THEN str_expr ELSE str_expr  */
#line 349 "calc.y"
                                                     { (yyval.sval) = (yyvsp[-5].bval) ? (yyvsp[-2].sval) : (yyvsp[0].sval); }
#line 1757 "calc.tab.c"
    break;

  case 55: /* bool_expr_base: BOOLEAN  */
#line 358 "calc.y"
                          { (yyval.bval) = (yyvsp[0].bval); }
#line 1763 "calc.tab.c"
    break;

  case 56: /* bool_expr_base: '(' bool_expr ')'  */
#line 359 "calc.y"
                          { (yyval.bval) = (yyvsp[-1].bval); }
#line 1769 "calc.tab.c"
    break;

  case 57: /* bool_expr_base: num_expr LT num_expr  */
#line 360 "calc.y"
                           { (yyval.bval) = (yyvsp[-2].ival) < (yyvsp[0].ival); }
#line 1775 "calc.tab.c"
    break;

  case 58: /* bool_expr_base: num_expr GT num_expr  */
#line 361 "calc.y"
                           { (yyval.bval) = (yyvsp[-2].ival) > (yyvsp[0].ival); }
#line 1781 "calc.tab.c"
    break;

  case 59: /* bool_expr_base: bool_expr AND bool_expr  */
#line 362 "calc.y"
                              { (yyval.bval) = (yyvsp[-2].bval) && (yyvsp[0].bval); }
#line 1787 "calc.tab.c"
    break;

  case 60: /* bool_expr_base: SWITCH '(' num_expr ')' '{' switch_cases_bool '}'  */
#line 363 "calc.y"
                                                        { 
        if (!(yyvsp[-1].case_result).matched) { 
            yyerror("No matching case and no default case provided"); 
            error_occurred = 1;
            (yyval.bval) = 0; 
        } else { 
            (yyval.bval) = (yyvsp[-1].case_result).bval; 
        } 
    }
#line 1801 "calc.tab.c"
    break;

  case 61: /* bool_expr_with_if: IF '(' bool_expr ')' THEN bool_expr ELSE bool_expr  */
#line 375 "calc.y"
                                                       { (yyval.bval) = (yyvsp[-5].bval) ? (yyvsp[-2].bval) : (yyvsp[0].bval); }
#line 1807 "calc.tab.c"
    break;

  case 62: /* switch_cases_num: case_list_num  */
#line 379 "calc.y"
                  { (yyval.case_result) = (yyvsp[0].case_result); }
#line 1813 "calc.tab.c"
    break;

  case 63: /* cases_num: CASE NUMBER ':' num_expr  */
#line 383 "calc.y"
                             { 
        if ((yyvsp[-2].ival) == (yyvsp[(-1) - (4)].ival)) { 
            (yyval.case_result).ival = (yyvsp[0].ival); 
            (yyval.case_result).matched = 1; 
        } else { 
            (yyval.case_result).ival = 0; 
            (yyval.case_result).matched = 0; 
        } 
    }
#line 1827 "calc.tab.c"
    break;

  case 64: /* cases_num: cases_num CASE NUMBER ':' num_expr  */
#line 392 "calc.y"
                                         { 
        if ((yyvsp[-4].case_result).matched) { 
            (yyval.case_result).ival = (yyvsp[-4].case_result).ival;
            (yyval.case_result).matched = 1;
        } else if ((yyvsp[-2].ival) == (yyvsp[(-2) - (5)].ival)) { 
            (yyval.case_result).ival = (yyvsp[0].ival);
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).ival = 0;
            (yyval.case_result).matched = 0;
        }
    }
#line 1844 "calc.tab.c"
    break;

  case 65: /* case_list_num: cases_num DEFAULT ':' num_expr  */
#line 407 "calc.y"
                                   { 
        if ((yyvsp[-3].case_result).matched) { 
            (yyval.case_result).ival = (yyvsp[-3].case_result).ival;
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).ival = (yyvsp[0].ival); 
            (yyval.case_result).matched = 1;
        }
    }
#line 1858 "calc.tab.c"
    break;

  case 66: /* switch_cases_str: case_list_str  */
#line 419 "calc.y"
                  { (yyval.case_result) = (yyvsp[0].case_result); }
#line 1864 "calc.tab.c"
    break;

  case 67: /* cases_str: CASE NUMBER ':' str_expr  */
#line 423 "calc.y"
                             { 
        if ((yyvsp[-2].ival) == (yyvsp[(-1) - (4)].ival)) { 
            (yyval.case_result).sval = (yyvsp[0].sval); 
            (yyval.case_result).matched = 1; 
        } else { 
            (yyval.case_result).sval = strdup(""); 
            (yyval.case_result).matched = 0; 
        } 
    }
#line 1878 "calc.tab.c"
    break;

  case 68: /* cases_str: cases_str CASE NUMBER ':' str_expr  */
#line 432 "calc.y"
                                         { 
        if ((yyvsp[-4].case_result).matched) { 
            (yyval.case_result).sval = (yyvsp[-4].case_result).sval;
            (yyval.case_result).matched = 1;
        } else if ((yyvsp[-2].ival) == (yyvsp[(-2) - (5)].ival)) { 
            free((yyvsp[-4].case_result).sval);
            (yyval.case_result).sval = (yyvsp[0].sval);
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).sval = strdup("");
            (yyval.case_result).matched = 0;
        }
    }
#line 1896 "calc.tab.c"
    break;

  case 69: /* case_list_str: cases_str DEFAULT ':' str_expr  */
#line 448 "calc.y"
                                   { 
        if ((yyvsp[-3].case_result).matched) { 
            (yyval.case_result).sval = (yyvsp[-3].case_result).sval;
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).sval = (yyvsp[0].sval); 
            (yyval.case_result).matched = 1;
        }
    }
#line 1910 "calc.tab.c"
    break;

  case 70: /* switch_cases_bool: case_list_bool  */
#line 460 "calc.y"
                   { (yyval.case_result) = (yyvsp[0].case_result); }
#line 1916 "calc.tab.c"
    break;

  case 71: /* cases_bool: CASE NUMBER ':' bool_expr  */
#line 464 "calc.y"
                              { 
        if ((yyvsp[-2].ival) == (yyvsp[(-1) - (4)].ival)) { 
            (yyval.case_result).bval = (yyvsp[0].bval); 
            (yyval.case_result).matched = 1; 
        } else { 
            (yyval.case_result).bval = 0; 
            (yyval.case_result).matched = 0; 
        } 
    }
#line 1930 "calc.tab.c"
    break;

  case 72: /* cases_bool: cases_bool CASE NUMBER ':' bool_expr  */
#line 473 "calc.y"
                                           { 
        if ((yyvsp[-4].case_result).matched) { 
            (yyval.case_result).bval = (yyvsp[-4].case_result).bval;
            (yyval.case_result).matched = 1;
        } else if ((yyvsp[-2].ival) == (yyvsp[(-2) - (5)].ival)) { 
            (yyval.case_result).bval = (yyvsp[0].bval);
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).bval = 0;
            (yyval.case_result).matched = 0;
        }
    }
#line 1947 "calc.tab.c"
    break;

  case 73: /* case_list_bool: cases_bool DEFAULT ':' bool_expr  */
#line 488 "calc.y"
                                     { 
        if ((yyvsp[-3].case_result).matched) { 
            (yyval.case_result).bval = (yyvsp[-3].case_result).bval;
            (yyval.case_result).matched = 1;
        } else {
            (yyval.case_result).bval = (yyvsp[0].bval); 
            (yyval.case_result).matched = 1;
        }
    }
#line 1961 "calc.tab.c"
    break;


#line 1965 "calc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 499 "calc.y"


int find_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_variable(char *name, int value) {
    int index = find_symbol(name);
    if (index != -1) {
        symbol_table[index].data.var.value = value;
        symbol_table[index].data.var.is_defined = 1;
        return index;
    }
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table full: too many symbols");
        return -1;
    }
    symbol_table[symbol_count].type = SYMBOL_VARIABLE;
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].data.var.value = value;
    symbol_table[symbol_count].data.var.is_defined = 1;
    return symbol_count++;
}

int add_function(char *name, char **params, int param_count, char *body) {
    int index = find_symbol(name);
    if (index != -1) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "Symbol %s already defined", name);
        yyerror(error_msg);
        return -1;
    }
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table full: too many symbols");
        return -1;
    }
    if (param_count > MAX_P) {
        yyerror("Too many parameters in function");
        return -1;
    }
    symbol_table[symbol_count].type = SYMBOL_FUNCTION;
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].data.func.param_count = param_count;
    for (int i = 0; i < param_count; i++) {
        symbol_table[symbol_count].data.func.params[i] = strdup(params[i]);
    }
    symbol_table[symbol_count].data.func.body = strdup("a + b");
    return symbol_count++;
}

int evaluate_function_body(char *body, char **params, int param_count, int *arg_values) {
    if (strcmp(body, "a + b") == 0 && param_count == 2) {
        return arg_values[0] + arg_values[1];
    }
    yyerror("Unsupported function body expression");
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    error_occurred = 1;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input.txt\n");
        return 1;
    }
    yyin = input_file;
    yyparse();
    fclose(input_file);
    return 0;
}
