execute: execute.o
	@gcc execute.o -o execute

execute.o: execute.c
	@gcc -c execute.c

my_fork: my_fork.o
	@gcc my_fork.o -o my_fork

my_fork.o: my_fork.c
	@gcc -c my_fork.c
	
clean:
	@rm *.o execute my_fork
