#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabeladesimbolos.h"

TDS *criarTabela()
{
  TDS *nova_tabela = (TDS *) calloc(1, sizeof(TDS));
  
  nova_tabela->simbolos = NULL;
  nova_tabela->linhas = 0;
  nova_tabela->tabela_anterior = NULL;
  nova_tabela->tabela_posterior = NULL;

  return nova_tabela;
}

void deletaTabela(TDS *tabela)
{
  TDS *tabela_anterior = tabela->anterior;

  if (tabela_anterior != NULL) {
    tabela_anterior->posterior = NULL;
  }

  free(tabela);
}

void adicionarLinha(TDS *tabela, Simbolo *linha)
{
  tabela->simbolos = realloc(tabela->simbolos, (tabela->linhas + 1) * sizeof(Simbolo));
  tabela->simbolos[tabela->linhas] = linha;
  tabela->linhas = tabela->linhas + 1;
}

TDS* adicionarTabela(TDS *tabela)
{
  TDS *nova_tabela = (TDS *) calloc(1, sizeof(TDS));

  nova_tabela->simbolos = NULL;
  nova_tabela->linhas = 0;
  nova_tabela->tabela_anterior = tabela;
  nova_tabela->tabela_posterior = NULL;

  tabela->tabela_posterior = nova_tabela;

  return nova_tabela;
}

char *consultarTabela(TDS *tabela, char *identificador)
{
  for(int i = 0; i < tabela->linhas; i++) {
    if(strcmp(identificador, tabela->simbolos[i]) == 0) {
      return tabela->simbolos[i]->valor;
    }
  }
  
  return NULL;
}

char *consultarTabelas(TDS *tabela, char *identificador)
{
  TDS *tabela_atual = tabela;
  TDS *tabela_anterior = tabela->tabela_anterior;
  char *value;
  
  while(tabela_anterior != NULL) {
    value = consultarTabela(tabela_atual, identificador);
    
    if(value == NULL) {
      tabela_atual = tabela_anterior;
      tabela_anterior = tabela_atual->tabela_anterior;
    } else {
      return value;
    }
  }

  value = consultarTabela(tabela_atual, identificador);
  
  return (value == NULL ? NULL : value);
}
