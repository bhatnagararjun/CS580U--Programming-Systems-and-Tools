all: program6
program6: program6.o bst.o
	gcc -g program6.o bst.o -o program6
program6.o: program6.c
	gcc -g -c program6.c -o program6.o
bst.o: bst.c
	gcc -g -c bst.c -o bst.o
run: program6
	./program6
checkmem: program6.c
	valgrind ./program6
clean:
	rm program6 *.o
