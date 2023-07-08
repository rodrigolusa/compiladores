%{
    #include "arvore.h"
    #include "parser.tab.h"
%}
%option noyywrap
%option yylineno

%x COMMENT

carac_normais [-!*/%+<>{}()=,;]

%%

"//".*
"/*"    BEGIN(COMMENT);

{carac_normais} { return  yytext[0]; }

int               return TK_PR_INT;
float             return TK_PR_FLOAT;
bool              return TK_PR_BOOL;
if                return TK_PR_IF;
else              return TK_PR_ELSE;
while             return TK_PR_WHILE;
return            return TK_PR_RETURN;

"<="              return TK_OC_LE;
">="              return TK_OC_GE;
"=="              return TK_OC_EQ;
"!="              return TK_OC_NE;
"&"               return TK_OC_AND;
"|"               return TK_OC_OR;
"->"              return TK_OC_MAP;

[0-9]+          { 
                    yylval.valor_lexico = criarTipoLexico(yylineno, LEX_LIT_INT, strdup(yytext)); 
                    return TK_LIT_INT; 
                }

[0-9]*"."[0-9]+ {
                    yylval.valor_lexico = criarTipoLexico(yylineno, LEX_LIT_FLOAT, strdup(yytext)); 
                    return TK_LIT_FLOAT;
                }

false           {
                    yylval.valor_lexico = criarTipoLexico(yylineno, LEX_LIT_BOOL, strdup(yytext)); 
                    return TK_LIT_FALSE; 
                }

true            {
                    yylval.valor_lexico = criarTipoLexico(yylineno, LEX_LIT_BOOL, strdup(yytext)); 
                    return TK_LIT_TRUE; 
                }

[a-z_]+         {
                    yylval.valor_lexico = criarTipoLexico(yylineno, LEX_ID, strdup(yytext)); 
                    return TK_IDENTIFICADOR; 
                }

" "
"\n"              yylineno;
"\t"
"\r"

.                 return TK_ERRO;

<COMMENT>.
<COMMENT>"\n"   yylineno;
<COMMENT>"*/"  BEGIN(INITIAL);

%%

int get_line_number(void) {
    return yylineno;
}
