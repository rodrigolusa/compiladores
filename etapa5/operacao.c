#include "operacao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

OperacaoILOC* criarOperacao(char *comando, char *parametro1, char *parametro2, char *destino, char *rotulo_apos)
{
  OperacaoILOC* nova_operacao = (OperacaoILOC*) calloc(1, sizeof(OperacaoILOC));
  
  strncpy(nova_operacao->comando, comando, TAMANHO_MAXIMO);
  if(parametro1 != NULL)
    strncpy(nova_operacao->parametro1, parametro1, TAMANHO_MAXIMO);
  else
    strncpy(nova_operacao->parametro1, "", TAMANHO_MAXIMO);

  if(parametro2 != NULL)
    strncpy(nova_operacao->parametro2, parametro2, TAMANHO_MAXIMO);
  else
    strncpy(nova_operacao->parametro2, "", TAMANHO_MAXIMO);

  if(destino != NULL)
    strncpy(nova_operacao->destino, destino, TAMANHO_MAXIMO);
  else
    strncpy(nova_operacao->destino, "", TAMANHO_MAXIMO);
  
  if(rotulo_apos != NULL)
    strncpy(nova_operacao->rotulo_apos, rotulo_apos, TAMANHO_MAXIMO);
  else
    strncpy(nova_operacao->rotulo_apos, "", TAMANHO_MAXIMO);

  return nova_operacao;
}

void adicionarOperacaoNaLista(ListaOperacaoILOC **lista, OperacaoILOC *operacao)
{
  ListaOperacaoILOC* novaLista = (ListaOperacaoILOC*)malloc(sizeof(ListaOperacaoILOC));
  
  novaLista->operacao = operacao;
  novaLista->proximo = NULL;

  if(*lista != NULL)
  {
    ListaOperacaoILOC* listaAtual = *lista;

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

void concatenarListas(ListaOperacaoILOC **listaPrincipal, ListaOperacaoILOC *listaSecundaria)
{
  if(*listaPrincipal != NULL)
  {
    ListaOperacaoILOC* listaAtual = *listaPrincipal;

    while (listaAtual->proximo != NULL) 
    {
        listaAtual = listaAtual->proximo;
    }

    listaAtual->proximo = listaSecundaria;
  }
  else
  {
    *listaPrincipal = listaSecundaria;
  }
}
