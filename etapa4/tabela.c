#include "tabela.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ChaveSimbolo* criarNomeChave(char* valor) 
{
    ChaveSimbolo* chave = malloc(sizeof(ChaveSimbolo));
    
    strcpy(chave->nomeChave, valor);

    return chave;
}

void definirNomeChave(ChaveSimbolo* chave, char* valor) 
{
    strcpy(chave->nomeChave, valor);
}

char* obterNomeChave(ConteudoTabela* linha) 
{
    return linha->chave->nomeChave;
}

ConteudoTabela* novoConteudo(ChaveSimbolo* chave, char* valorLexico, int linha, enum origemSimbolo origem, enum tipoSemantico tipo) 
{
    ConteudoTabela* linhaTabela = (ConteudoTabela*)malloc(sizeof(ConteudoTabela));

    linhaTabela->chave = (ChaveSimbolo*)malloc(sizeof(ChaveSimbolo));
    strcpy(linhaTabela->chave->nomeChave, chave->nomeChave);

    linhaTabela->linha = linha;
    linhaTabela->origem = origem;
    linhaTabela->tipo = tipo;

    if (valorLexico != NULL) 
    {
        strcpy(linhaTabela->valor, valorLexico);
    } 
    else 
    {
        strcpy(linhaTabela->valor, "0");
    }
    
    linhaTabela->parametros = NULL;

    return linhaTabela;
}

void atualizarTipoConteudo(ConteudoTabela* linha, enum tipoSemantico tipo) 
{
    linha->tipo = tipo;
}

void definirListaParametros(ConteudoTabela* conteudo, ListaChavesSimbolo* lista) 
{
    if (lista != NULL) 
    {
        conteudo->parametros = lista;
    }
}

void adicionarChaveNaLista(char* nome, ListaChavesSimbolo** lista, int tipo, char* valor) 
{
    ListaChavesSimbolo* novaLista = (ListaChavesSimbolo*)malloc(sizeof(ListaChavesSimbolo));
    ChaveSimbolo* chave = criarNomeChave(nome);

    strcpy(novaLista->chave.nomeChave, chave->nomeChave);
    novaLista->tipo = tipo;

    if (valor != NULL)
    {
        strcpy(novaLista->valor, valor);
    }
    else 
    {
        strcpy(novaLista->valor, "0");
    }

    novaLista->proximo = NULL;

    if (*lista != NULL) 
    {
        ListaChavesSimbolo* listaAtual = *lista;

        while (listaAtual->proximo != NULL) 
        {
            listaAtual = listaAtual->proximo;
        }

        listaAtual->proximo = novaLista;
    } 
    else 
    {
        *lista = novaLista;
    }
}
