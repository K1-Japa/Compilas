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
#line 1 "syntax.y"

    #include <iostream>
    #include <unistd.h>
    #include <vector>
    #include <string>
    #include "lex.yy.c"

    using namespace std;

    int yylex();

    void yyerror(const char *s);

    struct node* makeNode(struct node *left, struct node *right, const string& token);
    void putType();
    string checkType(const string&, const string&);
    char* getType(const char*);
    void checkStatement(char*);
    int search(char*);
    void checkReturnType(char*);
    void printtree(struct node* tree);
    void printInorder(struct node*, FILE*);

    struct node *root;

    struct node {
        string token;
        node *left;
        node *right;
    };


    struct data {
        char* nameId;
        char* dataType;
        char* type;
        int numLine;
    } Table[50];

    string type;
    extern int lines;
    int numError = 0;
    int label = 0;
    int count = 0;
    char errors[12][100];

    string reservedWords[12][12] = {"import", "int", "float", "char", "if", "else", "for", "print", "scanf", "main", "void", "return"};


#line 121 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tk_void = 258,                 /* tk_void  */
    tk_int = 259,                  /* tk_int  */
    tk_float = 260,                /* tk_float  */
    tk_char = 261,                 /* tk_char  */
    tk_string = 262,               /* tk_string  */
    tk_typeInt = 263,              /* tk_typeInt  */
    tk_typeFloat = 264,            /* tk_typeFloat  */
    tk_typeChar = 265,             /* tk_typeChar  */
    tk_typeString = 266,           /* tk_typeString  */
    tk_vet = 267,                  /* tk_vet  */
    tk_if = 268,                   /* tk_if  */
    tk_for = 269,                  /* tk_for  */
    tk_print = 270,                /* tk_print  */
    tk_scanf = 271,                /* tk_scanf  */
    tk_main = 272,                 /* tk_main  */
    tk_atrib = 273,                /* tk_atrib  */
    tk_opMath = 274,               /* tk_opMath  */
    tk_opLog = 275,                /* tk_opLog  */
    tk_openParen = 276,            /* tk_openParen  */
    tk_closeParen = 277,           /* tk_closeParen  */
    tk_openBracket = 278,          /* tk_openBracket  */
    tk_closeBracket = 279,         /* tk_closeBracket  */
    tk_openCurly = 280,            /* tk_openCurly  */
    tk_closeCurly = 281,           /* tk_closeCurly  */
    tk_colon = 282,                /* tk_colon  */
    tk_semicolon = 283,            /* tk_semicolon  */
    tk_comma = 284,                /* tk_comma  */
    tk_id = 285,                   /* tk_id  */
    tk_import = 286,               /* tk_import  */
    tk_true = 287,                 /* tk_true  */
    tk_false = 288,                /* tk_false  */
    tk_else = 289,                 /* tk_else  */
    tk_return = 290                /* tk_return  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tk_void 258
#define tk_int 259
#define tk_float 260
#define tk_char 261
#define tk_string 262
#define tk_typeInt 263
#define tk_typeFloat 264
#define tk_typeChar 265
#define tk_typeString 266
#define tk_vet 267
#define tk_if 268
#define tk_for 269
#define tk_print 270
#define tk_scanf 271
#define tk_main 272
#define tk_atrib 273
#define tk_opMath 274
#define tk_opLog 275
#define tk_openParen 276
#define tk_closeParen 277
#define tk_openBracket 278
#define tk_closeBracket 279
#define tk_openCurly 280
#define tk_closeCurly 281
#define tk_colon 282
#define tk_semicolon 283
#define tk_comma 284
#define tk_id 285
#define tk_import 286
#define tk_true 287
#define tk_false 288
#define tk_else 289
#define tk_return 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "syntax.y"

        struct varName{
            char name[100];
            struct node* nod;
        } ObjNod;

        struct varName2{
            char name[100];
            struct node* nod;
            char type[5];
        } ObjNod2;
    

#line 258 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tk_void = 3,                    /* tk_void  */
  YYSYMBOL_tk_int = 4,                     /* tk_int  */
  YYSYMBOL_tk_float = 5,                   /* tk_float  */
  YYSYMBOL_tk_char = 6,                    /* tk_char  */
  YYSYMBOL_tk_string = 7,                  /* tk_string  */
  YYSYMBOL_tk_typeInt = 8,                 /* tk_typeInt  */
  YYSYMBOL_tk_typeFloat = 9,               /* tk_typeFloat  */
  YYSYMBOL_tk_typeChar = 10,               /* tk_typeChar  */
  YYSYMBOL_tk_typeString = 11,             /* tk_typeString  */
  YYSYMBOL_tk_vet = 12,                    /* tk_vet  */
  YYSYMBOL_tk_if = 13,                     /* tk_if  */
  YYSYMBOL_tk_for = 14,                    /* tk_for  */
  YYSYMBOL_tk_print = 15,                  /* tk_print  */
  YYSYMBOL_tk_scanf = 16,                  /* tk_scanf  */
  YYSYMBOL_tk_main = 17,                   /* tk_main  */
  YYSYMBOL_tk_atrib = 18,                  /* tk_atrib  */
  YYSYMBOL_tk_opMath = 19,                 /* tk_opMath  */
  YYSYMBOL_tk_opLog = 20,                  /* tk_opLog  */
  YYSYMBOL_tk_openParen = 21,              /* tk_openParen  */
  YYSYMBOL_tk_closeParen = 22,             /* tk_closeParen  */
  YYSYMBOL_tk_openBracket = 23,            /* tk_openBracket  */
  YYSYMBOL_tk_closeBracket = 24,           /* tk_closeBracket  */
  YYSYMBOL_tk_openCurly = 25,              /* tk_openCurly  */
  YYSYMBOL_tk_closeCurly = 26,             /* tk_closeCurly  */
  YYSYMBOL_tk_colon = 27,                  /* tk_colon  */
  YYSYMBOL_tk_semicolon = 28,              /* tk_semicolon  */
  YYSYMBOL_tk_comma = 29,                  /* tk_comma  */
  YYSYMBOL_tk_id = 30,                     /* tk_id  */
  YYSYMBOL_tk_import = 31,                 /* tk_import  */
  YYSYMBOL_tk_true = 32,                   /* tk_true  */
  YYSYMBOL_tk_false = 33,                  /* tk_false  */
  YYSYMBOL_tk_else = 34,                   /* tk_else  */
  YYSYMBOL_tk_return = 35,                 /* tk_return  */
  YYSYMBOL_36_ = 36,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_menu = 38,                      /* menu  */
  YYSYMBOL_imports = 39,                   /* imports  */
  YYSYMBOL_listFunctions = 40,             /* listFunctions  */
  YYSYMBOL_statementFunction = 41,         /* statementFunction  */
  YYSYMBOL_nameFunction = 42,              /* nameFunction  */
  YYSYMBOL_listParameters = 43,            /* listParameters  */
  YYSYMBOL_main = 44,                      /* main  */
  YYSYMBOL_main_start = 45,                /* main_start  */
  YYSYMBOL_dataType = 46,                  /* dataType  */
  YYSYMBOL_code = 47,                      /* code  */
  YYSYMBOL_print = 48,                     /* print  */
  YYSYMBOL_printString = 49,               /* printString  */
  YYSYMBOL_args = 50,                      /* args  */
  YYSYMBOL_functionCall = 51,              /* functionCall  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_else = 53,                      /* else  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_init = 55,                      /* init  */
  YYSYMBOL_array = 56,                     /* array  */
  YYSYMBOL_value = 57,                     /* value  */
  YYSYMBOL_return = 58,                    /* return  */
  YYSYMBOL_expression = 59                 /* expression  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    78,    82,    87,    90,    96,    99,   104,
     109,   112,   115,   120,   125,   130,   133,   136,   139,   142,
     147,   150,   153,   156,   159,   163,   168,   171,   174,   177,
     181,   186,   195,   200,   203,   208,   211,   214,   219,   222,
     227,   230,   233,   236,   241,   244,   249,   263,   277,   282,
     287,   294,   300,   305,   310,   315,   321,   327,   332,   338,
     354
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
  "\"end of file\"", "error", "\"invalid token\"", "tk_void", "tk_int",
  "tk_float", "tk_char", "tk_string", "tk_typeInt", "tk_typeFloat",
  "tk_typeChar", "tk_typeString", "tk_vet", "tk_if", "tk_for", "tk_print",
  "tk_scanf", "tk_main", "tk_atrib", "tk_opMath", "tk_opLog",
  "tk_openParen", "tk_closeParen", "tk_openBracket", "tk_closeBracket",
  "tk_openCurly", "tk_closeCurly", "tk_colon", "tk_semicolon", "tk_comma",
  "tk_id", "tk_import", "tk_true", "tk_false", "tk_else", "tk_return",
  "'&'", "$accept", "menu", "imports", "listFunctions",
  "statementFunction", "nameFunction", "listParameters", "main",
  "main_start", "dataType", "code", "print", "printString", "args",
  "functionCall", "condition", "else", "statement", "init", "array",
  "value", "return", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,    16,    38,   -80,   -80,   -80,   -80,   -80,   -80,     1,
      81,   -80,     8,   -80,    14,    10,    36,   -80,   203,   203,
      30,    47,    50,    52,    53,    64,    65,   -15,     2,    15,
      43,    59,    60,    78,    15,    76,    81,    71,    32,   111,
      95,    96,    49,    12,    74,    78,    84,    86,    87,    49,
      89,    90,    99,    83,   -80,   -80,   -80,    49,   -80,    98,
     -80,   -12,    85,   -80,   -80,   -80,   -80,   110,   -80,   -80,
     112,   117,   124,   116,   129,   142,   136,   -80,   147,   -80,
     -80,    34,   145,   -80,    32,   111,   162,   143,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    81,   -80,    49,   149,    49,
      32,   140,   -80,   139,    49,   -80,   161,   173,   175,   171,
     169,   -80,   172,    33,   203,   -80,   176,   174,   177,   147,
     -80,   184,   185,    32,   165,   -80,   -80,    67,   111,   193,
     -80,   203,   192,   191,   188,   201,   196,   137,   111,   204,
     200,   -80,   202,   -80,   188,   206,   207,   203,   203,   -80,
     205,   -80,   146,   170,   203,   -80,   -80,   179,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    19,    15,    16,    17,    18,     0,
       2,     5,     0,     8,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,    50,    58,     0,    12,     0,    43,     0,
       0,     0,     0,    37,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    21,    20,     0,    47,     0,
      14,     0,     0,     3,    52,    53,    54,    55,    41,    42,
       0,     0,     0,     0,    33,     0,     0,    60,    48,    38,
      35,     0,     0,    46,    43,     0,     0,     0,    28,    27,
      26,     7,    49,    13,     9,     0,    10,     0,     0,     0,
      43,    37,    32,     0,     0,    39,     0,     0,     0,     0,
       0,    57,     0,     0,     0,    40,     0,    34,     0,    59,
      36,     0,     0,    43,     0,    11,    56,     0,     0,     0,
      51,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,    24,     0,    23,    45,     0,     0,     0,     0,    30,
       0,    29,     0,     0,     0,    44,    25,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   219,   -80,   -80,   -80,   -80,    -1,
     -19,   -21,   -80,   130,   -14,   -79,    88,   -27,   189,   -80,
     -38,   208,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    12,    61,    13,    14,    28,
      29,    30,    75,    81,    31,    70,   141,    32,    58,    33,
      71,    53,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    15,    52,    42,    77,   108,    43,    52,    50,    15,
      94,    87,    73,    50,    44,    51,     3,    95,     4,    92,
      51,   116,    16,     5,     6,     7,     8,    20,    46,    47,
      25,    48,    45,    18,    79,    62,    64,    65,    66,    19,
      21,     4,    80,    22,   132,    27,     5,     6,     7,     8,
      49,    35,   104,    64,    65,    66,   105,   126,   109,    77,
     113,   115,    67,   106,    68,    69,    77,   119,    36,     9,
       4,    54,    37,    38,    39,     5,     6,     7,     8,    67,
      46,    47,    25,    48,     4,    40,    41,    55,    56,     5,
       6,     7,     8,   134,   112,   127,    57,    27,    60,    63,
      52,   135,    74,    76,    82,    84,    50,    85,    86,    91,
      52,   145,   137,    51,     4,    96,    50,    88,    89,     5,
       6,     7,     8,    51,    93,    52,    52,    90,   152,   153,
      52,    50,    50,    97,    98,   157,    50,    99,    51,    51,
       4,    72,    42,    51,   100,     5,     6,     7,     8,     4,
      46,    47,    25,    48,     5,     6,     7,     8,   101,    46,
      47,    25,    48,   144,   102,   103,   104,    27,   107,   110,
      80,   111,   155,     4,   114,   118,    27,   121,     5,     6,
       7,     8,     4,    46,    47,    25,    48,     5,     6,     7,
       8,   120,    46,    47,    25,    48,   156,   122,   124,   123,
      27,   133,   125,   106,   128,   158,     4,   129,   130,    27,
     131,     5,     6,     7,     8,   136,    23,    24,    25,    26,
     138,   139,   140,   142,   143,   147,   146,   148,   150,    17,
     154,   117,   149,    27,    83,   151,     0,     0,     0,     0,
       0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      19,     2,    29,    18,    42,    84,    21,    34,    29,    10,
      22,    49,    39,    34,    12,    29,     0,    29,     3,    57,
      34,   100,    21,     8,     9,    10,    11,    17,    13,    14,
      15,    16,    30,    25,    22,    36,     4,     5,     6,    25,
      30,     3,    30,     7,   123,    30,     8,     9,    10,    11,
      35,    21,    19,     4,     5,     6,    22,    24,    85,    97,
      97,    99,    30,    29,    32,    33,   104,   104,    21,    31,
       3,    28,    22,    21,    21,     8,     9,    10,    11,    30,
      13,    14,    15,    16,     3,    21,    21,    28,    28,     8,
       9,    10,    11,    26,    95,   114,    18,    30,    22,    28,
     127,   128,     7,     7,    30,    21,   127,    21,    21,    26,
     137,   138,   131,   127,     3,    30,   137,    28,    28,     8,
       9,    10,    11,   137,    26,   152,   153,    28,   147,   148,
     157,   152,   153,    23,    22,   154,   157,    20,   152,   153,
       3,    30,    18,   157,    28,     8,     9,    10,    11,     3,
      13,    14,    15,    16,     8,     9,    10,    11,    29,    13,
      14,    15,    16,    26,    22,    29,    19,    30,    23,     7,
      30,    28,    26,     3,    25,    36,    30,     4,     8,     9,
      10,    11,     3,    13,    14,    15,    16,     8,     9,    10,
      11,    30,    13,    14,    15,    16,    26,    22,    29,    28,
      30,    36,    30,    29,    28,    26,     3,    30,    24,    30,
      25,     8,     9,    10,    11,    22,    13,    14,    15,    16,
      28,    30,    34,    22,    28,    25,    22,    25,    22,    10,
      25,   101,   144,    30,    45,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     8,     9,    10,    11,    31,
      40,    41,    42,    44,    45,    46,    21,    41,    25,    25,
      17,    30,     7,    13,    14,    15,    16,    30,    46,    47,
      48,    51,    54,    56,    47,    21,    21,    22,    21,    21,
      21,    21,    18,    21,    12,    30,    13,    14,    16,    35,
      48,    51,    54,    58,    28,    28,    28,    18,    55,    58,
      22,    43,    46,    28,     4,     5,     6,    30,    32,    33,
      52,    57,    30,    54,     7,    49,     7,    57,    59,    22,
      30,    50,    30,    55,    21,    21,    21,    57,    28,    28,
      28,    26,    57,    26,    22,    29,    30,    23,    22,    20,
      28,    29,    22,    29,    19,    22,    29,    23,    52,    54,
       7,    28,    46,    59,    25,    57,    52,    50,    36,    59,
      30,     4,    22,    28,    29,    30,    24,    47,    28,    30,
      24,    25,    52,    36,    26,    54,    22,    47,    28,    30,
      34,    53,    22,    28,    26,    54,    22,    25,    25,    53,
      22,    28,    47,    47,    25,    26,    26,    47,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      43,    43,    43,    44,    45,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     6,     0,     1,     2,     5,     1,     5,
       2,     4,     0,     5,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     8,     8,    11,     3,     3,     3,     9,
       9,    12,     4,     1,     3,     1,     3,     0,     3,     4,
       3,     1,     1,     0,     4,     0,     3,     2,     3,     2,
       0,     6,     1,     1,     1,     1,     4,     3,     0,     3,
       1
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
  case 2: /* menu: imports listFunctions  */
