
my_ls: main.o my_ls.o 
	@gcc -ggdb my_ls.o main.o -o my_ls
main.o: main.c
	@gcc -c main.c
my_ls.o: my_ls.c
	@gcc -c my_ls.c
clean:
	@rm *.o
