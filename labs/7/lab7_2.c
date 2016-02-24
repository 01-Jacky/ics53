#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>


#define PORT 7533

int main(int argc, char** argv) {
	int sockfd, numbytes;
	char buf[512];
	struct hostent *he;
	struct sockaddr_in their_addr;
	if(he= gethostbyname(argv[1]) == NULL)
	{
		//error
	}
	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		//error
	}
	
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);
	their_addr.sin_addr = *((struct in_addr *) he->h_addr);
	memset(&(their_addr.sin_zero), '\0', 8);

	if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		//error
	}

}