#line 72 "syntax.y"
                              {
            (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, (yyvsp[0].ObjNod).nod, "menu");
            root = (yyval.ObjNod).nod;
        }
#line 1414 "y.tab.c"
    break;

  case 3: /* imports: imports tk_import tk_openParen tk_string tk_closeParen tk_semicolon  */
#line 78 "syntax.y"
                                                                           {
            (yyvsp[-4].ObjNod).nod =  makeNode(NULL, NULL, (yyvsp[-4].ObjNod).name);
            (yyval.ObjNod).nod =  makeNode((yyvsp[-5].ObjNod).nod, (yyvsp[-4].ObjNod).nod, "imports");
        }
#line 1423 "y.tab.c"
    break;

  case 4: /* imports: %empty  */
#line 82 "syntax.y"
         {
            (yyval.ObjNod).nod = NULL;
        }
#line 1431 "y.tab.c"
    break;

  case 5: /* listFunctions: statementFunction  */
#line 87 "syntax.y"
                          {
            (yyval.ObjNod).nod = (yyvsp[0].ObjNod).nod;
        }
#line 1439 "y.tab.c"
    break;

  case 6: /* listFunctions: listFunctions statementFunction  */
#line 90 "syntax.y"
                                          {
            (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, (yyvsp[0].ObjNod).nod, "listFunctions");
        }
