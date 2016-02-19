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

int is_space(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\n';
}

int is_redirection(char ch)
{
	return ch == '<' || ch == '>';
}

void parse(char* input, char** args)
{
	while(*input != '\0' )
	{
		while (is_space(*input) || is_redirection(*input))
		{
			switch(*input)
			{
				case '<':
					*args++ = "<\0";
					break;
				case '>':
					*args++ = ">\0";
					break;
			}
			*input++ = '\0';
		}
		*args = input;
		while (!is_space(*input) && *input != '\0' && !is_redirection(*input)) 
			input++;
		if(strlen(input) == 0)
			*args = NULL;
		args++;
	}
	*args = NULL;
}

void execute(char** args)
{	
	pid_t pid;
	int status, i = 0, fdin, fdout, is_in = 0, is_out = 0;
	char input[64], output[64];
	switch(pid = fork())
	{
		case -1:
			perror("fork");
			exit(1);
		case 0:
			while (args[i] != NULL)
			{
				if (strcmp(args[i], "<") == 0)
				{
					args[i++] = NULL;
					strcpy(input, args[i]);
					is_in = 1;
				}
				else if (strcmp(args[i], ">") == 0)
				{
					args[i++] = NULL;
					strcpy(output, args[i]);
					is_out = 1;
				}
				else
					i++;
			}

			if (is_in == 1)
			{
				if ((fdin = open(input, O_RDONLY)) < 0)
				{
					perror(input);			
					exit(1);
				}
				dup2(fdin, 0);
				close(fdin);
			}
			
			if (is_out == 1)
			{
				if ((fdout = open(output, O_WRONLY| O_CREAT, S_IRUSR| S_IRGRP| S_IROTH| S_IWUSR)) < 0)
				{
					perror(output);			
					exit(1);
				}
				dup2(fdout, 1);
				close(fdout);
			}

			if (execvp(args[0], args) < 0)
			{
				exit(1);
			}
		default:
			while (wait(&status) != pid)
				continue;
			break;
	}
}

void shell()
{	
	char input[1024];
	char* args[64] = {NULL};

	while(1)
	{
		fputs("% ", stdout);
		fgets(input, 1024, stdin);
		parse(input, args);
		int i = 0;
		if(args[0] != NULL)
		{
			if(strcmp(args[0], "exit") == 0)
				exit(0);
			execute(args);
		}
	}
}

int main(int argc, char* argv[], char* envp[])
{	
	shell();
}
