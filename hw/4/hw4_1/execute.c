/*
Thomas Tang
82502633
ICS 53 hw 4
execute.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse(char* input, char** args)
{
	while (*input != '\0') 
	{
		while (*input == ' ' || *input == '\t' || *input == '\n')
			*input++ = '\0';
		*args = input;
		while (*input != '\0' && *input != ' ' && *input != '\t' && *input != '\n')
			input++;
		if (strlen(input) == 0)
			*args = NULL;
		args++;
	}
	*args = NULL;
}

void execute(char** args, char* en_path)
{
	if (execvp(args[0], args) < 0)
	{
		char* bin = strtok(en_path, ":");
		char path[1024];
		while (bin != NULL)
		{
			snprintf(path, sizeof(path), "%s/%s", bin, args[0]);
			execvp(path, args);
			bin = strtok(NULL, ":");
		}
	}
}

int main(int argc, char* argv[], char* envp[]) 
{
	char input[1024];
	fgets(input, 1024, stdin);

	char* args[64] = {NULL};
	parse(input, args);
	
	char* en_path = getenv("PATH");
	execute(args, en_path);

	return 0;
}