#line 1447 "y.tab.c"
    break;

  case 7: /* statementFunction: nameFunction tk_openCurly code return tk_closeCurly  */
#line 96 "syntax.y"
                                                            {
            (yyval.ObjNod).nod = makeNode((yyvsp[-4].ObjNod).nod, (yyvsp[-2].ObjNod).nod, "statementFunction");
        }
#line 1455 "y.tab.c"
    break;

  case 8: /* statementFunction: main  */
#line 99 "syntax.y"
               {
            (yyval.ObjNod).nod = (yyvsp[0].ObjNod).nod;
        }
#line 1463 "y.tab.c"
    break;

  case 9: /* nameFunction: dataType tk_id tk_openParen listParameters tk_closeParen  */
#line 104 "syntax.y"
                                                                 {
            (yyval.ObjNod).nod = makeNode((yyvsp[-4].ObjNod).nod, (yyvsp[-1].ObjNod).nod, (yyvsp[-3].ObjNod).name);
        }
#line 1471 "y.tab.c"
    break;

  case 10: /* listParameters: dataType tk_id  */
#line 109 "syntax.y"
                       {

        }
#line 1479 "y.tab.c"
    break;

  case 11: /* listParameters: listParameters tk_comma dataType tk_id  */
#line 112 "syntax.y"
                                                 {

        }
