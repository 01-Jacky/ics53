/*
	Thomas Tang
	82502633
	ICS53 HW5
	my_shell.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parse()
{
	char ch;
	while((ch = getchar() != EOF))
	{
		switch(ch)
		{
			case ' ':
				break;
			case '<':
				break;
			case '>':
				break;
			default:
				break;
		}
	}

}


void shell()
{
	while(1)
	{
		fputs("% ", stdout);
		parse();
	}
}

int main()
{	
	shell();
}
