# Note, you must change the port to your unique port number (between 1000 and 2^16-1) based on your Student ID
PORT = 54321
PROGRAMS = server client
S = -std=c99 -ggdb
O = client.o server.o Timer.o tpr_server.o tpool_server.o

both: $(PROGRAMS) tpr_server tpool_server

server: server.o Timer.o
	gcc $S server.o Timer.o -o server

server.o: server.c
	gcc $S server.c -c

tpool_server: tpool_server.o Timer.o
	gcc $S tpool_server.o Timer.o -lpthread -o tpool_server

tpool_server.o: tpool_server.c
	gcc $S tpool_server.c -c
	
tpr_server: tpr_server.o Timer.o
	gcc $S tpr_server.o Timer.o -lpthread -o tpr_server

tpr_server.o: tpr_server.c
	gcc $S tpr_server.c -c

client: client.o Timer.o
	gcc $S client.o Timer.o -lpthread -o client

client.o: client.c
	gcc $S client.c -c 

Timer.o: Timer.c Timer.h
	gcc -c Timer.c

test: both
	server $(PORT) &
	echo Starting client
	client `hostname` $(PORT)
	ls -lr Thread_*
	du

clean:
	/bin/rm -rf $(PROGRAMS) Thread_* $O tpr_server tpool_server
	clear
