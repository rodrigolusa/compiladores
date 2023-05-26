all:
	flex scanner.l
	gcc lex.yy.c main.c
flex:
	flex scanner.l
mainc:
	gcc lex.yy.c main.c
test:
	./a.out < test.in > test.out
diff:
	diff test.out expected.out
clean:
	rm lex.yy.c a.out test.out
