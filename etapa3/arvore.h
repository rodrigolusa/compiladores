#include "tipolexico.h"

typedef struct astNo
{
    char valor[TAMANHO_MAXIMO];
    TipoLexico *valor_lexico;
    int n_filhos;
    struct astNo **filhos;
} No;

No *criarNoTipoLexico(TipoLexico *valor_lexico);
No *criarNo(char *valor);
void adicionarFilho(No *pai, No *filho);
void imprimirArestas(No *pai);
void imprimirNos(No *pai);
void imprimirFilhos(No *pai);
void atualizarValor(No* no);