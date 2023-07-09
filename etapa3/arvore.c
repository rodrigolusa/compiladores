#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

extern void exporta(void *arvore);

No *criarNoTipoLexico(TipoLexico *valor_lexico)
{
    No *novo_nodo = (No *)malloc(sizeof(No));

    novo_nodo->valor_lexico = valor_lexico;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor_lexico->valor);

    return novo_nodo;
}

No *criarNo(char *valor)
{
    No *novo_nodo = (No *)malloc(sizeof(No));

    novo_nodo->valor_lexico = NULL;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor);

    return novo_nodo;
}

void adicionarFilho(No *pai, No *filho)
{
    pai->filhos = (No **)realloc(pai->filhos, (pai->n_filhos + 1) * sizeof(No *));
    pai->filhos[pai->n_filhos] = filho;
    pai->n_filhos++;
}

void imprimirArestas(No *pai)
{
    for (int i = 0; i < pai->n_filhos; i++)
    {
        printf("%p, %p\n", pai, pai->filhos[i]);
    }

    for (int i = 0; i < pai->n_filhos; i++)
    {
        imprimirArestas(pai->filhos[i]);
    }
}

void imprimirNos(No *pai)
{
    printf("%p [label=\"%s\"];\n", pai, pai->valor);

    for (int i = 0; i < pai->n_filhos; i++)
    {
        imprimirNos(pai->filhos[i]);
    }
}

void imprimirFilhos(No *pai)
{
    for (int i = 0; i < pai->n_filhos; i++)
    {
        imprimirFilhos(pai->filhos[i]);
    }
}

void exporta(void *arvore)
{
    No *pai = (No *)arvore;

    imprimirArestas(arvore);
    imprimirNos(arvore);
}

void atualizarValor(No* no) 
{
    if (no->valor[0] == 'c' && strcmp(no->valor, "condicional") == 0)
    {
        strcpy(no->valor, "condicional_complement");
    }
    else if (no->valor_lexico->tipo == LEX_ID) 
    {
        strcat(no->valor, "call ");
    }
}

int verificaValor(No* no, char *val) {
    if(strcmp(no->valor, val) == 0)
        return 1;
    else
	return 0;
}
