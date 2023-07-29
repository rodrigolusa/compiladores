#define TAMANHO_MAXIMO 64

enum natureza {
    nLIT,
    nID,
    nFUN
};

enum tipo {
    tINT, 
    tFLOAT, 
    tBOOL, 
};

typedef struct Simbolo
{
    char identificador[TAMANHO_MAXIMO];
    int linha;
    enum natureza natureza;
    enum tipo tipo;
    char valor[TAMANHO_MAXIMO];
} Simbolo;

Simbolo *criarSimbolo(char *identificador, int linha, int natureza, int tipo, char *valor);
