#define TAMANHO_MAXIMO 64

typedef struct OperacaoILOC
{
    char comando[TAMANHO_MAXIMO];
    char parametro1[TAMANHO_MAXIMO];
    char parametro2[TAMANHO_MAXIMO];
    char destino[TAMANHO_MAXIMO];
    char rotulo_apos[TAMANHO_MAXIMO];
} OperacaoILOC;

typedef struct ListaOperacaoILOC
{
  OperacaoILOC* operacao;
  struct ListaOperacaoILOC* proximo;
} ListaOperacaoILOC;


OperacaoILOC* criarOperacao(char *comando, char *parametro1, char *parametro2, char *destino, char *rotulo_apos);
void adicionarOperacaoNaLista(ListaOperacaoILOC** lista, OperacaoILOC *operacao);
void concatenarListas(ListaOperacaoILOC** listaPrincipal, ListaOperacaoILOC* listaSecundaria);