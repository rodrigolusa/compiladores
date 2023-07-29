#include "simbolo.h"

typedef struct TabelaDeSimbolos
{
    Simbolo *simbolos;
    int linhas;
    TDS **tabela_anterior;
    TDS **tabela_posterior;
} TDS;

TDS *criarTabela();
void deletaTabela(TDS *tabela);

void adicionarLinha(TDS *tabela, Simbolo *linha);
TDS *adicionarTabela(TDS *tabela);
char *consultarTabela(TDS *tabela, char *identificador);
char *consultarTabelas(TDS *tabela, char *identificador);
