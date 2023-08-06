#define TAMANHO_MAXIMO 64

enum tipo_lexico 
{
    LEX_LIT_INT, 
    LEX_LIT_FLOAT, 
    LEX_LIT_BOOL, 
    LEX_ID
};

typedef struct TipoLexico 
{
    int linha;
    enum tipo_lexico tipo;
    char valor[TAMANHO_MAXIMO];
} TipoLexico;

TipoLexico* criarTipoLexico(int linha, int tipo, char* valor);
