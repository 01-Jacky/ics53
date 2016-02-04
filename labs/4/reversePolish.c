#include <stdio.h>
#include <string.h>
#include <ctype.h>



void parse_input(char* input, char* inputs[])
{
	char* pch;
	
	printf("%s\n", input);
	pch = strtok(input, " ");
	inputs[0] = pch;
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ");
	}
}


int main()
{
	char* inputs[1024] = {"\0"};
	char input[1024];
	while(scanf("%s", &input) != EOF)
	{
		printf("%s\n", input);
	}
	
	return 0;
}