#line 1487 "y.tab.c"
    break;

  case 12: /* listParameters: %empty  */
#line 115 "syntax.y"
          {
            (yyval.ObjNod).nod = NULL;
        }
#line 1495 "y.tab.c"
    break;

  case 13: /* main: main_start tk_openCurly code return tk_closeCurly  */
#line 120 "syntax.y"
                                                          {
            (yyval.ObjNod).nod = makeNode((yyvsp[-4].ObjNod).nod, (yyvsp[-2].ObjNod).nod, "main");
        }
#line 1503 "y.tab.c"
    break;

  case 14: /* main_start: dataType tk_main tk_openParen tk_closeParen  */
#line 125 "syntax.y"
                                                   {

        }
#line 1511 "y.tab.c"
    break;

  case 15: /* dataType: tk_typeInt  */
#line 130 "syntax.y"
                  {
            putType();
        }
#line 1519 "y.tab.c"
    break;

  case 16: /* dataType: tk_typeFloat  */
#line 133 "syntax.y"
                     {
            putType();
        }
#line 1527 "y.tab.c"
    break;

  case 17: /* dataType: tk_typeChar  */
#line 136 "syntax.y"
                    {
            putType();
        }
#line 1535 "y.tab.c"
    break;

  case 18: /* dataType: tk_typeString  */
