%{
    #include <iostream>
    #include <unistd.h>
    #include <vector>
    #include "lex.yy.c"

    using namespace std;

    struct node* makeNode(struct node *left, struct node *right, char *token);

    struct node *root;

    struct node{
        struct node *left;
        struct node *right;
        char *token;
    };
%}

    %union {
        struct varName{
            char name[100];
            struct node* nod;
        } ObjNod;

        struct varName2{
            char name[100];
            struct node* nod;
            char type[5];
        } ObjNod2;
    }

    %token tk_void
    %token <ObjNod> tk_int tk_float tk_char tk_string tk_typeInt tk_typeFloat tk_typeChar tk_typeString tk_vet tk_if tk_for tk_print tk_scanf tk_main tk_atrib tk_opMath tk_opLog tk_openParen tk_closeParen tk_openBracket tk_closeBracket tk_openCurly tk_closeCurly tk_colon tk_semicolon tk_comma tk_id tk_import
    %type <ObjNod> menu imports listFunctions

%%

    menu:
        imports listFunctions {
            $$.nod = makeNode($1.nod, $2.nod, "menu");
            root = $$.nod;
        };

    imports:
        tk_import {
            $$.nod = makeNode(NULL, NULL, $1.name);
        };

%%

void main(){
    yyparse();
}