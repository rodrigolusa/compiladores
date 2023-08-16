#include <stdio.h>
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
void exporta_iloc (void *arvore);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  // exporta (arvore);
  exporta_iloc(arvore);
  yylex_destroy();
  return ret;
}
