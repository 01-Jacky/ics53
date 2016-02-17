/*
	Thomas Tang
	82502633
	ICS53 HW5
	my_shell.c
*/
#include <fcntl.h> // for open()
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read() write() close()
#include <sys/types.h>
#include <limits.h>

void processInputRedirection()
{
 // does nothing
}

void processOutputRedirection()
{
 // does nothing
}

void processPipe()
{
 // does nothing
}

char* getWord(char ch, char* buf)
{
	*buf++ = ch;
	while((ch = getchar()) != ' ' && ch != '\n' && ch != '<' && ch != '>' && ch != '|')
		*buf++ = ch;
	*buf = '\0';
	return buf;
}



void parse(char* input, char** args)
{
	while(*input != '\0')
	{
		while (*input == ' ' || *input == '\t' || *input == '\n')
			*input++ = '\0';
		*args = input;



	/*	switch(ch)
		{
			case ' ': // skip whitespaces
				break;
			case '<': // process input redirection
				processInputRedirection();
				break;
			case '>': // process output redirection
				processOutputRedirection();
				break;
			case '#': // process comments
				while(getchar() != '\n')
					continue;
				break;
			case '|': // process pipe
				processPipe();
				break;
			default: // get commands | args | input files | output files
				getWord(ch, *args++);
				break;
		}
		*args = NULL;
	*/
	}
}

void execute(char** args, char* en_path)
{
	if (execvp(args[0], args) < 0)
	{
		char* bin = strtok(en_path, ":");
		char path[PATH_MAX];
		while (bin != NULL)
		{
			snprintf(path, PATH_MAX, "%s/%s", bin, args[0]);
			execvp(path, args);
			bin = strtok(NULL, ":");
		}
	}
}

void shell(char* en_path)
{	
	char input[1024];
	char* args[64] = {NULL};

	while(1)
	{
		fputs("% ", stdout);
		fgets(input, 1024, stdin);
		parse(input, args);

		if(strcmp(args[0], "exit"))
			exit(0);

		execute(args, en_path);
	}
}

int main(int argc, char* argv[], char* envp[])
{	
	char* en_path = getenv("PATH");
	shell(en_path);
}
