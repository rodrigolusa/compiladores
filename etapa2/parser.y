/*Grupo P - Rodrigo Antonio Rezende Lusa*/

%{
int yylex(void);
int yyerror (char const *s);
extern int get_line_number (void);
extern char *yytext;
#include <stdlib.h>
#include <stdio.h>
%}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_MAP
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%


/* programa */

programa:
    array | ;
array: 
    array element | element;
element:
    function | global_var;

/* tipos */

type:
    TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL ;

/* variáveis globais */
global:
    type vars ';';

vars:
    vars ',' TK_IDENTIFICADOR | TK_IDENTIFICADOR;



/* função */

function:
    header body;

header:
    TK_IDENTIFICADOR '(' param_list ')' TK_OC_MAP type;

param_list:
    params | ;

params:
    params ',' param | param ;

param:
    type TK_IDENTIFICADOR;

body:


%%

int yyerror(char const *s){
	printf("%s at line %d UNEXPECTED token \"%s\" \n", s,get_line_number(), yytext);
	return 1;
}