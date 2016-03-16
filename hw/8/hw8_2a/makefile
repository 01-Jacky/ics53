server: iter_server.o my_tools.o my_ls.o
	gcc iter_server.o my_tools.o my_ls.o -o server

iter_server.o: iter_server.c my_tools.h my_ls.h
	gcc -ggdb iter_server.c -c 

client: client.o my_tools.o
	gcc client.o my_tools.o -o client

client.o: client.c my_tools.h
	gcc -ggdb client.c -c 

my_tools.o: my_tools.c my_tools.h
	gcc -ggdb my_tools.c -c 

my_ls.o: my_ls.c my_ls.h
	gcc -ggdb my_ls.c -c 

clean:
	rm client server *.o

strip:
	strip *.o

