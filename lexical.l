%{
    #include "y.tab.h"
    #include <iostream>
    #include <unistd.h>
    #include <string>
    #include <vector>
    extern int yylineno;

    int lines = 0;

    using namespace std;

    void printToken(const string& token_name, const string& token_value) {
        cout << "Token: " << token_name << "\tValor: " << token_value << endl;
    }
%}

%option yylineno

%%

[0-9]+                                 { printToken("tk_int", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_int); }
[0-9]+\.[0-9]+                         { printToken("tk_float", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_float); }
\'[^\']\'                              { printToken("tk_char", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_char); }
\"(\\.|[^"\\])*\"                      { printToken("tk_string", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_string); }

"import"                               { printToken("tk_import", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_import);}
"int"                                  { printToken("tk_typeInt", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_typeInt); }
"float"                                { printToken("tk_typeFloat", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_typeFloat); }
"char"                                 { printToken("tk_typeChar", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_typeChar); }
"string"                               { printToken("tk_typeString", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_typeString); }

"[]"                                   { printToken("tk_vet", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_vet); }
"if"                                   { printToken("tk_if", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_if); }
"else"                                 { printToken("tk_else", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_else); }
"for"                                  { printToken("tk_for", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_for); }
"print"                                { printToken("tk_print", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_print); }
"scanf"                                { printToken("tk_scanf", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_scanf); }
"main"                                 { printToken("tk_main", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_main); }
"void"                                 { printToken("tk_void", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_void); }
"return"                               { printToken("tk_return", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_return); }

"T"                                    { printToken("tk_true", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_true); }
"F"                                    { printToken("tk_false", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_false); }

\/\/[^\r\n]*                           {                }

"="                                    { printToken("tk_atrib", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_atrib); }

"+"|"-"|"*"|"**"|"/"                   { printToken("tk_opMath", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_opMath); }
"=="|"<"|">"|"<="|">="|"and"|"or"|"!=" { printToken("tk_opLog", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_opLog); }
"("                                    { printToken("tk_openParen", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_openParen); }
")"                                    { printToken("tk_closeParen", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_closeParen); }
"["                                    { printToken("tk_openBracket", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_openBracket); }
"]"                                    { printToken("tk_closeBracket", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_closeBracket); }
"{"                                    { printToken("tk_openCurly", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_openCurly); }
"}"                                    { printToken("tk_closeCurly", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_closeCurly); }
":"                                    { printToken("tk_colon", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_colon); }
";"                                    { printToken("tk_semicolon", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_semicolon); }
","                                    { printToken("tk_comma", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_comma); }

[a-zA-Z_-][a-zA-Z0-9_.:-]*             { printToken("tk_id", yytext); strcpy(yylval.ObjNod.name,(yytext)); return (tk_id); }

[ \t\r]                                {            }
[\n]                                   { lines++;   }

.                                      { cout << "Erro! Token desconhecido."; return (*yytext); }

%%

string tokenToString(int token) {
        switch (token) {
            case tk_int:        return "tk_int";
            case tk_float:      return "tk_float";
            case tk_char:       return "tk_char";
            case tk_string:     return "tk_string";
            case tk_typeInt:    return "tk_typeInt";
            case tk_typeFloat:  return "tk_typeFloat";
            case tk_typeChar:   return "tk_typeChar";
            case tk_typeString: return "tk_typeString";
            case tk_vet:        return "tk_vet";
            case tk_if:         return "tk_if";
            case tk_for:        return "tk_for";
            case tk_print:      return "tk_print";
            case tk_scanf:      return "tk_scanf";
            case tk_main:       return "tk_main";
            case tk_atrib:      return "tk_atrib";
            case tk_opMath:     return "tk_opMath";
            case tk_opLog:      return "tk_opLog";
            case tk_openParen:  return "tk_openParen";
            case tk_closeParen: return "tk_closeParen";
            case tk_openBracket:return "tk_openBracket";
            case tk_closeBracket:return "tk_closeBracket";
            case tk_openCurly:  return "tk_openCurly";
            case tk_closeCurly: return "tk_closeCurly";
            case tk_colon:      return "tk_colon";
            case tk_semicolon:  return "tk_semicolon";
            case tk_comma:      return "tk_comma";
            case tk_id:         return "tk_id";
            case tk_import:     return "tk_import";
            case tk_true:       return "tk_true";
            case tk_false:      return "tk_false";
            case tk_else:       return "tk_else";
            case tk_void:       return "tk_void";
            case tk_return:     return "tk_return";
            default:            return "Erro";
        }
    }

int yywrap() {
    return 1;
}