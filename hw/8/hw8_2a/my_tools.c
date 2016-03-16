#include "my_tools.h"

char* my_fgets(char* str, int num, FILE* stream)
{
	fgets(str, num, stream);
	strip_newline(str);
	return str;
}


void strip_newline(char* word)
{
	char* p;
	if ((p = strchr(word, '\n')) != NULL)
		*p = '\0';
}


void my_error(const char* s)
{
	perror(s);
	exit(1);
}


int read_from(int sockfd, char* buf)
{
	int n;
	if ( (n = read(sockfd, buf, BUFSIZ)) < 0)
	{
		perror("read");
		return 0;
	}
	else if (n == 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


int write_to(int sockfd, char* buf)
{
	int n;
	if ( (n = write(sockfd, buf, strlen(buf))) < 0)
	{
		perror("write");
		return 0;
	}
	else
	{
		return 1;
	}
}
