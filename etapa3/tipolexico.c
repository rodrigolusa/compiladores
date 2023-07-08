#include "tipolexico.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TipoLexico* criarTipoLexico(int linha, int tipo, char* valor) {
    TipoLexico* novo_tipo_lexico = (TipoLexico*) malloc(sizeof(TipoLexico));

    novo_tipo_lexico->linha = linha;
    novo_tipo_lexico->tipo = tipo;
    strncpy(novo_tipo_lexico->valor, valor, TAMANHO_MAXIMO);

    return novo_tipo_lexico;
}
