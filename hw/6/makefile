CC=gcc
CFLAGS=-ggdb

my_shell: my_shell.o
	$(CC) my_shell.o -o my_shell

my_shell.o: my_shell.c
	$(CC) my_shell.c -c $(CFLAGS)

hw6_2: hw6_2.c
	$(CC) hw6_2.c -o hw6_2

clean:
	rm *.o my_shell hw6_2

