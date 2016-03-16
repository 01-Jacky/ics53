#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "my_tools.h"
#include "my_ls.h"
#define PORT 25026
#define BACKLOG 500

int make_socket (uint16_t port)
{
	int sock;
	struct sockaddr_in name;

	// socket
	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		my_error("socket");

	memset(&name, 0, sizeof (name));
	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);

	// bind
	if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
		my_error("bind");
	
	// listen
	if (listen (sock, BACKLOG) == -1)
		my_error("listen");
	return sock;
}

int process_ls(int newsock)
{
	char buf[BUFSIZ];
	int n;
	dup2(newsock, STDOUT_FILENO);
	if ((read(newsock, buf, BUFSIZ)) > 0)
	{
		do_ls(buf);
		return 1;
	}
	else
		return 0;
}


int main(int argc, char** argv) 
{	
	if(argc != 2) 
		exit(-1);
	uint16_t port = atoi(argv[1]);
	int sock = make_socket(port);

	int newsock;
	struct sockaddr_in client;
	socklen_t sin_size;
	sin_size = sizeof (struct sockaddr_in);

	if ((newsock = accept(sock, (struct sockaddr *) &client, &sin_size) ) < 0)
		my_error("accept");

	process_ls(newsock);

	shutdown(sock, 2);
	return 0;
}
