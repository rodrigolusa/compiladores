etapa3: tipolexico.o arvore.o parser.tab.o lex.yy.o main.o
	gcc -o etapa3 parser.tab.o lex.yy.o tipolexico.o arvore.o main.o
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
clean:
	rm *.o lex.yy.c parser.tab.c etapa3
teste:
	./etapa3 < input.txt > output.txt