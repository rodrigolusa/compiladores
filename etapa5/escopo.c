#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escopo.h"

Escopo* criarTabela(Escopo* atual) 
{
    Escopo* tabela = (Escopo*)malloc(sizeof(Escopo));
    
    if(atual != NULL) 
    {
        tabela->escopoAnterior = (Escopo*)malloc(sizeof(Escopo));
        tabela->altura = atual->altura + 1;
        tabela->escopoAnterior = atual;
    }
    else 
    {
        tabela->altura = 0;
        tabela->escopoAnterior = NULL;
    }

    tabela->tamanho = TAMANHO_TABELA;
    tabela->contagem = 0;
    tabela->lexemas = malloc(TAMANHO_TABELA * sizeof(ItemEscopo));

    int count = 0;
    while(count<TAMANHO_TABELA)
    {
        tabela->lexemas[count] = NULL;
        count++;
    }
    return tabela;
}

Escopo* desempilharTabela(Escopo* topo) 
{
    int count = 0;

    while(count < TAMANHO_TABELA)
    {
        ItemEscopo* item = topo->lexemas[count];
        while(item != NULL) 
        {
            free(item->conteudo->chave);
            ListaChavesSimbolo* parametros = item->conteudo->parametros;
            while(parametros != NULL) {
                ListaChavesSimbolo* anterior = parametros;
                parametros = parametros->proximo;
                free(anterior);
            }
            free(item->conteudo);
            ItemEscopo* anterior = item;
            item = item->proximo;
            free(anterior);
        }
        count++;
    }

    Escopo* novoTopo = topo->escopoAnterior;
    free(topo);

    return novoTopo; 
}

ItemEscopo* criarItemEscopo(ConteudoTabela* conteudo) 
{
    ItemEscopo* item = (ItemEscopo*)malloc(sizeof(ItemEscopo));

    item->conteudo = conteudo;
    item->proximo = NULL;

    return item;
}

int calculaIndice(ChaveSimbolo* chave) 
{
    int ret = 0;
    int controle = 0;

    while(controle < strlen(chave->nomeChave))
    {
        ret += (int)chave->nomeChave[controle];
        controle++;
    }

    ret = ret % TAMANHO_TABELA;

    return ret;
}

void adicionarNaTabela(ConteudoTabela* conteudo, Escopo* tabela, int linha) 
{
    int indice = calculaIndice(conteudo->chave);

    ItemEscopo* atual = tabela->lexemas[indice];

    while (atual != NULL) 
    {
        if ((strcmp(obterNomeChave(atual->conteudo), obterNomeChave(conteudo)) == 0) && (conteudo->origem != LIT_SYMBOL)) 
        {
            printf("ERROR: A variável ou função \"%s\" declarada na linha %d já foi declarada anteriormente na linha %d\n", obterNomeChave(conteudo), linha, atual->conteudo->linha);
            exit(ERR_DECLARED);
        } 
        else if ((strcmp(obterNomeChave(atual->conteudo), obterNomeChave(conteudo)) == 0) && (conteudo->origem == LIT_SYMBOL)) 
        {
			return;
		}

        atual = atual->proximo;
    }

    ItemEscopo* novoItem = criarItemEscopo(conteudo);

    novoItem->proximo = tabela->lexemas[indice];
    tabela->lexemas[indice] = novoItem;
    tabela->contagem++;
}

ConteudoTabela* procurarNaTabela(ChaveSimbolo* chave, Escopo* tabela) 
{
    int indice = calculaIndice(chave);

    ItemEscopo* atual = tabela->lexemas[indice];
    
    while (atual != NULL) 
    {
        if (strcmp(obterNomeChave(atual->conteudo), chave->nomeChave) == 0) 
        {
            return atual->conteudo;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void verificaConteudoID(int origem, int linha) 
{
    if(origem != ID_SYMBOL && origem == FUN_SYMBOL) 
    {
        printf("ERROR: Uma função foi usada como variável na linha: %d\n", linha);
        exit(ERR_FUNCTION);
    }
}

void verificarConteudoFUN(int origem, int linha) 
{
    if(origem != FUN_SYMBOL && origem == ID_SYMBOL) 
    {
        printf("ERROR: Uma variável foi usada como função na linha: %d\n", linha);
        exit(ERR_VARIABLE);
    }
}

ConteudoTabela* procurarNaPilhaDeTabelas(ChaveSimbolo* chave, Escopo* topo, int origem, int linha) 
{
    Escopo* pilha = topo;
    ConteudoTabela* conteudo = NULL;

    int contador = 0;

    while(pilha != NULL && conteudo == NULL) 
    {
        conteudo = procurarNaTabela(chave, pilha);

        if(conteudo != NULL) 
        {
            if(origem == ID_SYMBOL)
            {
                verificaConteudoID(conteudo->origem, linha);
            }
            else if(origem == FUN_SYMBOL)
            {
                verificarConteudoFUN(conteudo->origem, linha);
            }

            return conteudo;
        }

        contador++;
        pilha = pilha->escopoAnterior;
    }

    printf("ERROR: A variável ou função \"%s\" usada na linha %d não foi declarada\n", chave->nomeChave, linha);
    exit(ERR_UNDECLARED);
}

int chaveEscopoGlobal(ChaveSimbolo* chave, Escopo* topo, int origem, int linha)
{
    Escopo* pilha = topo;
    ConteudoTabela* conteudo = NULL;

    int contador = 0;

    while(pilha != NULL && conteudo == NULL) 
    {
        conteudo = procurarNaTabela(chave, pilha);

        if(conteudo != NULL) 
        {
            if(origem == ID_SYMBOL)
            {
                verificaConteudoID(conteudo->origem, linha);
            }
            else if(origem == FUN_SYMBOL)
            {
                verificarConteudoFUN(conteudo->origem, linha);
            }

            if(pilha->escopoAnterior == NULL)
                return 1; // Sim, Escopo Global
            else
                return 0; // Não, Escopo Local
        }

        contador++;
        pilha = pilha->escopoAnterior;
    }

    return -1;
}
