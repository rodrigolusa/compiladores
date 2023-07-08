#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

No* criarNoTipoLexico(TipoLexico* valor_lexico) {
    No* novo_nodo = (No*) malloc(sizeof(No));

    novo_nodo->valor_lexico = valor_lexico;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor_lexico->valor);

    return novo_nodo;
}

No* criarNo(char* valor) {
    No* novo_nodo = (No*) malloc(sizeof(No));

    novo_nodo->valor_lexico = NULL;
    novo_nodo->n_filhos = 0;
    novo_nodo->filhos = NULL;
    strcpy(novo_nodo->valor, valor);

    return novo_nodo;
}