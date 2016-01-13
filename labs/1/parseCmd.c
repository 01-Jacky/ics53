#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*int parseNumber()
{
	while (isdigit(peekc()))
		getchar();
	return ; 
}
int parseWord()
{
	while (isalnum(peekc()))
		getchar();
	return word;
}*/
char lexeme[100];
int getToken() 
{
	int ch;
	char buffer[100];
	int index = 0;
	while ((ch = getchar()) != '\0')
	{	
		switch(ch)
		{
			case ' ':
			case '\t':
			case '\n':
				return '\n';dd
				break;
			case '&':
			case '|':
			case '<':
			case '>':
				return ch;
			default:
				int a = getc();
			    char* final_buffer;
				ungetc(a);
				switch(a)
				{   
					case ' ':
					case '\t':
					case '\n':
					case '&':
					case '|':
					case '<':
					case '>':
						strcpy(final_buffer, buffer);
						index = 0;
						return final_buffer;
				}
				buffer[index] = ch;
				index++;
				break;
		}
				
	}
}


int main() 
{
	//char* line;
	//fgets(line, 200, stdin);
	printf("%c", getToken());
	return 0;
}
