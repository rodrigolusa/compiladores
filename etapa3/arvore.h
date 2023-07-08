#include "tipolexico.h"

typedef struct astNo {
    char valor[TAMANHO_MAXIMO];
    TipoLexico* valor_lexico;
    int n_filhos;
    struct astNo** filhos;
} No;

No* criarNoTipoLexico(TipoLexico* valor_lexico);
No* criarNo(char* valor);
