%{
// Grupo P -> João Carlos Almeida da Silva - Rodrigo Antonio Rezende Lusa
// GERAÇÃO DE CÓDIGO EM UMA PASSAGEM

#include <stdlib.h>
#include <stdio.h>
#include "escopo.h"
#define TAMANHO_MAXIMO 64

int yylex(void);
void yyerror (char const *s);
extern int get_line_number (void);
extern char *yytext;
extern void *arvore;
Escopo* pilhaEscopo = NULL;
ListaChavesSimbolo* listaChaves = NULL;
int temporarioDisponivel = 0;
int rotuloDisponivel = 0;
int deslocamentoNovoDadoGlobal = 0;
int deslocamentoNovoDadoLocal = 0;
int memoriaReservada = 0;
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
%type<no> fun_name
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

inicio: abre_escopo programa fecha_escopo ;

abre_escopo:
            {
                pilhaEscopo = criarTabela(pilhaEscopo);
            } ;

fecha_escopo:       
            {
                pilhaEscopo = desempilharTabela(pilhaEscopo);
            } ;

programa:
            array 
            {
                definirCodigo($1, "halt", NULL, NULL, NULL);
                arvore = $1; 
            } 
            | { 
                arvore = NULL; 
                }
            ;
array: 
        element array 
        {
            if($1 == NULL)
            {
                $$ = $2;
            } 
            else
            {
                if($2 != NULL)
                {
                    adicionarFilho($1, $2);
                    $$ = $1;                                 
                } 
                else 
                {
                    $$ = $1;
                }
            }
        } 
        | element 
        {
            if($1 != NULL)
            {
                $$ = $1;
            } 
            else
            {
                $$ = NULL;
            }
        } ;

element:
        function 
        {
            $$ = $1;
        } 
        | global 
        {
            $$ = NULL;
        } ;

function:
            header TK_OC_MAP TK_PR_FLOAT body fecha_escopo 
            {
                    $$ = $1; adicionarFilho($$, $4); 
                    definirTipo($$, TYPE_FLOAT);
                    ChaveSimbolo* chave = criarNomeChave($1->valor);
                    ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, FUN_SYMBOL, get_line_number());
                    atualizarTipoConteudo(conteudo, TYPE_FLOAT); 
            } ;
            |  header TK_OC_MAP TK_PR_INT body fecha_escopo 
            {
                    $$ = $1; adicionarFilho($$, $4); definirTipo($$, TYPE_INT);
                    ChaveSimbolo* chave = criarNomeChave($1->valor);
                    ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, FUN_SYMBOL, get_line_number());
                    atualizarTipoConteudo(conteudo, TYPE_INT);
                    if($4 != NULL)
                        concatenarListas(&$$->codigo, $4->codigo);
            } ;
            | header TK_OC_MAP TK_PR_BOOL body fecha_escopo 
            {
                    $$ = $1; 
                    adicionarFilho($$, $4); 
                    definirTipo($$, TYPE_BOOL);
                    ChaveSimbolo* chave = criarNomeChave($1->valor);
                    ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, FUN_SYMBOL, get_line_number());
                    atualizarTipoConteudo(conteudo, TYPE_BOOL);
            } ;

header: 
        fun_name abre_escopo header_params 
        { 
            $$ = $1;
            ChaveSimbolo* chave = criarNomeChave($1->valor);
            ConteudoTabela* conteudo = procurarNaTabela(chave, pilhaEscopo->escopoAnterior);
            definirListaParametros(conteudo, listaChaves); 
            listaChaves = NULL;
        } ; 

fun_name: 
        TK_IDENTIFICADOR 
        {
            $$ = criarNoTipoLexico($1); 
            ChaveSimbolo* chave = criarNomeChave($1->valor);
            ConteudoTabela* conteudo =   novoConteudo(chave, $1->valor, get_line_number(), 0, FUN_SYMBOL, TYPE_UNDEFINED); 
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
        } ;

header_params: '(' param_list ')' ;

param_list:
            params | ;

params:
        params ',' param | param ;

