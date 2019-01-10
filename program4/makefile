All: program4 run  memcheck clean
	echo "All set"
run: program4
	./program4
memcheck:program4
	valgrind ./program4
program4:tournament.o program4.o
	gcc -g tournament.o program4.o -o program4
tournament.o:tournament.c 
	gcc -g -c tournament.c
program4.o: program4.c
	gcc -g -c program4.c
clean:
	rm tournament.o
	rm program4.o
	rm program4

