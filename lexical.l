%{
    #include <iostream>
    #include <unistd.h>
    #include <vector>
    #define MAKE_TOKEN(token) ((Tokens) token) 

    using namespace std;

    enum Tokens {
        tk_err,
        tk_int,
        tk_float,
        tk_char,
        tk_string,
        tk_typeInt,
        tk_typeFloat,
        tk_typeChar,
        tk_typeString,
        tk_vet,
        tk_if,
        tk_for,
        tk_print,
        tk_scanf,
        tk_main,
        tk_atrib,
        tk_opMath,
        tk_opLog,
        tk_openParen,
        tk_closeParen,
        tk_openBracket,
        tk_closeBracket,
        tk_openCurly,
        tk_closeCurly,
        tk_colon,
        tk_semicolon,
        tk_comma,
        tk_id,
        tk_import
    };

    string tokenToString(Tokens token) {
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
            case tk_err:        return "tk_err";
            default:            return "Erro";
        }
    }
%}

%%

[0-9]+                                 { return (tk_int); }
[0-9]+\.[0-9]+                         { return (tk_float); }
\'[^\']\'                              { return (tk_char); }
\"(\\.|[^"\\])*\"                      { return (tk_string); }

"import"                               { return (tk_import);}
"int"                                  { return (tk_typeInt); }
"float"                                { return (tk_typeFloat); }
"char"                                 { return (tk_typeChar); }
"string"                               { return (tk_typeString); }

"[]"                                   { return (tk_vet); }
"if"                                   { return (tk_if); }
"for"                                  { return (tk_for); }
"print"                                { return (tk_print); }
"scanf"                                { return (tk_scanf); }
"main"                                 { return (tk_main); }
"void"                                 { return (tk_void); }
"return"                               { return (tk_return); }

"T"                                    { return (tk_true); }
"F"                                    { return (tk_false); }

\/\/[^\r\n]*                           {                }

"="                                    { return (tk_atrib); }

"+"|"-"|"*"|"**"|"/"                   { return (tk_opMath); }
"=="|"<"|">"|"<="|">="|"and"|"or"|"!=" { return (tk_opLog); }
"("                                    { return (tk_openParen); }
")"                                    { return (tk_closeParen); }
"["                                    { return (tk_openBracket); }
"]"                                    { return (tk_closeBracket); }
"{"                                    { return (tk_openCurly); }
"}"                                    { return (tk_closeCurly); }
":"                                    { return (tk_colon); }
";"                                    { return (tk_semicolon); }
","                                    { return (tk_comma); }

[a-zA-Z_-][a-zA-Z0-9_.:-]*             { return (tk_id); }

[ \t\r\n]                              {                }

.                                      { return (return *yytext); } 

%%
int main(int argc, char **argv) {
    Tokens token;

    vector<Tokens> table;

    while ((token = MAKE_TOKEN(yylex()))) {
        table.push_back(token);

        if(token == 0){
            break;
        }
    }

    for (Tokens token : table) {
        cout << "Token: " << tokenToString(token) << endl;
    }

    return 0;
}

int yywrap() {
    return 1;
}