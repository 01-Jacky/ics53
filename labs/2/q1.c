#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_URL_LENGTH 200

void checkScheme(char* buff, char ch) 
{
	char after_scheme[4];
	after_scheme[0] = ch;
	if(ch == ':') //&& (ch = getchar()) == '/' && (ch = getchar()) == '/')
	{	
		after_scheme[1] = getchar();
		after_scheme[2] = getchar();
		after_scheme[3] = '\0';
		if (strcmp(after_scheme, "://") == 0)
		{
			printf("Scheme: %s\n", buff);
		}
		else
		{
			ungetc(after_scheme[2], stdin);
			ungetc(after_scheme[1], stdin);
		}
	}
	else
	{
		ungetc(after_scheme[0], stdin);
	}
}

void checkDomain(char* buff, char ch)
{
	int cnt = 0;
	char* dch, pch;
	while((ch = getchar()) != '/')
	{	
		buff[cnt++] = ch;
	}
	buff[cnt++] = '/';
	buff[cnt] = '\0';
	printf("%s\n", buff);
	dch = strtok(buff, ":/");
	printf("Domain: %s\n", dch);
	pch = strtok(buff, ":/");
		printf("Port: %s\n", pch);
}

int main() 
{
	char url[MAX_URL_LENGTH];
	char buff[200];
	char* dom;
	char ch;
	int cnt = 0;
	while(isalpha(ch = getchar()))
	{
		buff[cnt++] = ch;
	}
	buff[cnt]='\0';
	checkScheme(buff, ch);
	checkDomain(buff, ch);

	return 0;
}