#line 139 "syntax.y"
                      { //remover tipo string
            putType();
        }
#line 1543 "y.tab.c"
    break;

  case 19: /* dataType: tk_void  */
#line 142 "syntax.y"
                {
            putType();
        }
#line 1551 "y.tab.c"
    break;

  case 20: /* code: statement tk_semicolon  */
#line 147 "syntax.y"
                              {
            (yyval.ObjNod).nod = (yyvsp[-1].ObjNod).nod;
        }
#line 1559 "y.tab.c"
    break;

  case 21: /* code: functionCall tk_semicolon  */
#line 150 "syntax.y"
                                   {
            (yyval.ObjNod).nod = (yyvsp[-1].ObjNod).nod;
        }
#line 1567 "y.tab.c"
    break;

  case 22: /* code: print tk_semicolon  */
#line 153 "syntax.y"
                            {
            (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, (yyvsp[0].ObjNod).nod, "printFunction");
        }
#line 1575 "y.tab.c"
    break;

  case 23: /* code: tk_scanf tk_openParen tk_string tk_comma '&' tk_id tk_closeParen tk_semicolon  */
#line 156 "syntax.y"
                                                                                       {
            (yyval.ObjNod).nod = makeNode(NULL, NULL, "scan");
        }
#line 1583 "y.tab.c"
    break;

  case 24: /* code: tk_if tk_openParen condition tk_closeParen tk_openCurly code tk_closeCurly else  */
#line 159 "syntax.y"
                                                                                          {
            struct node *ifA = makeNode((yyvsp[-5].ObjNod).nod, (yyvsp[-2].ObjNod).nod, (yyvsp[-7].ObjNod).name);
            (yyval.ObjNod).nod = makeNode(ifA, (yyvsp[0].ObjNod).nod, "if-else");
        }
#line 1592 "y.tab.c"
    break;

  case 25: /* code: tk_for tk_openParen statement tk_semicolon condition tk_semicolon statement tk_closeParen tk_openCurly code tk_closeCurly  */
#line 163 "syntax.y"
                                                                                                                                    {
            struct node *forA = makeNode((yyvsp[-6].ObjNod).nod, (yyvsp[-4].ObjNod).nod, "for condition");
            struct node *forB = makeNode((yyvsp[-8].ObjNod).nod, forA, "for condition");
            (yyval.ObjNod).nod = makeNode(forB, (yyvsp[-1].ObjNod).nod, (yyvsp[-10].ObjNod).name);
        }
#line 1602 "y.tab.c"
    break;

  case 26: /* code: code statement tk_semicolon  */
#line 168 "syntax.y"
                                      {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[-1].ObjNod).nod, "code");
        }
#line 1610 "y.tab.c"
    break;

  case 27: /* code: code functionCall tk_semicolon  */
#line 171 "syntax.y"
                                         {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[-1].ObjNod).nod, "code");
        }
#line 1618 "y.tab.c"
    break;

  case 28: /* code: code print tk_semicolon  */
#line 174 "syntax.y"
                                  {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[-1].ObjNod).nod, "code");
        }
#line 1626 "y.tab.c"
    break;

  case 29: /* code: code tk_scanf tk_openParen tk_string tk_comma '&' tk_id tk_closeParen tk_semicolon  */
#line 177 "syntax.y"
                                                                                             {
            struct node* scanA = makeNode(NULL, NULL, "scan");
            (yyval.ObjNod).nod = makeNode((yyvsp[-8].ObjNod).nod, scanA, "code");
        }
