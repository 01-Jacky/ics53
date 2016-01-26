#include <stdio.h>
#include <string.h>
#include <ctype.h>
// PARSE C

int peekc()
{
	int c = getchar();
	ungetc(c, stdin);
	return c;
}

int endComment()
{
	if(getchar() == '*' && getchar() == '/')
		return 1;
	return 0;
}

void processOp(char ch)
{
	switch(peekc())
	{
		case '+':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
		case '-':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
		case '<':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
		case '>':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
		case '=':
			printf("%c", getchar());
			break;
		case '|':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
		case '&':
			if (peekc() == ch)
				printf("%c", getchar());
			break;
	}
}
void processComment(char ch)
{
	switch(peekc())
	{
		case '/':
			while(getchar() != '\n') ;
			break;
		case '*':
			while(!endComment()) ;
			break;
		default:
			processOp(ch);
			break;
	}
}

void processDoubleQuote(char ch)
{
	while((ch = getchar()) != '"')
		switch(ch)
		{
			case '\\':
				printf("%c%c", ch, getchar());
				break;
			default:
				printf("%c", ch);
				break;
		}
}

void processSingleQuote(char ch)
{
	while((ch = getchar()) != '\'')
		printf("%c", ch);
}

void processNumber(char ch)
{	
	printf("%c", ch);
	while (isdigit(peekc()) || peekc() == '.')
		printf("%c", getchar());
	printf("\n");
}

void processWord(char ch)
{	
	printf("%c", ch);
	while (isalnum(peekc()) || peekc() == '_')
		printf("%c", getchar());
	printf("\n");
}

void parse(char ch)
{
	switch(ch)
	{
		case ' ':
		case '\t':
		case '\n':
			// skip whitespaces
			break;
		case '/':
			processComment(ch);
			break;
		case '*':
		case '+':
		case '-':
		case '<':
		case '>':
		case '=':
		case '|':
		case '&':
			printf("%c", ch);
			processOp(ch);
			printf("\n");
			break;
		case '#':
		case ';':
		case ':':
		case ',':
		case '.':
		case '{':
		case '}':
		case '(':
		case ')':
			printf("%c\n", ch);
			break;
		case '"':
			printf("%c", ch);
			processDoubleQuote(ch);
			printf("%c\n", ch);
			break;
		case '\'':
			printf("%c", ch);
			processSingleQuote(ch);
			printf("%c\n", ch);
			break;
		default:
			if (isdigit(ch))
				processNumber(ch);
			else if (isalpha(ch))
				processWord(ch);
			break;
	}
}
int main()
{
	int ch;
	while((ch = getchar()) != EOF)
	{
		parse(ch);
	}
	printf("\n");
	return 0;
}
