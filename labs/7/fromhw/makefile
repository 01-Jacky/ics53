server: iter_server.o my_tools.o
	gcc iter_server.o my_tools.o -o server

iter_server.o: iter_server.c my_tools.h
	gcc iter_server.c -c

client: client.o my_tools.o
	gcc client.o my_tools.o -o client

client.o: client.c my_tools.h
	gcc client.c -c

my_tools.o: my_tools.c my_tools.h
	gcc my_tools.c -c 

clean:
	rm client server

strip:
