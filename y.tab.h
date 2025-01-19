/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    

#line 151 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
