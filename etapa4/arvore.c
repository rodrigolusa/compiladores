#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

extern void exporta(void *arvore);

No *criarNoTipoLexico(TipoLexico *valor_lexico)
{
    No *novo_nodo = (No *) calloc(1, sizeof(No));

    novo_nodo->valor_lexico = valor_lexico;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor_lexico->valor);

    return novo_nodo;
}

No *criarNo(char *valor)
{
    No *novo_nodo = (No *) calloc(1, sizeof(No));

    novo_nodo->valor_lexico = NULL;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor);

    return novo_nodo;
}

void adicionarFilho(No *pai, No *filho)
{
    if (filho != NULL) {
        if (pai->n_filhos == 0) {
            size_t tamanhoNo = sizeof(struct astNo);
            pai->filhos = malloc(tamanhoNo); // Assuming an initial size
        } else {
            size_t tamanhoNo = sizeof(struct astNo);
            pai->filhos = realloc(pai->filhos, (pai->n_filhos + 1) * tamanhoNo);
        }

        pai->filhos[pai->n_filhos] = filho;
        pai->n_filhos++;
    }
}

void imprimirArestas(No *pai)
{
    int t_filhos = pai->n_filhos;
    int i = 0;

    while(t_filhos > 0) {
        printf("%p, %p\n", pai, pai->filhos[i]);
	i++;
	t_filhos--;
    }

    t_filhos = pai->n_filhos;
    i = 0;

    while(t_filhos > 0) {
        imprimirArestas(pai->filhos[i]);
	i++;
	t_filhos--;
    }
}

void imprimirNos(No *pai)
{
    int t_filhos = pai->n_filhos;
    int i = 0;

    if(strcmp(pai->valor, "condicional") == 0)
        printf("%p [label=\"if\"];\n", pai);
    else
        printf("%p [label=\"%s\"];\n", pai, pai->valor);

    while(t_filhos > 0) {
        imprimirNos(pai->filhos[i]);
        i++;
        t_filhos--;
    }
}

void exporta(void *arvore)
{
    No *pai = (No*) arvore;
    
    if(arvore != NULL) {
        imprimirArestas(arvore);
        printf("\n\n");
        imprimirNos(arvore);
    }
    
}

void atualizarValor(No* no) 
{
    if (strcmp(no->valor, "condicional") == 0) {
        strcpy(no->valor, "condicional_complement");
        return;
    }

    if (no->valor_lexico != NULL && no->valor_lexico->tipo == LEX_ID) {
        char dummy[TAMANHO_MAXIMO];
        strcpy(dummy, "call ");
	    strcat(dummy, no->valor);
        strcpy(no->valor, dummy);
    }
}

int verificaValor(No* no, char *valor) 
{
    if(strcmp(no->valor, valor) == 0)
    {
        return 1;
    }
    else
    {
	    return 0;
    }
}

int obterTipo(No* no)
{	
	return no->tipo;
}

void definirTipo(No* no, enum tipoSemantico tipo) 
{ 
    no->tipo = tipo;
}

enum tipoSemantico leracionamentoTipos[][4] = {
    // TYPE_INT         TYPE_FLOAT          TYPE_BOOL           TYPE_UNDEFINED
    { TYPE_INT,         TYPE_FLOAT,         TYPE_INT,           TYPE_UNDEFINED },  // TYPE_INT
    { TYPE_FLOAT,       TYPE_FLOAT,         TYPE_FLOAT,         TYPE_UNDEFINED },  // TYPE_FLOAT
    { TYPE_INT,         TYPE_FLOAT,         TYPE_BOOL,          TYPE_UNDEFINED },  // TYPE_BOOL
    { TYPE_UNDEFINED,   TYPE_UNDEFINED,     TYPE_UNDEFINED,     TYPE_UNDEFINED }  // TYPE_UNDEFINED
};

enum tipoSemantico inferirTipo(enum tipoSemantico tipo1, enum tipoSemantico tipo2)
{
    return leracionamentoTipos[tipo1][tipo2];
}

