#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 2892
#define BACKLOG 13

int read_from_client (int fd, char* buf)
{
	int nbytes;

	if ((nbytes = read(fd, buf, BUFSIZ)) < 0 )
	{
		return 1;
	}
	else if (nbytes == 0)
	{
		//EOF
		return -1;
	}
	else
	{
		printf("%s\n", buf);
		return 0;
	}
}

int make_socket (uint16_t port)
{
	int sock;
	struct sockaddr_in name;

	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{	
		perror("socket");
		exit(1);
	}
	memset(&name, 0, sizeof (name));
	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
	{
		perror("bind");
		exit(1);
	}
	return sock;
}


int main() 
{
	int sock;
	fd_set active_set, read_set;
	char buf[1024];
	int i;
	struct sockaddr_in client;
	socklen_t size;
	
	sock = make_socket(PORT);

	if (listen (sock, BACKLOG) == -1)
	{
		perror("listen");
		exit(1);
	}

	sin_size = sizeof (struct sockaddr_in);

	shutdown();
	return 0;
}
