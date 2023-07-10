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
    int n_filhos = pai->n_filhos;
    int i = 0;

    while (n_filhos > 0) {
        printf("%p, %p\n", pai, pai->filhos[i]);
        imprimirArestas(pai->filhos[i]);
        i++;
        n_filhos--;
    }
}

void imprimirNos(No *pai)
{
    int n_filhos = pai->n_filhos;
    int i = 0;

    int isIfElse = (strcmp(pai->valor, "condicional_complement") == 0);

    if (isIfElse)
        printf("%p [label=\"if\"];\n", pai);
    else
        printf("%p [label=\"%s\"];\n", pai, pai->valor);

    while (n_filhos > 0) {
        imprimirNos(pai->filhos[i]);
        i++;
        n_filhos--;
    }
}

/*
void imprimirFilhos(No *pai)
{
    for (int i = 0; i < pai->n_filhos; i++)
    {
        imprimirFilhos(pai->filhos[i]);
    }
}
*/

void exporta(void *arvore)
{
    No *pai = (No *)arvore;

    //imprimirArestas(arvore);
    //imprimirNos(arvore);
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

int verificaValor(No* no, char *val) {
    if(strcmp(no->valor, val) == 0)
        return 1;
    else
	return 0;
}