param:
        TK_PR_INT TK_IDENTIFICADOR 
        {
            ChaveSimbolo* chave = criarNomeChave($2->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $2->valor, get_line_number(), 0, ID_SYMBOL, TYPE_INT); 
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            adicionarChaveNaLista(chave->nomeChave, &listaChaves, TYPE_INT, NULL);
        } ;
        | TK_PR_FLOAT TK_IDENTIFICADOR 
        {
            ChaveSimbolo* chave = criarNomeChave($2->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $2->valor, get_line_number(), 0, ID_SYMBOL, TYPE_FLOAT); 
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            adicionarChaveNaLista(chave->nomeChave, &listaChaves, TYPE_FLOAT, NULL);
        } ;
        | TK_PR_BOOL TK_IDENTIFICADOR 
        {
            ChaveSimbolo* chave = criarNomeChave($2->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $2->valor, get_line_number(), 0, ID_SYMBOL, TYPE_BOOL); 
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            adicionarChaveNaLista(chave->nomeChave, &listaChaves, TYPE_BOOL, NULL); 
        } ;

literal: 
        TK_LIT_INT
        { 
            $$ = criarNoTipoLexico($1);
            ChaveSimbolo* chave = criarNomeChave($1->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $1->valor, get_line_number(), 0, LIT_SYMBOL, TYPE_INT);
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            definirTipo($$, TYPE_INT);
            definirTemporario($$, temporarioDisponivel); temporarioDisponivel++;
            definirCodigo($$, "loadI", $$->valor, NULL, $$->local);
        } ;

literal: 
        TK_LIT_FLOAT
        { 
            $$ = criarNoTipoLexico($1);
            ChaveSimbolo* chave = criarNomeChave($1->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $1->valor, get_line_number(), 0, LIT_SYMBOL, TYPE_FLOAT);
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            definirTipo($$, TYPE_FLOAT); 
        } ;

literal: 
        TK_LIT_TRUE
        { 
            $$ = criarNoTipoLexico($1);
            ChaveSimbolo* chave = criarNomeChave($1->valor);
            ConteudoTabela* conteudo = novoConteudo(chave, $1->valor, get_line_number(), 0, LIT_SYMBOL, TYPE_BOOL);
            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
            definirTipo($$, TYPE_BOOL); 
        } ;

literal: 
    TK_LIT_FALSE
    {
        $$ = criarNoTipoLexico($1);
        ChaveSimbolo* chave = criarNomeChave($1->valor);
        ConteudoTabela* conteudo = novoConteudo(chave, $1->valor, get_line_number(), 0, LIT_SYMBOL, TYPE_BOOL);
        adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
        definirTipo($$, TYPE_BOOL); 
    } ;

operando:
            TK_IDENTIFICADOR 
            {
                $$ = criarNoTipoLexico($1); 
                ChaveSimbolo* chave = criarNomeChave($1->valor); 
                ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, ID_SYMBOL, get_line_number());
                definirTipo($$, conteudo->tipo);
                definirTemporario($$, temporarioDisponivel); temporarioDisponivel++;
                char* deslocamento = malloc(sizeof(char)*TAMANHO_MAXIMO);
                if(chaveEscopoGlobal(chave, pilhaEscopo, ID_SYMBOL, get_line_number()) == 1)
                {
                    sprintf(deslocamento, "%d", conteudo->deslocamento);
                    definirCodigo($$, "loadAI", "rbss", deslocamento, $$->local);
                }
                else if(chaveEscopoGlobal(chave, pilhaEscopo, ID_SYMBOL, get_line_number()) == 0)
                {
                    sprintf(deslocamento, "%d", conteudo->deslocamento);
                    definirCodigo($$, "loadAI", "rfp", deslocamento, $$->local);
                }
            }
            | literal
            {
                $$ = $1; 
            }
            | function_call
            {
                $$ = $1;
            }
            ;

global: 
        TK_PR_BOOL vars ';' 
        {   
            while(listaChaves != NULL) 
            {                             
                ChaveSimbolo* chave = criarNomeChave(listaChaves->chave.nomeChave);
                ConteudoTabela* conteudo = novoConteudo(chave, "0", get_line_number(), 0, ID_SYMBOL, TYPE_BOOL); 
                adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                listaChaves = listaChaves->proximo;
            }
            listaChaves = NULL;
        } ;


global: 
        TK_PR_INT vars ';' 
        {   
            while(listaChaves != NULL) 
            {                             
                ChaveSimbolo* chave = criarNomeChave(listaChaves->chave.nomeChave);
                ConteudoTabela* conteudo = novoConteudo(chave, "0", get_line_number(), deslocamentoNovoDadoGlobal, ID_SYMBOL, TYPE_INT);
                deslocamentoNovoDadoGlobal+=4;
                adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                listaChaves = listaChaves->proximo;
            }
            listaChaves = NULL;
        } ;


