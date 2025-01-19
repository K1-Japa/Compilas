%{
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
    %token <ObjNod> tk_int tk_float tk_char tk_string tk_typeInt tk_typeFloat tk_typeChar tk_typeString tk_vet tk_if tk_for tk_print tk_scanf tk_main tk_atrib tk_opMath tk_opLog tk_openParen tk_closeParen tk_openBracket tk_closeBracket tk_openCurly tk_closeCurly tk_colon tk_semicolon tk_comma tk_id tk_import tk_true tk_false tk_else tk_return
    %type <ObjNod> menu imports listFunctions main main_start code return dataType statement functionCall print printString args condition else statementFunction nameFunction listParameters array
    %type <ObjNod2> value init expression

%%

    menu:
        imports listFunctions {
            $$.nod = makeNode($1.nod, $2.nod, "menu");
            root = $$.nod;
        };

    imports:
        imports tk_import tk_openParen tk_string tk_closeParen tk_semicolon{
            $2.nod =  makeNode(NULL, NULL, $2.name);
            $$.nod =  makeNode($1.nod, $2.nod, "imports");
        }
        |{
            $$.nod = NULL;
        };

    listFunctions:
        statementFunction {
            $$.nod = $1.nod;
        }
        | listFunctions statementFunction {
            $$.nod = makeNode($1.nod, $2.nod, "listFunctions");
        }
        ;

    statementFunction:
        nameFunction tk_openCurly code return tk_closeCurly {
            $$.nod = makeNode($1.nod, $3.nod, "statementFunction");
        }
        | main {
            $$.nod = $1.nod;
        };

    nameFunction:
        dataType tk_id tk_openParen listParameters tk_closeParen {
            $$.nod = makeNode($1.nod, $4.nod, $2.name);
        };

    listParameters:
        dataType tk_id {

        }
        | listParameters tk_comma dataType tk_id {

        }
        | {
            $$.nod = NULL;
        }
    
    main:
        main_start tk_openCurly code return tk_closeCurly {
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
            putType();
        }
        |tk_typeChar{
            putType();
        }
        |tk_typeString{ //remover tipo string
            putType();
        }
        |tk_void{
            putType();
        };

    code:
        statement tk_semicolon{
            $$.nod = $1.nod;
        }
        | functionCall tk_semicolon{
            $$.nod = $1.nod;
        }
        | print tk_semicolon{
            $$.nod = makeNode($1.nod, $2.nod, "printFunction");
        }
        | tk_scanf tk_openParen tk_string tk_comma '&' tk_id tk_closeParen tk_semicolon{
            $$.nod = makeNode(NULL, NULL, "scan");
        }
        | tk_if tk_openParen condition tk_closeParen tk_openCurly code tk_closeCurly else {
            struct node *ifA = makeNode($3.nod, $6.nod, $1.name);
            $$.nod = makeNode(ifA, $8.nod, "if-else");
        }
        | tk_for tk_openParen statement tk_semicolon condition tk_semicolon statement tk_closeParen tk_openCurly code tk_closeCurly {
            struct node *forA = makeNode($5.nod, $7.nod, "for condition");
            struct node *forB = makeNode($3.nod, forA, "for condition");
            $$.nod = makeNode(forB, $10.nod, $1.name);
        }
        | code statement tk_semicolon {
            $$.nod = makeNode($1.nod, $2.nod, "code");
        }
        | code functionCall tk_semicolon {
            $$.nod = makeNode($1.nod, $2.nod, "code");
        }
        | code print tk_semicolon {
            $$.nod = makeNode($1.nod, $2.nod, "code");
        }
        | code tk_scanf tk_openParen tk_string tk_comma '&' tk_id tk_closeParen tk_semicolon {
            struct node* scanA = makeNode(NULL, NULL, "scan");
            $$.nod = makeNode($1.nod, scanA, "code");
        }
        | code tk_if tk_openParen condition tk_closeParen tk_openCurly code tk_closeCurly else {
            struct node *ifA = makeNode($4.nod, $7.nod, $3.name);
            struct node* ifelseA = makeNode(ifA, $9.nod, "if-else");
            $$.nod = makeNode($1.nod, ifelseA, "code");
        }
        | code tk_for tk_openParen statement tk_semicolon condition tk_semicolon statement tk_closeParen tk_openCurly code tk_closeCurly {
            struct node *forA = makeNode($6.nod, $8.nod, "for condition");
            struct node *forB = makeNode($4.nod, forA, "for condition");
            struct node *forC = makeNode(forC, $11.nod, $3.name);
            $$.nod = makeNode($1.nod, forC, "code");
        }
        ;

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
        |args tk_comma tk_id{
            $$.nod = makeNode($1.nod, $3.nod, $3.name);
        }
        |{
            $$.nod = NULL;
        };

    functionCall:
        tk_id tk_openParen tk_closeParen {
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        | tk_id tk_openParen args tk_closeParen {
            $$.nod = makeNode(NULL, $3.nod, $1.name);
        };

    condition:
        value tk_opLog value {
            $$.nod = makeNode($1.nod, $3.nod, $2.name);
        }
        | tk_true {
            $$.nod = NULL;
        }
        | tk_false {
            $$.nod = NULL;
        }
        | {
            $$.nod = NULL;
        };

    else:
        tk_else tk_openCurly code tk_closeCurly {
            $$.nod = makeNode($3.nod, NULL, $1.name);
        }
        | {
            $$.nod = NULL;
        };
    
    statement:
        dataType tk_id init {
            $2.nod = makeNode(NULL, NULL, $2.name);

            string ret = checkType($1.name, $3.type);
            
            if((ret == "equal") || (ret == "Null")){
                $$.nod = makeNode($2.nod, $3.nod, "statement");
            }
            else{
                struct node *t =  makeNode(NULL, $3.nod, ret);

                $$.nod = makeNode($2.nod, t, "statement");
            }
        }
        | array init {
            $2.nod = makeNode(NULL, NULL, $2.name);

            string ret = checkType($1.name, $2.type);

            if((ret == "equal") || (ret == "Null")){
                $$.nod = makeNode($2.nod, $2.nod, "statement");
            }
            else{
                struct node *t =  makeNode(NULL, $2.nod, ret);

                $$.nod = makeNode($2.nod, t, "statement");
            }    
        }
        | tk_id tk_atrib expression{
            $1.nod = makeNode(NULL, NULL, $1.name);
        };
    
    init:
        tk_atrib value {
            $$.nod = $2.nod;
            snprintf($$.type, sizeof($$.type), "%s", $2.type);
            strcpy($$.name, $2.name);
        }
        | {
            snprintf($$.type, sizeof($$.type), "%s", "null");
            $$.nod = makeNode(NULL, NULL, "null");
            strcpy($$.name, "null");
        };
    
    array:
        dataType tk_vet tk_id tk_openBracket tk_int tk_closeBracket {
            $1.nod = makeNode(NULL, NULL, $1.name);
            $$.nod = makeNode($1.nod, $3.nod, "array");
        };

    value:
        tk_int {
            strcpy($$.name, $1.name);
            snprintf($$.type, sizeof($$.type), "%s", "int");
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        | tk_float {
            strcpy($$.name, $1.name);
            snprintf($$.type, sizeof($$.type), "%s", "float");
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        | tk_char {
            strcpy($$.name, $1.name);
            snprintf($$.type, sizeof($$.type), "%s", "char");
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        | tk_id {
            strcpy($$.name, $1.name);
            char* typeId = getType($1.name);
            snprintf($$.type, sizeof($$.type), "%s", typeId);
            $$.nod = makeNode(NULL, NULL, $1.name);
        }
        | tk_id tk_openBracket expression tk_closeBracket {
            checkStatement($1.name);
            $$.nod = makeNode($1.nod, $3.nod, "Index Array Access");
        };

    return:
        tk_return value tk_semicolon{
            checkReturnType($2.name);
            $1.nod = makeNode(NULL, NULL, "return");
            $$.nod = makeNode($1.nod, $2.nod, "Return value");
        }
        | {
            $$.nod = NULL;
        }
        ;

    expression:
        expression tk_opMath expression {
            
            string ret = checkType($1.name, $3.type);

            if((ret == "equal")){
                {
                    snprintf($$.type, sizeof($$.type), "%s", $1.type);
                    $$.nod = makeNode($1.nod, $3.nod, "OpMath");
                }
            }
            else if(ret != "Null"){
                    snprintf($$.type, sizeof($$.type), "%s", $1.type);
                    struct node *t =  makeNode(NULL, $3.nod, ret);
                    $$.nod = makeNode($1.nod, t, ret);
                }
            }
        | value {
            strcpy($$.name, $1.name);
            snprintf($$.type, sizeof($$.type), "%s", $1.type);
            $$.nod = $1.nod;
        }
        ;

%%

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

    fprintf(file, "{\n");
    fprintf(file, "  \"token\": \"%s\",\n", tree->token);
    fprintf(file, "  \"left\": ");
    printInorder(tree->left, file);
    fprintf(file, ",\n");
    fprintf(file, "  \"right\": ");
    printInorder(tree->right, file);
    fprintf(file, "\n}");
}

void printtree(struct node* tree) {
    FILE *file = fopen("arvore_sintatica.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }

    printInorder(tree, file);
    fprintf(file, "\n");

    fclose(file);
    printf("Abstract Syntax Tree salva em 'arvore_sintatica.txt'.\n");
}