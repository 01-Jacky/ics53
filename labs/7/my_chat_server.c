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
#define BACKLOG 10

int make_socket (uint16_t port)
{
	int sock;
	struct sockaddr_in serv_addr;

	if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ( bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 )
	{	
		perror("bind");
		exit(EXIT_FAILURE);
	}

	return sock;
}

int read_from_client (int filedes)
{
	char buffer[BUFSIZ];
	int nbytes;

	nbytes = read (filedes, buffer, BUFSIZ);
	if (nbytes < 0)
	{
		perror ("read");
		exit (EXIT_FAILURE);
	}
	else if (nbytes == 0)
		return -1;
	else if (strcmp(buffer,"exit\n") == 0) {
		close(filedes);
		return 0;
	}
	else
	{
		fprintf (stderr, "Server: got message: `%s'\n", buffer);
		return 0;
	}
}

int write_to_client (int filedes, char* buf, int nbytes)
{
	return write(filedes, buf, nbytes);
}

int main() 
{
	int sock = make_socket(PORT);
	struct sockaddr_in client_addr;
	fd_set active_set, read_set;

	size_t size;
	if (listen(sock, BACKLOG) < 0 )
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	FD_ZERO(&active_set);
	FD_SET(sock, &active_set);

	while (1)
	{
		read_set = active_set;
		if (select (FD_SETSIZE, &read_set, NULL, NULL, NULL) < 0)
		{
			//error
		}
		int i;
		for (i = 0; i < FD_SETSIZE; i++)
		{
			if(FD_ISSET(i, &read_set))
			{
				if(i == sock)
				{
					int client_fd ;
					size = sizeof(client_addr);
					if (( client_fd = accept(sock, (struct sockaddr *)&client_addr, (socklen_t* )&size) ) < 0)
					{
						perror("accept");
						exit(EXIT_FAILURE);
					}
					FD_SET(client_fd, &active_set);
					
					char buf[6] = "ENTER";
					write(client_fd, buf, 6);

				}
				else
				{
					int read_size;
					char client_message[256];
					while(1)
					{
						read_from_client(i);
					}
				}
			}
		}
	}
		
	
	close(sock);
	return 0;
}