global: 
        TK_PR_FLOAT vars ';' 
        {   
            while(listaChaves != NULL) 
            {                             
                ChaveSimbolo* chave = criarNomeChave(listaChaves->chave.nomeChave);
                ConteudoTabela* conteudo = novoConteudo(chave, "0", get_line_number(), 0, ID_SYMBOL, TYPE_FLOAT); 
                adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                listaChaves = listaChaves->proximo;                                                              
            }
            listaChaves = NULL;
        } ;

vars:
        vars ',' TK_IDENTIFICADOR 
        {
                adicionarChaveNaLista($3->valor, &listaChaves, TYPE_UNDEFINED, NULL); 
        }
        | TK_IDENTIFICADOR 
        {
                adicionarChaveNaLista($1->valor, &listaChaves, TYPE_UNDEFINED, NULL); 
        }
        ;

body:
        commands_block 
        {
            $$ = $1;
        }
        ;

commands_block:
                '{' simple_command '}' 
                {
                    $$ = $2;
                }
                | '{' '}' 
                {
                    $$ = NULL;
                }
                ;

simple_command:
                    command_list simple_command 
                    {
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
                                    concatenarListas(&folha->codigo, $2->codigo);
                                }
                                else 
                                {
                                    adicionarFilho($1, $2);
                                    concatenarListas(&$1->codigo, $2->codigo);
                                } 
                                $$ = $1;
                            }
                            else
                            {
                                $$ = $1; 
                            } 
                        } 
                    }
                    | command_list 
                    {
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
                abre_escopo commands_block fecha_escopo ';' 
                {
                $$ = $2;
                }
                | local_var_command ';' 
                {
                    $$ = $1;
                }
                | set_command  ';' 
                {
                    $$ = $1;
                }
                | flow_control_command 
                {
                    $$ = $1;
                }
                | return_command ';' 
                {
                    $$ = $1;
                }
                | function_call ';' 
                {
                    $$ = $1;
                }
                ;

local_var_command: 
                    TK_PR_BOOL local_vars_list	
                    {
                        $$ = $2; 
                        if($2 != NULL) 
                        {
                            No *folha = $2;
                            No *id = $2->filhos[0];
                            definirTipo($$, TYPE_BOOL);
                            definirTipo(id, TYPE_BOOL);
                            while(folha->n_filhos == 3) 
                            {
                                folha = folha->filhos[2];
                                id = folha->filhos[0];
                                definirTipo(folha, TYPE_BOOL);
                                definirTipo(id, TYPE_BOOL);
                            }
                        }
                        while(listaChaves != NULL) 
                        {                             
                            ChaveSimbolo* chave = criarNomeChave( listaChaves->chave.nomeChave);                                               
                            ConteudoTabela* conteudo = novoConteudo(chave, listaChaves->valor, get_line_number(), 0, ID_SYMBOL, TYPE_BOOL); 
                            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                            listaChaves =  listaChaves->proximo;
                        }
                            listaChaves = NULL;
                    } ; 

local_var_command: 
                    TK_PR_INT local_vars_list	
                    {
                        $$ = $2; 
                        if($2 != NULL) 
                        {
                            No *folha = $2;
                            No *id = $2->filhos[0];
                            definirTipo($$, TYPE_INT);
                            definirTipo(id, TYPE_INT);
                            while(folha->n_filhos == 3) 
                            {
                                folha = folha->filhos[2];
                                id = folha->filhos[0];
                                definirTipo(folha, TYPE_INT);
                                definirTipo(id, TYPE_INT);
                            }
                        }
                        while(listaChaves != NULL) 
                        {
                            ChaveSimbolo* chave = criarNomeChave(listaChaves->chave.nomeChave);   
                            ConteudoTabela*  conteudo = novoConteudo(chave,  listaChaves->valor, get_line_number(), deslocamentoNovoDadoLocal, ID_SYMBOL, TYPE_INT);
                            deslocamentoNovoDadoLocal+=4;
                            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                            listaChaves =  listaChaves->proximo;
                        }
                        listaChaves = NULL;
                        memoriaReservada = 0;
                    } ; 

local_var_command: 
                    TK_PR_FLOAT local_vars_list	
                    {
                        $$ = $2; 
                        if($2 != NULL) 
                        {
                            No *folha = $2;
                            No *id = $2->filhos[0];
                            definirTipo($$, TYPE_FLOAT);
                            definirTipo(id, TYPE_FLOAT);
                            while(folha->n_filhos == 3) 
                            {
                                folha = folha->filhos[2];
                                id = folha->filhos[0];
                                definirTipo(folha, TYPE_FLOAT);
                                definirTipo(id, TYPE_FLOAT);
                            }
                        }
                        while( listaChaves != NULL) 
                        {                             
                            ChaveSimbolo* chave = criarNomeChave(listaChaves->chave.nomeChave);                                                
                            ConteudoTabela* conteudo = novoConteudo(chave, listaChaves->valor, get_line_number(), 0, ID_SYMBOL, TYPE_FLOAT); 
                            adicionarNaTabela(conteudo, pilhaEscopo, get_line_number());
                            listaChaves = listaChaves->proximo;
                        }
                        listaChaves = NULL;
                    } ; 

local_vars_list:
                    TK_IDENTIFICADOR ',' local_vars_list 
                    {
                        if($3 == NULL)
                        {
                            $$ = NULL;
                            adicionarChaveNaLista($1->valor, &listaChaves, TYPE_UNDEFINED, NULL);
                        } 
                        else
                        {
                            $$ = $3;
                        }
                    }
                    | local_var_list_complement ',' local_vars_list 
                    {
                        adicionarFilho($1, $3);
                        if($3 != NULL)
                            concatenarListas(&$1->codigo, $3->codigo);
                        $$ = $1;
                    }
                    | TK_IDENTIFICADOR 
                    {
                        $$ = NULL;
                        adicionarChaveNaLista($1->valor, &listaChaves, TYPE_UNDEFINED, NULL);
                    }
                    | local_var_list_complement 
                    {
                        $$ = $1;
                    } 
                    ;

local_var_list_complement:
                            TK_IDENTIFICADOR TK_OC_LE literal 
                            {
                                $$ = criarNo("<=");
                                adicionarFilho($$, criarNoTipoLexico($1));
                                adicionarFilho($$, $3);
                                int deslocamento = deslocamentoNovoDadoLocal + memoriaReservada; memoriaReservada+=4;
                                adicionarChaveNaLista($1->valor, &listaChaves, $3->tipo, $3->valor_lexico->valor);
                                concatenarListas(&$$->codigo, $3->codigo);
                                char* posicaoMemoria = malloc(sizeof(char)*TAMANHO_MAXIMO);
                                sprintf(posicaoMemoria, "rfp, %d", deslocamento);
                                definirCodigo($$, "storeAI", $3->local, NULL, posicaoMemoria);
                            }
                            ;

set_command:
                TK_IDENTIFICADOR '=' expr 
                {
                    ChaveSimbolo* chave = criarNomeChave($1->valor);
                    ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, ID_SYMBOL, get_line_number());                                          
                    $$ = criarNo("=");
                    No* id = criarNoTipoLexico($1);
                    definirTipo(id, conteudo->tipo);
                    adicionarFilho($$, id); 
                    adicionarFilho($$, $3); 
                    definirTipo($$, conteudo->tipo);
                    concatenarListas(&$$->codigo, $3->codigo);
                    char* posicaoMemoria = malloc(sizeof(char)*TAMANHO_MAXIMO);
                    if(chaveEscopoGlobal(chave, pilhaEscopo, ID_SYMBOL, get_line_number()) == 1)
                    {
                        sprintf(posicaoMemoria, "rbss, %d", conteudo->deslocamento);
                        definirCodigo($$, "storeAI", $3->local, NULL, posicaoMemoria);
                    }
                    else if(chaveEscopoGlobal(chave, pilhaEscopo, ID_SYMBOL, get_line_number()) == 0)
                    {
                        sprintf(posicaoMemoria, "rfp, %d", conteudo->deslocamento);
                        definirCodigo($$, "storeAI", $3->local, NULL, posicaoMemoria);
                    }
                }
                ;

