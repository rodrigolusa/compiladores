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
#line 1 "parser.y"

/*Grupo P -> João Carlos Almeida da Silva - Rodrigo Antonio Rezende Lusa*/

#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int yylex(void);
void yyerror (char const *s);
extern int get_line_number (void);
extern char *yytext;
extern void *arvore;


#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 7,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 8,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 9,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 10,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 11,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 12,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 13,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 14,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 15,                  /* TK_OC_OR  */
  YYSYMBOL_TK_OC_MAP = 16,                 /* TK_OC_MAP  */
  YYSYMBOL_TK_IDENTIFICADOR = 17,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 18,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 19,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 20,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 21,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_ERRO = 22,                   /* TK_ERRO  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '!'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_array = 40,                     /* array  */
  YYSYMBOL_element = 41,                   /* element  */
  YYSYMBOL_type = 42,                      /* type  */
  YYSYMBOL_literal = 43,                   /* literal  */
  YYSYMBOL_operando = 44,                  /* operando  */
  YYSYMBOL_global = 45,                    /* global  */
  YYSYMBOL_vars = 46,                      /* vars  */
  YYSYMBOL_function = 47,                  /* function  */
  YYSYMBOL_header = 48,                    /* header  */
  YYSYMBOL_param_list = 49,                /* param_list  */
  YYSYMBOL_params = 50,                    /* params  */
  YYSYMBOL_param = 51,                     /* param  */
  YYSYMBOL_body = 52,                      /* body  */
  YYSYMBOL_commands_block = 53,            /* commands_block  */
  YYSYMBOL_simple_command = 54,            /* simple_command  */
  YYSYMBOL_command_list = 55,              /* command_list  */
  YYSYMBOL_local_var_command = 56,         /* local_var_command  */
  YYSYMBOL_local_vars_list = 57,           /* local_vars_list  */
  YYSYMBOL_local_var_list_complement = 58, /* local_var_list_complement  */
  YYSYMBOL_set_command = 59,               /* set_command  */
  YYSYMBOL_function_call = 60,             /* function_call  */
  YYSYMBOL_args_list = 61,                 /* args_list  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_arg = 63,                       /* arg  */
  YYSYMBOL_return_command = 64,            /* return_command  */
  YYSYMBOL_flow_control_command = 65,      /* flow_control_command  */
  YYSYMBOL_condicional = 66,               /* condicional  */
  YYSYMBOL_condicional_complement = 67,    /* condicional_complement  */
  YYSYMBOL_iterative = 68,                 /* iterative  */
  YYSYMBOL_opG0 = 69,                      /* opG0  */
  YYSYMBOL_opG1 = 70,                      /* opG1  */
  YYSYMBOL_opG2 = 71,                      /* opG2  */
  YYSYMBOL_opG3 = 72,                      /* opG3  */
  YYSYMBOL_opG4 = 73,                      /* opG4  */
  YYSYMBOL_opAnd = 74,                     /* opAnd  */
  YYSYMBOL_opOr = 75,                      /* opOr  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_expr1 = 77,                     /* expr1  */
  YYSYMBOL_expr2 = 78,                     /* expr2  */
  YYSYMBOL_expr3 = 79,                     /* expr3  */
  YYSYMBOL_expr4 = 80,                     /* expr4  */
  YYSYMBOL_expr5 = 81,                     /* expr5  */
  YYSYMBOL_expr6 = 82,                     /* expr6  */
  YYSYMBOL_expr7 = 83                      /* expr7  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    34,     2,     2,
      25,    26,    32,    35,    24,    30,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
      36,    29,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    92,    97,   108,   116,   119,   126,   127,
     128,   132,   135,   138,   141,   147,   150,   153,   160,   165,
     166,   170,   177,   183,   183,   186,   186,   189,   192,   200,
     203,   209,   240,   252,   255,   258,   261,   264,   267,   274,
     280,   287,   291,   294,   300,   308,   316,   325,   328,   334,
     338,   344,   350,   358,   358,   362,   375,   378,   385,   393,
     396,   402,   405,   408,   414,   417,   423,   426,   429,   432,
     438,   441,   447,   453,   459,   462,   470,   473,   481,   484,
     492,   495,   503,   506,   514,   517,   525,   528,   535,   538
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_OC_MAP", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_ERRO", "';'", "','",
  "'('", "')'", "'{'", "'}'", "'='", "'-'", "'!'", "'*'", "'/'", "'%'",
  "'+'", "'<'", "'>'", "$accept", "programa", "array", "element", "type",
  "literal", "operando", "global", "vars", "function", "header",
  "param_list", "params", "param", "body", "commands_block",
  "simple_command", "command_list", "local_var_command", "local_vars_list",
  "local_var_list_complement", "set_command", "function_call", "args_list",
  "args", "arg", "return_command", "flow_control_command", "condicional",
  "condicional_complement", "iterative", "opG0", "opG1", "opG2", "opG3",
  "opG4", "opAnd", "opOr", "expr", "expr1", "expr2", "expr3", "expr4",
  "expr5", "expr6", "expr7", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      43,   -28,   -28,   -28,   -19,    18,   -28,    43,     8,   -28,
     -28,    16,    76,   -28,   -28,   -28,    -8,     5,   -28,   -28,
      38,    35,    65,   -28,   -28,    55,    66,    67,    33,    45,
     -28,    77,    70,    62,    32,    72,    74,    75,    78,   -28,
     -28,    79,   -28,    80,    76,   -28,    33,    33,    81,   -28,
     -28,   -28,   -28,    33,   -28,   -28,   -28,   -28,   -28,    48,
      84,    86,    73,    -7,    27,    50,   -28,   -28,    33,    33,
       7,   -28,    83,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,    76,   -28,    -3,    13,    30,   -28,   -28,    33,   -28,
      33,   -28,   -28,    33,   -28,   -28,   -28,   -28,    33,   -28,
     -28,    33,   -28,   -28,   -28,    33,    82,   -28,    85,    84,
      84,    57,    77,    77,   -28,    16,    16,   -28,    86,    73,
      -7,    27,    50,   -28,   -28,    33,   -28,   -28,   -28,    -2,
     -28,   -28,    16,   -28,   -28,    87,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     8,     9,    10,     0,     0,     2,     5,     0,     7,
       6,     0,    24,     1,     4,    20,     0,     0,    21,    28,
       0,     0,    23,    26,    18,     0,     0,     0,     0,     0,
      30,     0,     0,     0,    32,     0,     0,     0,     0,    36,
      53,     0,    27,     0,     0,    19,     0,     0,    15,    11,
      12,    14,    13,     0,    59,    60,    16,    88,    17,     0,
      52,    74,    76,    78,    80,    82,    84,    86,    48,     0,
      42,    39,    43,    33,    29,    31,    34,    35,    38,    37,
      54,     0,    25,     0,     0,     0,    87,    73,     0,    72,
       0,    70,    71,     0,    68,    69,    66,    67,     0,    65,
      64,     0,    61,    62,    63,     0,     0,    47,    50,    51,
      45,     0,     0,     0,    22,     0,     0,    89,    75,    77,
      79,    81,    83,    85,    46,     0,    44,    40,    41,     0,
      58,    49,     0,    57,    55,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    96,   -28,   -10,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,    68,   -28,   -11,    88,   -28,   -28,   -25,
     -28,   -28,    10,   -28,   -12,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -27,    26,
      25,    23,    19,    17,    14,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    56,    57,     9,    16,    10,
      11,    21,    22,    23,    18,    32,    33,    34,    35,    71,
      72,    36,    58,   106,   107,   108,    38,    39,    40,   134,
      41,    59,   105,   101,    98,    93,    90,    88,   109,    61,
      62,    63,    64,    65,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    60,    20,    94,    95,   132,    12,    31,     1,     2,
       3,    26,    87,    27,    28,    24,    25,   111,    13,    83,
      84,   133,    29,   115,    31,    15,    85,    37,    87,    96,
      97,   112,    17,    30,    20,     1,     2,     3,    26,   116,
      27,    28,   110,    17,    37,    87,     1,     2,     3,    29,
      48,    49,    50,    51,    52,    42,   117,    99,    53,    17,
       4,    43,   100,    54,    55,    48,    49,    50,    51,    52,
      68,   114,    45,    53,    69,    49,    50,    51,    52,     1,
       2,     3,   102,   103,   104,    91,    92,   127,   128,    44,
      74,    46,    47,    73,    70,    76,    81,    77,    78,    87,
      89,    79,    80,    14,   129,   130,    68,   113,   124,   125,
     136,   126,    82,   131,   118,   119,   120,   121,   122,   123,
      86,   135,    75
};

static const yytype_uint8 yycheck[] =
{
      11,    28,    12,    10,    11,     7,    25,    17,     3,     4,
       5,     6,    15,     8,     9,    23,    24,    10,     0,    46,
      47,    23,    17,    26,    34,    17,    53,    17,    15,    36,
      37,    24,    27,    28,    44,     3,     4,     5,     6,    26,
       8,     9,    69,    27,    34,    15,     3,     4,     5,    17,
      17,    18,    19,    20,    21,    17,    26,    30,    25,    27,
      17,    26,    35,    30,    31,    17,    18,    19,    20,    21,
      25,    81,    17,    25,    29,    18,    19,    20,    21,     3,
       4,     5,    32,    33,    34,    12,    13,   112,   113,    24,
      28,    25,    25,    23,    17,    23,    16,    23,    23,    15,
      14,    23,    23,     7,   115,   116,    25,    24,    26,    24,
      23,   111,    44,   125,    88,    90,    93,    98,   101,   105,
      59,   132,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    17,    39,    40,    41,    42,    45,
      47,    48,    25,     0,    40,    17,    46,    27,    52,    53,
      42,    49,    50,    51,    23,    24,     6,     8,     9,    17,
      28,    42,    53,    54,    55,    56,    59,    60,    64,    65,
      66,    68,    17,    26,    24,    17,    25,    25,    17,    18,
      19,    20,    21,    25,    30,    31,    43,    44,    60,    69,
      76,    77,    78,    79,    80,    81,    82,    83,    25,    29,
      17,    57,    58,    23,    28,    54,    23,    23,    23,    23,
      23,    16,    51,    76,    76,    76,    83,    15,    75,    14,
      74,    12,    13,    73,    10,    11,    36,    37,    72,    30,
      35,    71,    32,    33,    34,    70,    61,    62,    63,    76,
      76,    10,    24,    24,    42,    26,    26,    26,    77,    78,
      79,    80,    81,    82,    26,    24,    43,    57,    57,    53,
      53,    62,     7,    23,    67,    53,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    43,    44,    44,    44,    45,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    57,    57,    58,    59,    60,    61,    61,    62,
      62,    63,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    74,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     2,     6,     1,     0,     3,     1,     2,     1,     3,
       2,     2,     1,     2,     2,     2,     1,     2,     2,     2,
       3,     3,     1,     1,     3,     3,     4,     1,     0,     3,
       1,     1,     2,     1,     2,     6,     3,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* programa: array  */
