%{
/*Grupo P -> João Carlos Almeida da Silva - Rodrigo Antonio Rezende Lusa*/

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

%type<no> programa
%type<no> array
%type<no> element
%type<no> literal
%type<no> operando
%type<no> function
%type<no> header
%type<valor_lexico> empilha_tabela
%type<no> param
%type<no> type
%type<no> global
%type<no> vars
%type<no> body
%type<no> commands_block
%type<no> simple_command
%type<no> command_list
%type<no> local_var_command
%type<no> local_vars_list
%type<no> local_var_list_complement
%type<no> set_command
%type<no> function_call
%type<no> args_list 
%type<no> args
%type<no> arg
%type<no> return_command
%type<no> flow_control_command
%type<no> condicional
%type<no> condicional_complement
%type<no> iterative
%type<no> opG0
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

programa:
                        cria_tabela array { 
                            arvore = $2; 
                            } 
                        | { 
                            arvore = NULL; 
                            }
                        ;
cria_tabela:           
                        {
                            // Cria a tabela
                        }
                        ;
array: 
                        element array {
                            if($1 == NULL){
                                $$ = $2;
                            } else{
                                if($2 != NULL){
                                    adicionarFilho($1, $2);                                   
                                } else {
                                    $$ = $1;
                                }
                            }
                        } 
                        | element {
                            if($1 != NULL){
                                $$ = $1;
                            } else{
                                $$ = NULL;
                            }
                        } ;

element:
                        function {
                            $$ = $1;
                        } 
                        | global {
                            $$ = NULL;
                        } ;


function:
                    header body {
                        $$ = $1;
                        adicionarFilho($$, $2);
                    }
                    ;

header:
                    empilha_tabela '(' param_list ')' TK_OC_MAP type {
                        No *folha = $6;
                        $$ = criarNoTipoLexico($1, folha->tipo);

                        // Volta uma tabela e adiciona o simbolo da função
                    }
                    ;
empilha_tabela:
                    TK_IDENTIFICADOR {
                        $$ = $1;
                        
                        // Procura na tabela
                        // 1.1. Reporta err_declared
                        // 1.2. Empilha na tabela
                    }
                    ;
param_list:
                    params | ;

params:
                    params ',' param | param ;

param:
                    type TK_IDENTIFICADOR { 
                        No *folha = $1;
                        $$ = criarNoTipoLexico($2, folha->tipo);

                        // Procura na tabela
                        // 1.1. Reporta err_declared
                        // 1.2. Adicionar simbolo na tabela
                    }
                    ;

type:
        TK_PR_INT {
            $$ = criarNo("int", tINT); 
        }
        | TK_PR_FLOAT {
            $$ = criarNo("float", tFLOAT);
        }
        | TK_PR_BOOL {
            $$ = criarNo("bool", tBOOL);
        }
        ;

literal:
                        TK_LIT_INT {
                            $$ = criarNoTipoLexico($1, tINT);
                        } 
                        | TK_LIT_FLOAT {
                            $$ = criarNoTipoLexico($1, tFLOAT);
                        } 
                        | TK_LIT_TRUE {
                            $$ = criarNoTipoLexico($1, tBOOL);
                        } 
                        | TK_LIT_FALSE{
                            $$ = criarNoTipoLexico($1, tBOOL);
                        } 
                        ;

operando:
                        TK_IDENTIFICADOR {
                            // Tipo avaliado pela tabela
                            $$ = criarNoTipoLexico($1, tIndefinido);
                        }
                        | literal {
                            $$ = $1;
                        }
                        | function_call {
                            $$ = NULL;
                        }
                        ;

global:
        type vars ';' {
            $$ = $2;
            No *folha = $1;
            atualizarTipo($$, folha->tipo);

            // Procura na tabela
            // 1.1. Reporta err_declared
            // 1.2. Adiciona na tabela todos os vars
        }
        ;

vars:
                        vars ',' TK_IDENTIFICADOR {
                            $$ = $1;
                            adicionarFilho($$, criarNoTipoLexico($3, tIndefinido));
                        }
                        | TK_IDENTIFICADOR {
                            $$ = criarNoTipoLexico($1, tIndefinido);
                        }
                        ;

body:
                    commands_block {
                        $$ = $1;
                    }
                    ;

commands_block:
                    '{' simple_command '}' {
                        $$ = $2;
                    }
                    | '{' '}' {
                        $$ = NULL;
                    }
                    ;

simple_command:
                    command_list simple_command {
                        if($1 == NULL) 
                        { 
                            $$ = $2; 
                        }
                        else 
                        { 
                            if($2 != NULL) 
                            {
                                if(verificaValor($1, "<=") == 1) 
                                { 
                                    No *folha = $1;
                                    while(folha->n_filhos == 3)
                                        folha = folha->filhos[2];
                                    adicionarFilho(folha, $2);
                                }
                            else 
                            {
                                adicionarFilho($1, $2);
                            } 
                            $$ = $1;
                            } 
                            else 
                            { 
                                $$ = $1; 
                            } 
                        } 
                    }
                    | command_list {
                        if($1 != NULL)
                        {
                            $$ = $1;
                        } else
                        {
                            $$ = NULL;
                        }
                    }
                    ;

command_list:
                        empilha_tabela commands_block ';' {
                            $$ = $2;
                        }
                        | local_var_command ';' {
                            $$ = $1;
                        }
                        | set_command  ';' {
                            $$ = $1;
                        }
                        | flow_control_command {
                            $$ = $1;
                        }
                        | return_command ';' {
                            $$ = $1;
                        }
                        | function_call ';' {
                            $$ = $1;
                        }
                        ;

local_var_command:
                        type local_vars_list {
                            $$ = $2;
                            No *folha = $1;
                            atualizarTipo($$, folha->tipo);

                            // Procura na tabela
                            // 1.1. Reporta err_declared
                            // 1.2. Adiciona na tabela todos os local_vars_list
                        } 
                        ;

local_vars_list:
                        TK_IDENTIFICADOR ',' local_vars_list {
                            $$ = criarNoTipoLexico($1, tIndefinido);
                            adicionarFilho($$, $3);
                        }
                        | local_var_list_complement ',' local_vars_list {
                            $$ = $1;
                            adicionarFilho($$, $3);
                        }
                        | TK_IDENTIFICADOR {
                            $$ = criarNoTipoLexico($1, tIndefinido);
                        }
                        | local_var_list_complement {
                            $$ = $1;
                        } 
                        ;

local_var_list_complement:
                        TK_IDENTIFICADOR TK_OC_LE literal {
                            No *folha = $3;
                            $$ = criarNo("<=", tIndefinido);
                            adicionarFilho($$, criarNoTipoLexico($1, tIndefinido));
                            adicionarFilho($$, $3);
                        }
                        ;

set_command:
                        TK_IDENTIFICADOR '=' expr {
                            No *folha = $3;
                            $$ = criarNo("=", tIndefinido);
                            // Tipo avaliado pela tabela
                            adicionarFilho($$, criarNoTipoLexico($1, tIndefinido));
                            adicionarFilho($$, $3);

                            // Procura na Tabela
                            // 1.1. Reporta err_undeclared (caso não encontrado)
                            // 1.2. Reporta err_function (caso encontrado e ser uma função)
                            // 1.3. Configura na Tabela
                        }
                        ;

function_call:
                        TK_IDENTIFICADOR '(' args_list ')' {
                            // Tipo avaliado pela tabela
                            $$ = criarNoTipoLexico($1, tIndefinido);
                            atualizarValor($$);
                            adicionarFilho($$, $3);

                            // Procura na tabela
                            // 1.1. Reporta err_undeclared (caso não encontrado)
                            // 1.2. Reporta err_variable (caso encontrado e ser uma variável)
                            // 1.3. Abre tabela e seta argumentos
                        }
                        ;

args_list:              args{ 
                            $$ = $1; 
                        }
		                | {
                             $$ = NULL;
                        }
		                ;

args:                   arg ',' args {
                            adicionarFilho($1, $3); 
                            $$ = $1; 
                        } 
			            | arg {
                            $$ = $1;
                        }
		               ;

arg:
                        expr {
                            $$ = $1;
                        }
                        ;

return_command:
                        TK_PR_RETURN expr {
                            // Verifica na tabela
                            $$ = criarNo("return", tIndefinido);
                            adicionarFilho($$, $2);
                        }
                        ;

flow_control_command:
    condicional | iterative ';';

//if
condicional:
                        TK_PR_IF '(' expr ')' empilha_tabela commands_block condicional_complement {
                            $$ = criarNo("condicional", tIndefinido);
                            adicionarFilho($$, $3);
                            adicionarFilho($$, $6);
                            adicionarFilho($$, $7);
                            if($7 != NULL){
                                atualizarValor($$);
                            }
                        }
                        ;

//else
condicional_complement:
                        TK_PR_ELSE empilha_tabela commands_block ';' {
                            $$ = $3;
                        }
                        | ';' {
                            $$ = NULL;
                        }
                        ;

//while
iterative:
                        TK_PR_WHILE '(' expr ')' empilha_tabela commands_block {
                            $$ = criarNo("iterative", tIndefinido);
                            adicionarFilho($$, $3);
                            adicionarFilho($$, $6);
                        }
                        ;

opG0:
                        '-' {
                            $$ = criarNo("-", tIndefinido);
                        }
                        | '!' {
                            $$ = criarNo("!", tIndefinido);
                        }
                        ;

opG1:
                        '*' {
                            $$ = criarNo("*", tIndefinido);
                        }
                        | '/' {
                            $$ = criarNo("/", tIndefinido);
                        }
                        | '%' {
                            $$ = criarNo("%", tIndefinido);
                        }
                        ;

opG2:
                        '+' {
                            $$ = criarNo("+", tIndefinido);
                        }
                        | '-' {
                            $$ = criarNo("-", tIndefinido);
                        }
                        ;

opG3:
                        '<' {
                            $$ = criarNo("<", tIndefinido);
                        }
                        | '>' {
                            $$ = criarNo(">", tIndefinido);
                        }
                        | TK_OC_LE {
                            $$ = criarNo("<=", tIndefinido);
                        }
                        | TK_OC_GE {
                            $$ = criarNo(">=", tIndefinido);
                        }
                        ;

opG4:
                        TK_OC_EQ {
                            $$ = criarNo("==", tIndefinido);
                        }
                        | TK_OC_NE {
                            $$ = criarNo("!=", tIndefinido);
                        }
                        ;

opAnd:
                        TK_OC_AND {
                            $$ = criarNo("&", tIndefinido);
                        }
                        ;
                        
opOr:
                        TK_OC_OR {
                            $$ = criarNo("|", tIndefinido);
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
                        expr6 {
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
                        | opG0 expr7 {
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
	printf("ERROR: %s [linha: %d token \"%s\"] \n\n", s,get_line_number(), yytext);
}