#line 1635 "y.tab.c"
    break;

  case 30: /* code: code tk_if tk_openParen condition tk_closeParen tk_openCurly code tk_closeCurly else  */
#line 181 "syntax.y"
                                                                                               {
            struct node *ifA = makeNode((yyvsp[-5].ObjNod).nod, (yyvsp[-2].ObjNod).nod, (yyvsp[-6].ObjNod).name);
            struct node* ifelseA = makeNode(ifA, (yyvsp[0].ObjNod).nod, "if-else");
            (yyval.ObjNod).nod = makeNode((yyvsp[-8].ObjNod).nod, ifelseA, "code");
        }
#line 1645 "y.tab.c"
    break;

  case 31: /* code: code tk_for tk_openParen statement tk_semicolon condition tk_semicolon statement tk_closeParen tk_openCurly code tk_closeCurly  */
#line 186 "syntax.y"
                                                                                                                                         {
            struct node *forA = makeNode((yyvsp[-6].ObjNod).nod, (yyvsp[-4].ObjNod).nod, "for condition");
            struct node *forB = makeNode((yyvsp[-8].ObjNod).nod, forA, "for condition");
            struct node *forC = makeNode(forC, (yyvsp[-1].ObjNod).nod, (yyvsp[-9].ObjNod).name);
            (yyval.ObjNod).nod = makeNode((yyvsp[-11].ObjNod).nod, forC, "code");
        }
#line 1656 "y.tab.c"
    break;

  case 32: /* print: tk_print tk_openParen printString tk_closeParen  */
#line 195 "syntax.y"
                                                       {
            (yyval.ObjNod).nod = makeNode(NULL, NULL, "print");
        }
#line 1664 "y.tab.c"
    break;

  case 33: /* printString: tk_string  */
#line 200 "syntax.y"
                 {
            (yyval.ObjNod).nod = makeNode(NULL, NULL, "printString");
        }
#line 1672 "y.tab.c"
    break;

  case 34: /* printString: tk_string tk_comma args  */
#line 203 "syntax.y"
                                {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[0].ObjNod).nod, "args");
        }
#line 1680 "y.tab.c"
    break;

  case 35: /* args: tk_id  */
#line 208 "syntax.y"
             {
            (yyval.ObjNod).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod).name);
        }
#line 1688 "y.tab.c"
    break;

  case 36: /* args: args tk_comma tk_id  */
#line 211 "syntax.y"
                            {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[0].ObjNod).nod, (yyvsp[0].ObjNod).name);
        }
#line 1696 "y.tab.c"
    break;

  case 37: /* args: %empty  */
#line 214 "syntax.y"
         {
            (yyval.ObjNod).nod = NULL;
        }
#line 1704 "y.tab.c"
    break;

  case 38: /* functionCall: tk_id tk_openParen tk_closeParen  */
#line 219 "syntax.y"
                                         {
            (yyval.ObjNod).nod = makeNode(NULL, NULL, (yyvsp[-2].ObjNod).name);
        }
#line 1712 "y.tab.c"
    break;

  case 39: /* functionCall: tk_id tk_openParen args tk_closeParen  */
#line 222 "syntax.y"
                                                {
            (yyval.ObjNod).nod = makeNode(NULL, (yyvsp[-1].ObjNod).nod, (yyvsp[-3].ObjNod).name);
        }
#line 1720 "y.tab.c"
    break;

  case 40: /* condition: value tk_opLog value  */
#line 227 "syntax.y"
                             {
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod2).nod, (yyvsp[0].ObjNod2).nod, (yyvsp[-1].ObjNod).name);
        }
#line 1728 "y.tab.c"
    break;

  case 41: /* condition: tk_true  */
#line 230 "syntax.y"
                  {
            (yyval.ObjNod).nod = NULL;
        }
#line 1736 "y.tab.c"
    break;

  case 42: /* condition: tk_false  */
#line 233 "syntax.y"
                   {
            (yyval.ObjNod).nod = NULL;
        }
#line 1744 "y.tab.c"
    break;

  case 43: /* condition: %empty  */
#line 236 "syntax.y"
          {
            (yyval.ObjNod).nod = NULL;
        }
#line 1752 "y.tab.c"
    break;

  case 44: /* else: tk_else tk_openCurly code tk_closeCurly  */
#line 241 "syntax.y"
                                                {
            (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, NULL, (yyvsp[-3].ObjNod).name);
        }
#line 1760 "y.tab.c"
    break;

  case 45: /* else: %empty  */
#line 244 "syntax.y"
          {
            (yyval.ObjNod).nod = NULL;
        }
#line 1768 "y.tab.c"
    break;

  case 46: /* statement: dataType tk_id init  */
