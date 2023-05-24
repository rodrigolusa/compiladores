all:
	flex scanner.l
	gcc lex.yy.c main.c
flex:
	flex scanner.l
mainc:
	gcc lex.yy.c main.c
test:
	./a.out < test.in > test.out
test2:
	./a.out < test2.in > test2.out
test3:
	./a.out < test3.in > test3.out
diff:
	diff test.out expected.out
clean:
	rm lex.yy.c a.out test.out