function_call:
                TK_IDENTIFICADOR '(' args_list ')' 
                {
                    $$ = criarNoTipoLexico($1); 
                    atualizarValor($$); 
                    adicionarFilho($$, $3); 
                    ChaveSimbolo* chave = criarNomeChave($1->valor); 
                    ConteudoTabela* conteudo = procurarNaPilhaDeTabelas(chave, pilhaEscopo, FUN_SYMBOL, get_line_number());
                    definirTipo($$, conteudo->tipo); 
                    listaChaves = NULL;
                }
                ;

args_list:              
            args
            { 
                $$ = $1; 
            }
            | {
                    $$ = NULL;
            }
            ;

args:                   
        arg ',' args 
        {
            adicionarFilho($1, $3); 
            $$ = $1; 
        } 
        | arg 
        {
            $$ = $1;
        }
        ;

arg:
        expr 
        {
            $$ = $1;
            adicionarChaveNaLista($1->valor, &listaChaves, $1->tipo, NULL); //so importa tipo!
        }
        ;

return_command:
                    TK_PR_RETURN expr 
                    {
                        $$ = criarNo("return");
                        adicionarFilho($$, $2);
                        int tipo =  obterTipo($2);
                        definirTipo($$, tipo);
                    }
                    ;

flow_control_command:
                        condicional | iterative ';';

