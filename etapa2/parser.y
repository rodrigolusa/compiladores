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
    function | global;


/* tipos */
type:
    TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL ;


/* literais*/
literal:
    TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_TRUE | TK_LIT_FALSE ;


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
    commands_block;


/* bloco de comando */
commands_block:
    '{' simple_command_list '}'

simple_command_list:
    simple_command_list simple_command ';' | ;


/* comandos simples */
simple_command:
    local_var_command | set_command | function_command | return_command;


/* declaração de variável */
local_var_command:
    type local_vars_list ';';

local_vars_list:
    local_vars_list ',' TK_IDENTIFICADOR | local_vars_list ',' TK_IDENTIFICADOR TK_OC_LE literal | TK_IDENTIFICADOR TK_OC_LE literal  | TK_IDENTIFICADOR;


/* declaração de atribuição */
set_command:
    TK_IDENTIFICADOR TK_OC_EQ expr;


/* comando de função
function_command:
    TK_IDENTIFICADOR '(' args ')';

args:
    args ',' expr | expr;


/* comando de retorno */
return_command:
    TK_PR_RETURN expr;


/* comandos de controle de fluxo */
flow_control_command:
    condicional | iterative;

condicional:
    TK_PR_IF '(' expr ')' commands_block condicional_complement;

condicional_complement:
    TK_PR_ELSE commands_block | ;

iterative:
    TK_PR_WHILE '(' expr ')' commands_block;


expr:


%%

int yyerror(char const *s){
	printf("%s at line %d UNEXPECTED token \"%s\" \n", s,get_line_number(), yytext);
	return 1;
}