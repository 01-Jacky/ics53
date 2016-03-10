#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "my_tools.h"
#define PORT 2892
#define BACKLOG 13

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
	{
		perror("bind");
		exit(1);
	}
	return sock;
}


void welcome_msg(int sockfd, char* username)
{
	read_from(sockfd, username); // get username
	char msg[BUFSIZ];
	snprintf(msg, BUFSIZ, "Welcome, %s", username);
	fprintf(stderr, "%s has entered", username);
	fflush(stderr);
	write_to(sockfd, msg);
}

void process_msg(int sockfd, char* username, char* buf)
{
	read_from(sockfd, buf);
	char msg[BUFSIZ];
	snprintf(msg, BUFSIZ, "%s: %s", username, buf);
	write_to(sockfd, msg);
}


int main() 
{
	int sock, newsock;
	struct sockaddr_in client;
	socklen_t sin_size;
	//fd_set active_set, read_set;
	//int i;
	
	sock = make_socket(PORT);

	// listen
	if (listen (sock, BACKLOG) == -1)
		my_error("listen");

	char buf[BUFSIZ];
	bzero(buf, BUFSIZ); // zero out buf
	sin_size = sizeof (struct sockaddr_in);
	
	if ((newsock = accept(sock, (struct sockaddr *) &client, &sin_size) ) < 0)
		my_error("accept");

	char username[64];
	bzero(username, 64); // zero out username
	welcome_msg(newsock, username);


	while(strcmp(buf, "exit") != 0)
	{
		process_msg(newsock, username, buf);
		
		if (strcmp(buf, "exit") != 0)
			bzero(buf, BUFSIZ); // zero out buf
	}

	close(newsock);
	close(sock);
	shutdown(sock, 2);

	return 0;
}