#line 249 "syntax.y"
                            {
            (yyvsp[-1].ObjNod).nod = makeNode(NULL, NULL, (yyvsp[-1].ObjNod).name);

            string ret = checkType((yyvsp[-2].ObjNod).name, (yyvsp[0].ObjNod2).type);
            
            if((ret == "equal") || (ret == "Null")){
                (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, (yyvsp[0].ObjNod2).nod, "statement");
            }
            else{
                struct node *t =  makeNode(NULL, (yyvsp[0].ObjNod2).nod, ret);

                (yyval.ObjNod).nod = makeNode((yyvsp[-1].ObjNod).nod, t, "statement");
            }
        }
#line 1787 "y.tab.c"
    break;

  case 47: /* statement: array init  */
#line 263 "syntax.y"
                     {
            (yyvsp[0].ObjNod2).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod2).name);

            string ret = checkType((yyvsp[-1].ObjNod).name, (yyvsp[0].ObjNod2).type);

            if((ret == "equal") || (ret == "Null")){
                (yyval.ObjNod).nod = makeNode((yyvsp[0].ObjNod2).nod, (yyvsp[0].ObjNod2).nod, "statement");
            }
            else{
                struct node *t =  makeNode(NULL, (yyvsp[0].ObjNod2).nod, ret);

                (yyval.ObjNod).nod = makeNode((yyvsp[0].ObjNod2).nod, t, "statement");
            }    
        }
#line 1806 "y.tab.c"
    break;

  case 48: /* statement: tk_id tk_atrib expression  */
#line 277 "syntax.y"
                                   {
            (yyvsp[-2].ObjNod).nod = makeNode(NULL, NULL, (yyvsp[-2].ObjNod).name);
        }
#line 1814 "y.tab.c"
    break;

  case 49: /* init: tk_atrib value  */
#line 282 "syntax.y"
                       {
            (yyval.ObjNod2).nod = (yyvsp[0].ObjNod2).nod;
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", (yyvsp[0].ObjNod2).type);
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod2).name);
        }
#line 1824 "y.tab.c"
    break;

  case 50: /* init: %empty  */
#line 287 "syntax.y"
          {
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", "null");
            (yyval.ObjNod2).nod = makeNode(NULL, NULL, "null");
            strcpy((yyval.ObjNod2).name, "null");
        }
#line 1834 "y.tab.c"
    break;

  case 51: /* array: dataType tk_vet tk_id tk_openBracket tk_int tk_closeBracket  */
#line 294 "syntax.y"
                                                                    {
            (yyvsp[-5].ObjNod).nod = makeNode(NULL, NULL, (yyvsp[-5].ObjNod).name);
            (yyval.ObjNod).nod = makeNode((yyvsp[-5].ObjNod).nod, (yyvsp[-3].ObjNod).nod, "array");
        }
#line 1843 "y.tab.c"
    break;

  case 52: /* value: tk_int  */
#line 300 "syntax.y"
               {
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod).name);
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", "int");
            (yyval.ObjNod2).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod).name);
        }
#line 1853 "y.tab.c"
    break;

  case 53: /* value: tk_float  */
#line 305 "syntax.y"
                   {
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod).name);
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", "float");
            (yyval.ObjNod2).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod).name);
        }
#line 1863 "y.tab.c"
    break;

  case 54: /* value: tk_char  */
#line 310 "syntax.y"
                  {
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod).name);
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", "char");
            (yyval.ObjNod2).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod).name);
        }
#line 1873 "y.tab.c"
    break;

  case 55: /* value: tk_id  */
#line 315 "syntax.y"
                {
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod).name);
            char* typeId = getType((yyvsp[0].ObjNod).name);
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", typeId);
            (yyval.ObjNod2).nod = makeNode(NULL, NULL, (yyvsp[0].ObjNod).name);
        }
#line 1884 "y.tab.c"
    break;

  case 56: /* value: tk_id tk_openBracket expression tk_closeBracket  */
#line 321 "syntax.y"
                                                          {
            checkStatement((yyvsp[-3].ObjNod).name);
            (yyval.ObjNod2).nod = makeNode((yyvsp[-3].ObjNod).nod, (yyvsp[-1].ObjNod2).nod, "Index Array Access");
        }
#line 1893 "y.tab.c"
    break;

  case 57: /* return: tk_return value tk_semicolon  */
#line 327 "syntax.y"
                                    {
            checkReturnType((yyvsp[-1].ObjNod2).name);
            (yyvsp[-2].ObjNod).nod = makeNode(NULL, NULL, "return");
            (yyval.ObjNod).nod = makeNode((yyvsp[-2].ObjNod).nod, (yyvsp[-1].ObjNod2).nod, "Return value");
        }
#line 1903 "y.tab.c"
    break;

  case 58: /* return: %empty  */
#line 332 "syntax.y"
          {
            (yyval.ObjNod).nod = NULL;
        }
#line 1911 "y.tab.c"
    break;

  case 59: /* expression: expression tk_opMath expression  */
