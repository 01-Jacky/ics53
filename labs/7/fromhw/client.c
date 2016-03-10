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
#define PORT 2892



void send_msg(int sockfd, char* buf)
{
	write_to(sockfd, buf);
}

void recv_msg(int sockfd, char* reply)
{
	read_from(sockfd, reply);
	printf("%s\n", reply);
	fflush(stdout);
}


int main(int argc, char** argv) 
{
	// =======================================
	// 			USERNAME STUFF
	// =======================================
	char username[64] = "";
	if (argc == 3) 
		strcpy(username, argv[2]);
	else
	{
		printf("Enter username: ");
		my_fgets(username, 64, stdin);
	}
	

	// =======================================
	// 			SOCKET STUFF
	// =======================================
	int sockfd, numbytes;
	struct hostent *he;
	struct sockaddr_in their_addr;
	if((he = gethostbyname(argv[1])) == NULL)
		my_error("gethost");
	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		my_error("socket");
	
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr = *((struct in_addr *) he->h_addr);
	memset(&(their_addr.sin_zero), '\0', 8); // make rest 0

	if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
		my_error("connect");
	
	// =======================================
	// 			MESSAGING STUFF
	// =======================================
	char message[BUFSIZ], reply[BUFSIZ];
	bzero(message, BUFSIZ);
	bzero(reply, BUFSIZ);

	send_msg(sockfd, username);
	recv_msg(sockfd, reply);
	
	while ( strcmp(message, "exit")!= 0 )
	{
		my_fgets(message, BUFSIZ, stdin);
		send_msg(sockfd, message);
		bzero(reply, BUFSIZ);
		recv_msg(sockfd, reply);
	}
	close(sockfd);

	return 0;
}

