#include "tipolexico.h"

enum tipoSemantico 
{
    TYPE_UNDEFINED,
    TYPE_INT, 
    TYPE_FLOAT, 
    TYPE_BOOL
};

typedef struct astNo
{
    char valor[TAMANHO_MAXIMO];
    TipoLexico *valor_lexico;
    int n_filhos;
    enum tipoSemantico tipo;
    struct astNo** filhos;
} No;

No *criarNoTipoLexico(TipoLexico *valor_lexico);
No *criarNo(char *valor);
void adicionarFilho(No *pai, No *filho);
void imprimirArestas(No *pai);
void imprimirNos(No *pai);
void atualizarValor(No *no);
int verificaValor(No *no, char *val);
int obterTipo(No *no);
void definirTipo(No *no, enum tipoSemantico tipo);
enum tipoSemantico inferirTipo(enum tipoSemantico tipo1, enum tipoSemantico tipo2);