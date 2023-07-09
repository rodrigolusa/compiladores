//Grupo P -> João Carlos Almeida da Silva - Rodrigo Antonio Rezende Lusa

%{

#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int yylex(void);
void yyerror (char const *s);
extern int get_line_number (void);
extern char *yytext;
extern void *arvore;

%}

%define parse.error verbose

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
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token TK_ERRO

%token<valor_lexico> literal

%type<no> programa
%type<no> array
%type<no> element
%type<no> function
%type<no> global
%type<no> type
%type<no> operando
%type<no> vars
%type<no> header
%type<no> param_list
%type<no> param
%type<no> body
%type<no> commands_block
%type<no> simple_command
%type<no> simple_command_list
%type<no> simple_commands
%type<no> local_var_command
%type<no> local_var_list_complement
%type<no> local_vars_list
%type<no> set_command
%type<no> function_call
%type<no> args
%type<no> return_command
%type<no> flow_control_command
%type<no> condicional
%type<no> condicional_complement
%type<no> iterative
%type<no> opUn
%type<no> opG1
%type<no> opG2
%type<no> opG3
%type<no> opG4
%type<no> opAnd
%type<no> opOr
%type<no> expr
%type<no> expr1
%type<no> expr2
%type<no> expr3
%type<no> expr4
%type<no> expr5
%type<no> expr6
%type<no> expr7


%union {
    struct TipoLexico* valor_lexico;
    struct astNo* no;
}

%%


/* programa */
programa:
                        array { 
                            arvore = $1; 
                            } 
                        | { 
                            arvore = NULL; 
                            }
                        ;
array: 
                        array element {
                            if($2 == NULL){
                                $$ = $1;
                            } else{
                                if($1 != NULL){
                                    adicionarFilho($2, $1);                                   
                                }
                                $$ = $2;
                            }
                        }
                        | element {
                            if($1 == NULL){
                                $$ = $1;
                            } else{
                                $$ = NULL;
                            }
                        }
                        ;
element:
                        function {
                            $$ = $1;
                        } 
                        | global {
                            $$ = NULL;
                        }
                        ;


// TODO
type:
    TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;


literal:
                        TK_LIT_INT {
                            $$ = $1;
                        } 
                        | TK_LIT_FLOAT {
                            $$ = $1;
                        } 
                        | TK_LIT_TRUE {
                            $$ = $1;
                        } 
                        | TK_LIT_FALSE{
                            $$ = $1;
                        } 
                        ;

operando:
                        TK_IDENTIFICADOR {
                            $$ = criarNoTipoLexico($1);
                        }
                        | literal {
                            $$ = criarNoTipoLexico($1)
                        }
                        | function {
                            $$ = NULL;
                        }
                        ;

// TODO
global:
    type vars ';';

// TODO
vars:
    vars ',' TK_IDENTIFICADOR | TK_IDENTIFICADOR;

function:
                    header body {
                        $$ = $1;
                        adicionarFilho($$, $2);
                    }
                    ;

header:
                    TK_IDENTIFICADOR '(' param_list ')' TK_OC_MAP type {
                        $$ = criarNoTipoLexico($1);
                    }
                    ;

// TODO
param_list:
    params | ;

// TODO
params:
    params ',' param | param;

// TODO
param:
    type TK_IDENTIFICADOR;

body:
                    commands_block {
                        $$ = $1;
                    }
                    ;


/* bloco de comando */
commands_block:
                    '{' simple_commands '}' {
                        $$ = $2;
                    }
                    | '{' '}' {
                        $$ = NULL;
                    }
                    ;

// TODO
simple_commands:
    simple_command_list | ;

// TODO
simple_command_list:
    simple_command_list simple_command ';' | simple_command ';';


// TODO
simple_command:
    local_var_command | set_command | function_call | return_command | flow_control_command | ;


// TODO
local_var_command:
    type local_vars_list;

