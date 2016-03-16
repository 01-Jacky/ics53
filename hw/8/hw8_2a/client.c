#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "my_tools.h"
#define PORT 25026

int make_socket (uint16_t port, char* hostname)
{
	int sockfd;
	struct hostent *he;
	struct sockaddr_in their_addr;
	if((he = gethostbyname(hostname)) == NULL)
		my_error("gethost");
	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		my_error("socket");
	
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *) he->h_addr);
	memset(&(their_addr.sin_zero), '\0', 8); // make rest 0
	if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
		my_error("connect");
	return sockfd;
}


void recv_msg(int sockfd, char* reply)
{
	read_from(sockfd, reply);
	printf("%s\n", reply);
	fflush(stdout);
}

void read_from_server(int sockfd)
{
	char buf[BUFSIZ];
	int n;
	while ((n = read(sockfd, buf, BUFSIZ)) > 0)
		write(1, buf, n);
}


int main(int argc, char** argv) 
{
	if(argc < 3)
		exit(-1);
	uint16_t port = atoi(argv[2]);
	int sock = make_socket(port, argv[1]);
	
	int i = 3;
	while ( i < argc )
	{
		write(sock, argv[i], strlen(argv[i]));
		read_from_server(sock);
		i++;
	}
	close(sock);

	return 0;
}

