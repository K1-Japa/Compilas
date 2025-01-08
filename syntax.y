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
    %type <ObjNod> menu imports listFunctions main main_start code return dataType statement functionCall print printString args condition else

%%

    menu:
        imports listFunctions {
            $$.nod = makeNode($1.nod, $2.nod, "menu");
            root = $$.nod;
        };

    imports:
        tk_import {
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        |imports tk_import {
            $2.nod =  makeNode(NULL, NULL, $2.name);
            $$.nod = makeNode($1.nod, $2.nod, "imports");
        }
        |{
            $$.nod = NULL;
        };
    
    main:
        main_start tk_openCurly code return tk_closeBracket {
            $$.nod = makeNode($1.nod, $3.nod, "main");
        };
    
    main_start:
        dataType tk_main tk_openParen tk_closeParen{

        };
    
    dataType:
        tk_typeInt{
            putType();
        }
        |tk_typeFloat{
            putType():
        }
        |tk_typeChar{
            putType();
        }
        |tk_typeString{
            putType();
        }
        |tk_void{
            putType();
        };

    code:
        statement tk_semicolon{
            $$.nod = $1.nod;
        }
        |functionCall tk_semicolon{
            $$.nod = $1.nod;
        }
        |print tk_semicolon{
            $$.nod = makeNode($1.nod, $2.nod, "printFunction");
        }
        |tk_scanf tk_openParen tk_string tk_comma '&' tk_id tk_closeParen tk_semicolon{
            $$.nod = makeNode(NULL, NULL, "scan");
        }
        |tk_if tk_openParen condition tk_closeParen tk_openCurly code tk_closeCurly else

    print:
        tk_print tk_openParen printString tk_closeParen{
            $$.nod = makeNode(NULL, NULL, "print");
        };

    printString:
        tk_string{
            $$.nod = makeNode(NULL, NULL, "printString");
        }
        |tk_string tk_comma args{
            $$.nod = makeNode($1.nod, $3.nod, "args");
        };

    args:
        tk_id{
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        |tk_id tk_comma args{
            $$.nod = makeNode(NULL, $3.nod, $3.name);
        }
        |{
            $$.nod = NULL;
        };



%%

void main(){
    yyparse();
}

void putType(){
    strcpy(type, yytext);
}