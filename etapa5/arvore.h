#include "tipolexico.h"
#include "operacao.h"

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
    ListaOperacaoILOC *codigo;
    char local[TAMANHO_MAXIMO];
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
void definirTemporario(No *no, int temporarioDisponivel);
void definirCodigo(No *no, char *comando, char *parametro1, char *parametro2, char *destino);
char *definirRotulo(int rotuloDisponivel);
void rotulaAposOperacao(No *no, char *rotulo);
