#include "arvore.h"

#define ERR_UNDECLARED 10
#define ERR_DECLARED 11
#define ERR_VARIABLE 20
#define ERR_FUNCTION 21

enum origemSimbolo {
    LIT_SYMBOL,
    ID_SYMBOL,
    FUN_SYMBOL
};

typedef struct ChaveSimbolo {
    char nomeChave[TAMANHO_MAXIMO];
} ChaveSimbolo;

typedef struct ListaChavesSimbolo {
    ChaveSimbolo chave;
    enum tipoSemantico tipo;
    char valor[TAMANHO_MAXIMO];
    struct ListaChavesSimbolo* proximo;
} ListaChavesSimbolo;

typedef struct ConteudoTabela {
    ChaveSimbolo* chave;
    int linha;
    enum origemSimbolo origem;
    enum tipoSemantico tipo;
    char valor[TAMANHO_MAXIMO];
    ListaChavesSimbolo* parametros;
} ConteudoTabela;

ChaveSimbolo* criarNomeChave(char* valor);
void definirNomeChave(ChaveSimbolo* chave, char* valor);
char* obterNomeChave(ConteudoTabela* linha);
ConteudoTabela* novoConteudo(ChaveSimbolo* chave, char* valor_lexico, int linha, enum origemSimbolo nat, enum tipoSemantico tipo);
void atualizarTipoConteudo(ConteudoTabela* linha, enum tipoSemantico tipo);
void definirListaParametros(ConteudoTabela* conteudo, ListaChavesSimbolo* lista);
void adicionarChaveNaLista(char* nome, ListaChavesSimbolo** lista, int tipo, char* valor);
