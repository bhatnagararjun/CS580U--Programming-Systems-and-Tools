all: program5
program5: program5.o list.o vector.o stack.o queue.o
	gcc -g  program5.o list.o vector.o stack.o queue.o -o program5
program5.o: program5.c
	gcc -g -c program5.c -o program5.o
list.o: list.c
	gcc -g -c list.c -o list.o
vector.o: vector.c
	gcc -g -c vector.c -o vector.o
stack.o: stack.c
	gcc -g -c stack.c -o stack.o
queue.o: queue.c
	gcc -g -c queue.c -o queue.o
run: program5
	./program5
checkmem: program5.c
	valgrind ./program5
clean:
	rm program5 *.o