#line 89 "parser.y"
                              { 
                            arvore = (yyvsp[0].no); 
                            }
#line 1524 "parser.tab.c"
    break;

  case 3: /* programa: %empty  */
#line 92 "parser.y"
                          { 
                            arvore = NULL; 
                            }
#line 1532 "parser.tab.c"
    break;

  case 4: /* array: element array  */
#line 97 "parser.y"
                                      {
                            if((yyvsp[0].no) == NULL){
                                (yyval.no) = (yyvsp[-1].no);
                            } else{
                                if((yyvsp[-1].no) != NULL){
                                    adicionarFilho((yyvsp[0].no), (yyvsp[-1].no));                                   
                                }
                                (yyval.no) = (yyvsp[0].no);
                            }
                        }
#line 1547 "parser.tab.c"
    break;

  case 5: /* array: element  */
#line 108 "parser.y"
                                 {
                            if((yyvsp[0].no) == NULL){
                                (yyval.no) = (yyvsp[0].no);
                            } else{
                                (yyval.no) = NULL;
                            }
                        }
#line 1559 "parser.tab.c"
    break;

  case 6: /* element: function  */
#line 116 "parser.y"
                                 {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1567 "parser.tab.c"
    break;

  case 7: /* element: global  */
#line 119 "parser.y"
                               {
                            (yyval.no) = NULL;
                        }
#line 1575 "parser.tab.c"
    break;

  case 11: /* literal: TK_LIT_INT  */
#line 132 "parser.y"
                                   {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
#line 1583 "parser.tab.c"
    break;

  case 12: /* literal: TK_LIT_FLOAT  */
#line 135 "parser.y"
                                       {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
#line 1591 "parser.tab.c"
    break;

  case 13: /* literal: TK_LIT_TRUE  */
#line 138 "parser.y"
                                      {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
#line 1599 "parser.tab.c"
    break;

  case 14: /* literal: TK_LIT_FALSE  */
#line 141 "parser.y"
                                      {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
#line 1607 "parser.tab.c"
    break;

  case 15: /* operando: TK_IDENTIFICADOR  */
#line 147 "parser.y"
                                         {
                            (yyval.no) = criarNoTipoLexico((yyvsp[0].valor_lexico));
                        }
#line 1615 "parser.tab.c"
    break;

  case 16: /* operando: literal  */
#line 150 "parser.y"
                                  {
                            (yyval.no) = criarNoTipoLexico((yyvsp[0].valor_lexico));
                        }
#line 1623 "parser.tab.c"
    break;

  case 17: /* operando: function_call  */
#line 153 "parser.y"
                                        {
                            (yyval.no) = NULL;
                        }
#line 1631 "parser.tab.c"
    break;

  case 21: /* function: header body  */
#line 170 "parser.y"
                                {
                        (yyval.no) = (yyvsp[-1].no);
                        adicionarFilho((yyval.no), (yyvsp[0].no));
                    }
#line 1640 "parser.tab.c"
    break;

  case 22: /* header: TK_IDENTIFICADOR '(' param_list ')' TK_OC_MAP type  */
#line 177 "parser.y"
                                                                       {
                        (yyval.no) = criarNoTipoLexico((yyvsp[-5].valor_lexico));
                    }
#line 1648 "parser.tab.c"
    break;

  case 28: /* body: commands_block  */
#line 192 "parser.y"
                                   {
                        (yyval.no) = (yyvsp[0].no);
                    }
#line 1656 "parser.tab.c"
    break;

  case 29: /* commands_block: '{' simple_command '}'  */
#line 200 "parser.y"
                                           {
                        (yyval.no) = (yyvsp[-1].no);
                    }
#line 1664 "parser.tab.c"
    break;

  case 30: /* commands_block: '{' '}'  */
#line 203 "parser.y"
                              {
                        (yyval.no) = NULL;
                    }
#line 1672 "parser.tab.c"
    break;

  case 31: /* simple_command: command_list simple_command  */
#line 209 "parser.y"
                                                {
                        if((yyvsp[-1].no) == NULL) 
                        { 
                            (yyval.no) = (yyvsp[0].no); 
                        }
                        else 
                        { 
                            if((yyvsp[0].no) != NULL) 
                            {
                                if(verificaValor((yyvsp[-1].no), "<=") == 1) 
                                { 
                                    // if it is <=. Here only attr can be <=
                                    No *folha = (yyvsp[-1].no);
                                    while(folha->n_filhos == 3)
                                        folha = folha->filhos[2];
                                    adicionarFilho(folha, (yyvsp[0].no));
                                    //$$ = leaf_attr; point that started secondary recursion must turn into $$ (previous cmd_list in the recursion)
                                }
                            else 
                            {
                                adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                                //$$ = $2;
                            } 
                            (yyval.no) = (yyvsp[-1].no);
                            } 
                            else 
                            { 
                                (yyval.no) = (yyvsp[-1].no); 
                            } 
                        } 
                    }
#line 1708 "parser.tab.c"
    break;

  case 32: /* simple_command: command_list  */
#line 240 "parser.y"
                                   {
                        if((yyvsp[0].no) != NULL)
                        {
                            (yyval.no) = (yyvsp[0].no);
                        } else
                        {
                            (yyval.no) = NULL;
                        }
                    }
#line 1722 "parser.tab.c"
    break;

  case 33: /* command_list: commands_block ';'  */
#line 252 "parser.y"
                                           {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1730 "parser.tab.c"
    break;

  case 34: /* command_list: local_var_command ';'  */
#line 255 "parser.y"
                                                {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1738 "parser.tab.c"
    break;

  case 35: /* command_list: set_command ';'  */
#line 258 "parser.y"
                                           {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1746 "parser.tab.c"
    break;

  case 36: /* command_list: flow_control_command  */
#line 261 "parser.y"
                                               {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1754 "parser.tab.c"
    break;

  case 37: /* command_list: return_command ';'  */
#line 264 "parser.y"
                                             {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1762 "parser.tab.c"
    break;

  case 38: /* command_list: function_call ';'  */
#line 267 "parser.y"
                                            {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1770 "parser.tab.c"
    break;

  case 39: /* local_var_command: type local_vars_list  */
#line 274 "parser.y"
                                             {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1778 "parser.tab.c"
    break;

  case 40: /* local_vars_list: TK_IDENTIFICADOR ',' local_vars_list  */
#line 280 "parser.y"
                                                             {
                            if((yyvsp[0].no) == NULL){
                                (yyval.no) = NULL;
                            } else{
                                (yyval.no) = (yyvsp[0].no);
                            }
                        }
#line 1790 "parser.tab.c"
    break;

  case 41: /* local_vars_list: local_var_list_complement ',' local_vars_list  */
#line 287 "parser.y"
                                                                        {
                            adicionarFilho((yyvsp[-2].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-2].no);
                        }
#line 1799 "parser.tab.c"
    break;

  case 42: /* local_vars_list: TK_IDENTIFICADOR  */
#line 291 "parser.y"
                                           {
                            (yyval.no) = NULL;
                        }
#line 1807 "parser.tab.c"
    break;

  case 43: /* local_vars_list: local_var_list_complement  */
#line 294 "parser.y"
                                                    {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1815 "parser.tab.c"
    break;

  case 44: /* local_var_list_complement: TK_IDENTIFICADOR TK_OC_LE literal  */
#line 300 "parser.y"
                                                          {
                            (yyval.no) = criarNo("<=");
                            adicionarFilho((yyval.no), criarNoTipoLexico((yyvsp[-2].valor_lexico)));
                            adicionarFilho((yyval.no), criarNoTipoLexico((yyvsp[0].valor_lexico)));
                        }
#line 1825 "parser.tab.c"
    break;

  case 45: /* set_command: TK_IDENTIFICADOR '=' expr  */
#line 308 "parser.y"
                                                  {
                            (yyval.no) = criarNo("=");
                            adicionarFilho((yyval.no), criarNoTipoLexico((yyvsp[-2].valor_lexico)));
                            adicionarFilho((yyval.no), (yyvsp[0].no));
                        }
#line 1835 "parser.tab.c"
    break;

  case 46: /* function_call: TK_IDENTIFICADOR '(' args_list ')'  */
#line 316 "parser.y"
                                                           {
                            (yyval.no) = criarNoTipoLexico((yyvsp[-3].valor_lexico));
                            atualizarValor((yyval.no));
                            adicionarFilho((yyval.no), (yyvsp[-1].no));
                        }
#line 1845 "parser.tab.c"
    break;

  case 47: /* args_list: args  */
#line 325 "parser.y"
                            { 
                            (yyval.no) = (yyvsp[0].no); 
                        }
#line 1853 "parser.tab.c"
    break;

  case 48: /* args_list: %empty  */
#line 328 "parser.y"
                                  {
                             (yyval.no) = NULL;
                        }
#line 1861 "parser.tab.c"
    break;

  case 49: /* args: arg ',' args  */
#line 334 "parser.y"
                                     {
                            adicionarFilho((yyvsp[-2].no), (yyvsp[0].no)); 
                            (yyval.no) = (yyvsp[-2].no); 
                        }
#line 1870 "parser.tab.c"
    break;

  case 50: /* args: arg  */
#line 338 "parser.y"
                                          {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1878 "parser.tab.c"
    break;

  case 51: /* arg: expr  */
#line 344 "parser.y"
                             {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 1886 "parser.tab.c"
    break;

  case 52: /* return_command: TK_PR_RETURN expr  */
#line 350 "parser.y"
                                          {
                            (yyval.no) = criarNo("return");
                            adicionarFilho((yyval.no), (yyvsp[0].no));
                        }
#line 1895 "parser.tab.c"
    break;

  case 55: /* condicional: TK_PR_IF '(' expr ')' commands_block condicional_complement  */
#line 362 "parser.y"
                                                                                    {
                            (yyval.no) = criarNo("if");
                            adicionarFilho((yyval.no), (yyvsp[-3].no));
                            adicionarFilho((yyval.no), (yyvsp[-1].no));
                            adicionarFilho((yyval.no), (yyvsp[0].no));
                            if((yyvsp[0].no) != NULL){
                                atualizarValor((yyval.no));
                            }
                        }
#line 1909 "parser.tab.c"
    break;

  case 56: /* condicional_complement: TK_PR_ELSE commands_block ';'  */
#line 375 "parser.y"
                                                      {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 1917 "parser.tab.c"
    break;

  case 57: /* condicional_complement: ';'  */
#line 378 "parser.y"
                              {
                            (yyval.no) = NULL;
                        }
#line 1925 "parser.tab.c"
    break;

  case 58: /* iterative: TK_PR_WHILE '(' expr ')' commands_block  */
#line 385 "parser.y"
                                                                {
                            (yyval.no) = criarNo("iterative");
                            adicionarFilho((yyval.no), (yyvsp[-2].no));
                            adicionarFilho((yyval.no), (yyvsp[0].no));
                        }
#line 1935 "parser.tab.c"
    break;

  case 59: /* opG0: '-'  */
#line 393 "parser.y"
                            {
                            (yyval.no) = criarNo("-");
                        }
#line 1943 "parser.tab.c"
    break;

  case 60: /* opG0: '!'  */
#line 396 "parser.y"
                              {
                            (yyval.no) = criarNo("!");
                        }
#line 1951 "parser.tab.c"
    break;

  case 61: /* opG1: '*'  */
#line 402 "parser.y"
                            {
                            (yyval.no) = criarNo("*");
                        }
#line 1959 "parser.tab.c"
    break;

  case 62: /* opG1: '/'  */
#line 405 "parser.y"
                              {
                            (yyval.no) = criarNo("/");
                        }
#line 1967 "parser.tab.c"
    break;

  case 63: /* opG1: '%'  */
#line 408 "parser.y"
                              {
                            (yyval.no) = criarNo("%");
                        }
#line 1975 "parser.tab.c"
    break;

  case 64: /* opG2: '+'  */
#line 414 "parser.y"
                            {
                            (yyval.no) = criarNo("+");
                        }
#line 1983 "parser.tab.c"
    break;

  case 65: /* opG2: '-'  */
#line 417 "parser.y"
                              {
                            (yyval.no) = criarNo("-");
                        }
#line 1991 "parser.tab.c"
    break;

  case 66: /* opG3: '<'  */
#line 423 "parser.y"
                            {
                            (yyval.no) = criarNo("<");
                        }
#line 1999 "parser.tab.c"
    break;

  case 67: /* opG3: '>'  */
#line 426 "parser.y"
                              {
                            (yyval.no) = criarNo(">");
                        }
#line 2007 "parser.tab.c"
    break;

  case 68: /* opG3: TK_OC_LE  */
#line 429 "parser.y"
                                   {
                            (yyval.no) = criarNo("<=");
                        }
#line 2015 "parser.tab.c"
    break;

  case 69: /* opG3: TK_OC_GE  */
#line 432 "parser.y"
                                   {
                            (yyval.no) = criarNo(">=");
                        }
#line 2023 "parser.tab.c"
    break;

  case 70: /* opG4: TK_OC_EQ  */
#line 438 "parser.y"
                                 {
                            (yyval.no) = criarNo("==");
                        }
#line 2031 "parser.tab.c"
    break;

  case 71: /* opG4: TK_OC_NE  */
#line 441 "parser.y"
                                   {
                            (yyval.no) = criarNo("!=");
                        }
#line 2039 "parser.tab.c"
    break;

  case 72: /* opAnd: TK_OC_AND  */
#line 447 "parser.y"
                                  {
                            (yyval.no) = criarNo("&");
                        }
#line 2047 "parser.tab.c"
    break;

  case 73: /* opOr: TK_OC_OR  */
#line 453 "parser.y"
                                 {
                            (yyval.no) = criarNo("|");
                        }
#line 2055 "parser.tab.c"
    break;

  case 74: /* expr: expr1  */
#line 459 "parser.y"
                              {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2063 "parser.tab.c"
    break;

  case 75: /* expr: expr opOr expr1  */
#line 462 "parser.y"
                                          {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2073 "parser.tab.c"
    break;

  case 76: /* expr1: expr2  */
#line 470 "parser.y"
                              {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2081 "parser.tab.c"
    break;

  case 77: /* expr1: expr1 opAnd expr2  */
#line 473 "parser.y"
                                            {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2091 "parser.tab.c"
    break;

  case 78: /* expr2: expr3  */
#line 481 "parser.y"
                              {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2099 "parser.tab.c"
    break;

  case 79: /* expr2: expr2 opG4 expr3  */
#line 484 "parser.y"
                                           {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2109 "parser.tab.c"
    break;

  case 80: /* expr3: expr4  */
#line 492 "parser.y"
                             {
                        (yyval.no) = (yyvsp[0].no);
                       }
#line 2117 "parser.tab.c"
    break;

  case 81: /* expr3: expr3 opG3 expr4  */
#line 495 "parser.y"
                                          {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                       }
#line 2127 "parser.tab.c"
    break;

  case 82: /* expr4: expr5  */
#line 503 "parser.y"
                             {
                        (yyval.no) = (yyvsp[0].no);
                       }
#line 2135 "parser.tab.c"
    break;

  case 83: /* expr4: expr4 opG2 expr5  */
#line 506 "parser.y"
                                          {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                       }
#line 2145 "parser.tab.c"
    break;

  case 84: /* expr5: expr6  */
#line 514 "parser.y"
                              {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2153 "parser.tab.c"
    break;

  case 85: /* expr5: expr5 opG1 expr6  */
#line 517 "parser.y"
                                           {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[-2].no));
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2163 "parser.tab.c"
    break;

  case 86: /* expr6: expr7  */
#line 525 "parser.y"
                              {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2171 "parser.tab.c"
    break;

  case 87: /* expr6: opG0 expr7  */
#line 528 "parser.y"
                                     {
                            adicionarFilho((yyvsp[-1].no), (yyvsp[0].no));
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2180 "parser.tab.c"
    break;

  case 88: /* expr7: operando  */
#line 535 "parser.y"
                                 {
                            (yyval.no) = (yyvsp[0].no);
                        }
#line 2188 "parser.tab.c"
    break;

  case 89: /* expr7: '(' expr ')'  */
#line 538 "parser.y"
                                       {
                            (yyval.no) = (yyvsp[-1].no);
                        }
#line 2196 "parser.tab.c"
    break;


#line 2200 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 543 "parser.y"


void yyerror(char const *s){
	printf("ERROR: %s [linha: %d token \"%s\"] \n\n", s,get_line_number(), yytext);
}
