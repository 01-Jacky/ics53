#include <stdio.h>
#include <string.h>
char lexeme[200];

void getToken()
{
	int ch;
	while ((ch =getchar()) != '\0')
	{
		if(ch == ' ') {
			printf("\n");
		}
		if(ch == '<' || ch == '>' || ch == '&' || ch == '|') {
			printf("\n%c\n", ch);
		}
		else
			printf("%c", ch);
	}
}


int main()
{	
	getToken();
	return 0;
}
