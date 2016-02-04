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
		while (*input == ' ' || *input == '\t')
			*input++ = '\0';
		*args++ = input;
		while (*input != '\0' && *input != ' ' && *input != '\t')
			input++;
	}
	*args = 0;
}


int main(int argc, char* argv[], char* envp[]) 
{
	char* en_path = getenv("PATH");
	char* bin;
	bin = strtok(en_path, ":");

	char input[1024];
	char* args[64];
	fgets(input, 1024, stdin);
	parse(input, args);
	printf("%s", args[0]);
/*
	while (bin != NULL)
	{
		printf("%s\n", bin);
		snprintf(path, sizeof(path), "%s/%s", bin, args[0]);
		execvp(path, "/bin");
		bin = strtok(NULL, ":");
	}
*/
	return 0;
}