//if
condicional:
                TK_PR_IF '(' expr ')' abre_escopo commands_block fecha_escopo condicional_complement 
                {
                    $$ = criarNo("condicional");
                    adicionarFilho($$, $3);
                    adicionarFilho($$, $6);
                    adicionarFilho($$, $8);
                    definirTipo($$,  obterTipo($3));
                    char *rotulo1 = definirRotulo(rotuloDisponivel); rotuloDisponivel++;
                    char *rotulo2 = definirRotulo(rotuloDisponivel); rotuloDisponivel++;
                    char *rotulos = malloc(sizeof(char)*TAMANHO_MAXIMO);
                    sprintf(rotulos, "%s, %s", rotulo1, rotulo2);
                    concatenarListas(&$$->codigo, $3->codigo);
                    definirCodigo($$, "cbr", $3->local, NULL, rotulos);
                    rotulaAposOperacao($$, rotulo1);
                    if($6 !=NULL)
                    {
                        concatenarListas(&$$->codigo, $6->codigo);
                    }
                    rotulaAposOperacao($$, rotulo2);
                    if($8 != NULL)
                    {
                        atualizarValor($$);
                        concatenarListas(&$$->codigo, $8->codigo);
                    }
                }
                ;

//else
condicional_complement:
                        TK_PR_ELSE abre_escopo commands_block fecha_escopo ';' 
                        {
                            $$ = $3;
                        }
                        | ';' 
                        {
                            $$ = NULL;
                        }
                        ;

//while
iterative:
                TK_PR_WHILE '(' expr ')' abre_escopo commands_block fecha_escopo 
                {
                    $$ = criarNo("iterative");
                    adicionarFilho($$, $3);
                    adicionarFilho($$, $6);
                    definirTipo($$,  obterTipo($3));
                    char *rotuloInicio = definirRotulo(rotuloDisponivel); rotuloDisponivel++;
                    char *rotulo1 = definirRotulo(rotuloDisponivel); rotuloDisponivel++;
                    char *rotulo2 = definirRotulo(rotuloDisponivel); rotuloDisponivel++;
                    char *rotulos = malloc(sizeof(char)*TAMANHO_MAXIMO);
                    definirCodigo($$, "nop", NULL, NULL, NULL);
                    rotulaAposOperacao($$, rotuloInicio);
                    sprintf(rotulos, "%s, %s", rotulo1, rotulo2);
                    concatenarListas(&$$->codigo, $3->codigo);
                    definirCodigo($$, "cbr", $3->local, NULL, rotulos);
                    rotulaAposOperacao($$, rotulo1);
                    if($6 !=NULL)
                    {
                        concatenarListas(&$$->codigo, $6->codigo);
                    }
                    definirCodigo($$, "jumpI", NULL, NULL, rotuloInicio);
                    rotulaAposOperacao($$, rotulo2);
                }
                ;

opG0:
        '-'
        {
            $$ = criarNo("-");
        }
        | '!'
        {
            $$ = criarNo("!");
        }
        ;

opG1:
        '*' 
        {
            $$ = criarNo("*");
        }
        | '/' 
        {
            $$ = criarNo("/");
        }
        | '%' 
        {
            $$ = criarNo("%");
        }
        ;

opG2:
        '+' 
        {
            $$ = criarNo("+");
        }
        | '-' 
        {
            $$ = criarNo("-");
        }
        ;

