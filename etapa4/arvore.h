#include "tipolexico.h"

enum tipo {
    tINT, 
    tFLOAT, 
    tBOOL,
    tIndefinido
};

typedef struct astNo
{
    char valor[TAMANHO_MAXIMO];
    TipoLexico *valor_lexico;
    enum tipo tipo;
    int n_filhos;
    struct astNo** filhos;
} No;

No *criarNoTipoLexico(TipoLexico *valor_lexico, int tipo);
No *criarNo(char *valor, int tipo);
void adicionarFilho(No *pai, No *filho);
void imprimirArestas(No *pai);
void imprimirNos(No *pai);
void atualizarValor(No *no);
void atualizarTipo(No *no, int tipo);
int verificaValor(No *no, char *val);