
my_ls: main.o my_ls.o 
	gcc my_ls.o main.o -o my_ls
main.o: main.c
	gcc -ggdb -c main.c
my_ls.o: my_ls.c
	gcc -ggdb -c my_ls.c
clean:
	rm *.o
