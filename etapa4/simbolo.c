#include "simbolo.h"

Simbolo *criarSimbolo(char *identificador, int linha, int natureza, int tipo, char *valor)
{
  Simbolo *novo_simbolo = (Simbolo *) calloc(1, sizeof(Simbolo));

  strncpy(novo_simbolo->identificador, identificador, TAMANHO_MAXIMO);
  novo_simbolo->linha = linha;
  novo_simbolo->natureza = natureza;
  novo_simbolo->tipo = tipo;
  strncpy(novo_simbolo->valor, valor, TAMANHO_MAXIMO);

  return novo_simbolo;
}