#line 338 "syntax.y"
                                        {
            
            string ret = checkType((yyvsp[-2].ObjNod2).name, (yyvsp[0].ObjNod2).type);

            if((ret == "equal")){
                {
                    snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", (yyvsp[-2].ObjNod2).type);
                    (yyval.ObjNod2).nod = makeNode((yyvsp[-2].ObjNod2).nod, (yyvsp[0].ObjNod2).nod, "OpMath");
                }
            }
            else if(ret != "Null"){
                    snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", (yyvsp[-2].ObjNod2).type);
                    struct node *t =  makeNode(NULL, (yyvsp[0].ObjNod2).nod, ret);
                    (yyval.ObjNod2).nod = makeNode((yyvsp[-2].ObjNod2).nod, t, ret);
                }
            }
#line 1932 "y.tab.c"
    break;

  case 60: /* expression: value  */
#line 354 "syntax.y"
                {
            strcpy((yyval.ObjNod2).name, (yyvsp[0].ObjNod2).name);
            snprintf((yyval.ObjNod2).type, sizeof((yyval.ObjNod2).type), "%s", (yyvsp[0].ObjNod2).type);
            (yyval.ObjNod2).nod = (yyvsp[0].ObjNod2).nod;
        }
#line 1942 "y.tab.c"
    break;


#line 1946 "y.tab.c"

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

#line 361 "syntax.y"


int main(int argc, char **argv) {
    
    yyparse();

     printtree(root);
    if (numError > 0) {
        printf("Analise semantica completa com %d erros\n", numError);
        for (int i = 0; i < numError; i++) {
            printf("\t - %s", errors[i]);
        }
    } else {
        printf("Analise semantica completa sem erros");
    }
    printf("\n\n");

    return 0;
}

void putType(){
    type = yytext;
}

string checkType(const string& typeA, const string& typeB) {
    if (typeA == typeB) {
        return "equal";
    } else if (typeA == "int") {
        if (typeB == "float") {
            return "intFloat";
        } else if (typeB == "char") {
            return "intChar";
        }
    } else if (typeA == "float") {
        if (typeB == "int") {
            return "floatInt";
        } else if (typeB == "char") {
            return "floatChar";
        }
    } else if (typeA == "char") {
        if (typeB == "int") {
            return "charInt";
        } else if (typeB == "float") {
            return "charFloat";
        }
    } else if (typeB == "null") {
        return "Null";
    } else {
        cout << "Erro na linha " << (lines + 1) << ": Tipo de dado nao encontrado." << endl;
        numError++;
        return "";
    } 
}

node* makeNode(node* left, node* right, const string& token) {
    node* newNode = new node;
    newNode->token = token;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void report_error(const std::string& type, const std::string& msg) {
    std::cerr << "Erro! " << type << " (linha " << yylineno << "): " << msg << std::endl;
}

void yyerror(const char *s) {
    report_error(s, "Erro de sintaxe");
    std::cerr << "Erro! " << s << " (linha " << yylineno << ")" << std::endl;
    exit(1);
}

char* getType(const char* var) {
    for (int i = 0; i < count; i++) {
        if (strcmp(Table[i].nameId, var) == 0) {
            return Table[i].dataType;
        }
    }
    return "Tipo desconhecido";
}

void checkStatement(char* c) {
    int check = search(c);
    if (!check) {
        snprintf(errors[numError], sizeof(errors[numError]), "Linha %d: Variavel \"%s\" nao declarada antes do uso!\n", lines + 1, c);
        numError++;
    }
}

int search(char *type) {
    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(Table[i].nameId, type) == 0) {
            return -1;
        }
    }
    return 0;
}

void checkReturnType(char *value) {
    char *dataTypeA = getType("main");
    char *dataTypeB = getType(value);


    if (!strcmp(dataTypeA, "Tipo desconhecido") || 
        !strcmp(dataTypeB, "Tipo desconhecido")) {
        sprintf(errors[numError], "Linha %d: Tipo de retorno ou tipo de função main não encontrado\n", lines + 1);
        numError;
        return ;
    }
    else if (!strcmp(dataTypeA, dataTypeB)) {
        return;
    } else {
        sprintf(errors[numError], "Linha %d: Tipos de retorno diferentes\n", lines + 1);
        numError++;
    }
}

void printInorder(struct node *tree, FILE *file) {
    if (tree == NULL) {
        fprintf(file, "null");
        return;
    }

    fputs(file, "{\n");
    fputs(file, "  \"token\": \"%s\",\n", tree->token);
    fputs(file, "  \"left\": ");
    printInorder(tree->left, file);
    fputs(file, ",\n");
    fputs(file, "  \"right\": ");
    printInorder(tree->right, file);
    fputs(file, "\n}");
}

void printtree(struct node* tree) {
    FILE *file = fopen("arvore_sintatica.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }

    printInorder(tree, file);
    fputs(file, "\n");

    fclose(file);
    printf("Abstract Syntax Tree salva em 'arvore_sintatica.txt'.\n");
}