// TODO
local_vars_list:
    local_vars_list ',' TK_IDENTIFICADOR local_var_list_complement | TK_IDENTIFICADOR local_var_list_complement;

// TODO
local_var_list_complement:
    TK_OC_LE literal | ;

// TODO
set_command:
    TK_IDENTIFICADOR '=' expr;

// TODO
function_call:
    TK_IDENTIFICADOR '(' args ')';

// TODO
args:
    args ',' expr | expr;


// TODO
return_command:
    TK_PR_RETURN expr;


// TODO
flow_control_command:
    condicional | iterative;

condicional:
                        TK_PR_IF '(' expr ')' commands_block condicional_complement {
                            $$ = criarNo("if");
                            adicionarFilho($$, $3);
                            adicionarFilho($$, $5);
                            adicionarFilho($$, $6);
                            if($6 != NULL){
                                atualizarValor($$);
                            }
                        }
                        ;

condicional_complement:
                        TK_PR_ELSE commands_block {
                            $$ = $2;
                        }
                        | {
                            $$ = NULL;
                        }
                        ;

iterative:
                        TK_PR_WHILE '(' expr ')' commands_block {
                            $$ = criarNo("iterative");
                            adicionarFilho($$, $3);
                            adicionarFilho($$, $5);
                        }
                        ;

opUn:
                        '-' {
                            $$ = criarNo("-");
                        }
                        | '!' {
                            $$ = criarNo("!");
                        }
                        ;

opG1:
                        '*' {
                            $$ = criarNo("*");
                        }
                        | '/' {
                            $$ = criarNo("/");
                        }
                        | '%' {
                            $$ = criarNo("%");
                        }
                        ;

opG2:
                        '+' {
                            $$ = criarNo("+");
                        }
                        | '-' {
                            $$ = criarNo("-");
                        }
                        ;

opG3:
                        '<' {
                            $$ = criarNo("<");
                        }
                        | '>' {
                            $$ = criarNo(">");
                        }
                        | TK_OC_LE {
                            $$ = criarNo("<=");
                        }
                        | TK_OC_GE {
                            $$ = criarNo(">=");
                        }
                        ;

opG4:
                        TK_OC_EQ {
                            $$ = criarNo("==");
                        }
                        | TK_OC_NE {
                            $$ = criarNo("!=");
                        }
                        ;

opAnd:
                        TK_OC_AND {
                            $$ = criarNo("&");
                        }
                        ;
                        
opOr:
                        TK_OC_OR {
                            $$ = criarNo("|");
                        }
                        ;

expr:                   
                        expr1 {
                            $$ = $1;
                        }
                        | expr opOr expr1 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                        }
                        ;

expr1:
                        expr2 {
                            $$ = $1;
                        }
                        | expr1 opAnd expr2 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                        }
                        ;

expr2:
                        expr3 {
                            $$ = $1;
                        }
                        | expr2 opG4 expr3 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                        }
                        ;

expr3:
                       expr4 {
                        $$ = $1;
                       }
                       | expr3 opG3 expr4 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                       }
                       ;

expr4:
                       expr5 {
                        $$ = $1;
                       } 
                       | expr4 opG2 expr5 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                       }
                       ;

expr5:
                        expr5 {
                            $$ = $1;
                        }
                        | expr5 opG1 expr6 {
                            adicionarFilho($2, $1);
                            adicionarFilho($2, $3);
                            $$ = $2;
                        }
                        ;

expr6:
                        expr7 {
                            $$ = $1;
                        }
                        | opUn expr7 {
                            adicionarFilho($1, $2);
                            $$ = $1;
                        }
                        ;

expr7:
                        operando {
                            $$ = $1;
                        }
                        | '(' expr ')' {
                            $$ = $2;
                        }
                        ;

%%

void yyerror(char const *s){
	printf("%s at line %d UNEXPECTED token \"%s\" \n", s,get_line_number(), yytext);
}