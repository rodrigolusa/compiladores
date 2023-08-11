#Grupo P -> João Carlos Almeida da Silva - Rodrigo Antonio Rezende Lusa

etapa5: tipolexico.o arvore.o tabela.o escopo.o parser.tab.o lex.yy.o main.o
	gcc -o etapa5 parser.tab.o lex.yy.o tipolexico.o arvore.o tabela.o escopo.o main.o
main.o: main.c
	gcc -c main.c
parser.tab.o: parser.tab.c
	gcc -c parser.tab.c
parser.tab.c: parser.y arvore.h
	bison -d parser.y
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
lex.yy.c: scanner.l
	flex scanner.l 
tipolexico.o: tipolexico.c tipolexico.h
	gcc -c tipolexico.c
arvore.o: arvore.c arvore.h tipolexico.h
	gcc -c arvore.c
tabela.o: tabela.h arvore.h tabela.c
	gcc -c tabela.c
escopo.o: tabela.h escopo.h escopo.c
	gcc -c escopo.c
clean:
	rm *.o lex.yy.c parser.tab.c etapa5