opG3:
        '<' 
        {
            $$ = criarNo("<");
        }
        | '>' 
        {
            $$ = criarNo(">");
        }
        | TK_OC_LE 
        {
            $$ = criarNo("<=");
        }
        | TK_OC_GE 
        {
            $$ = criarNo(">=");
        }
        ;

opG4:
        TK_OC_EQ 
        {
            $$ = criarNo("==");
        }
        | TK_OC_NE 
        {
            $$ = criarNo("!=");
        }
        ;

opAnd:
        TK_OC_AND 
        {
            $$ = criarNo("&");
        }
        ;
                        
opOr:
        TK_OC_OR 
        {
            $$ = criarNo("|");
        }
        ;

expr:                   
        expr1 
        {
            $$ = $1;
        }
        | expr opOr expr1 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);															
            definirTipo($2, inferirTipo(tipo1, tipo2)); 
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3);
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            concatenarListas(&$2->codigo, $1->codigo);
            concatenarListas(&$2->codigo, $3->codigo);
            definirCodigo($2, "or", $1->local, $3->local, $2->local);
            $$ = $2;
        }
        ;

expr1:
        expr2 
        {
            $$ = $1;
        }
        | expr1 opAnd expr2 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);                                                              
            definirTipo($2, inferirTipo(tipo1, tipo2));
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3);
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            concatenarListas(&$2->codigo, $1->codigo);
            concatenarListas(&$2->codigo, $3->codigo);
            definirCodigo($2, "and", $1->local, $3->local, $2->local);
            $$ = $2;                            
        }
        ;

expr2:
        expr3 
        {
            $$ = $1;
        }
        | expr2 opG4 expr3 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);                                                      
            definirTipo($2, inferirTipo(tipo1, tipo2));
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            if(verificaValor($2, "==") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_EQ", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, "!=") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_NE", $1->local, $3->local, $2->local);
            }
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3); 
            $$ = $2;  
        }
        ;

expr3:
        expr4 
        {
        $$ = $1;
        }
        | expr3 opG3 expr4 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);                                                               
            definirTipo($2, inferirTipo(tipo1, tipo2));
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            if(verificaValor($2, ">") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_GT", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, "<") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_LT", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, ">=") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_GE", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, "<=") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "cmp_LE", $1->local, $3->local, $2->local);
            }
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3); 
            $$ = $2;
        }
        ;

expr4:
        expr5 
        {
        $$ = $1;
        } 
        | expr4 opG2 expr5 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);
            definirTipo($2, inferirTipo(tipo1, tipo2));
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            if(verificaValor($2, "+") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "add", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, "-") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "sub", $1->local, $3->local, $2->local);
            }
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3); 
            $$ = $2;
        }
        ;

expr5:
        expr6 
        {
            $$ = $1;
        }
        | expr5 opG1 expr6 
        {
            int tipo1 =  obterTipo($1);
            int tipo2 =  obterTipo($3);
            definirTipo($2, inferirTipo(tipo1, tipo2));
            definirTemporario($2, temporarioDisponivel); temporarioDisponivel++;
            if(verificaValor($2, "*") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "mult", $1->local, $3->local, $2->local);
            }
            else if(verificaValor($2, "/") == 1)
            {
                concatenarListas(&$2->codigo, $1->codigo);
                concatenarListas(&$2->codigo, $3->codigo);
                definirCodigo($2, "div", $1->local, $3->local, $2->local);
            }
            adicionarFilho($2, $1); 
            adicionarFilho($2, $3); 
            $$ = $2;
        }
        ;

expr6:
        expr7 
        {
            $$ = $1;
        }
        | opG0 expr7 
        {
            adicionarFilho($1, $2); 
            $$ = $1;
            definirTipo($1, obterTipo($2)); 
            if(verificaValor($1, "!") == 1)
            {
                definirTemporario($$, temporarioDisponivel); temporarioDisponivel++;
                concatenarListas(&$$->codigo, $2->codigo);
                definirCodigo($$, "not", $2->local, NULL, $$->local);
            }
        }
        ;

expr7:
        operando 
        {
            $$ = $1;
        }
        | '(' expr ')' 
        {
            $$ = $2;
        }
        ;

%%

void yyerror(char const *s){
	printf("ERROR: %s [linha: %d token \"%s\"] \n\n", s,get_line_number(), yytext);
}