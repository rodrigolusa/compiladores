#include "tabela.h"
#include <stdlib.h>

#define TAMANHO_TABELA 32

typedef struct ItemEscopo 
{
    ConteudoTabela* conteudo;
    struct ItemEscopo* proximo;
} ItemEscopo;

typedef struct Escopo 
{
    int altura;
    int tamanho;
    int contagem;
    ItemEscopo** lexemas;
    struct Escopo* escopoAnterior;
} Escopo;

Escopo* criarTabela(Escopo* atual);
Escopo* desempilharTabela(Escopo* topo) ;
ItemEscopo* criarItemEscopo(ConteudoTabela* conteudo);
int calculaIndice(ChaveSimbolo* chave);
void adicionarNaTabela(ConteudoTabela* conteudo, Escopo* tabela, int linha);
ConteudoTabela* procurarNaTabela(ChaveSimbolo* chave, Escopo* tabela);
void verificaConteudoID(int origem, int linha);
void verificarConteudoFUN(int origem, int linha);
ConteudoTabela* procurarNaPilhaDeTabelas(ChaveSimbolo* chave, Escopo* topo, int origem, int linha);

