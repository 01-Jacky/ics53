#include <stdio.h>
#include <string.h>

int isSameLen(char* w1, char* w2)
{
	return strlen(w1) == strlen(w2);
}

void stripNewline(char* word)
{
	char* p;
	if ((p = strchr(word, '\n')) != NULL)
		*p = '\0';
}

int isValidWord(char* w1)
{
	int isValid = 0;
	char w2[1024];
	FILE* fp = fopen("/usr/share/dict/words", "r");
	while (fgets(w2, sizeof(w2), fp) != NULL)
	{
		stripNewline(w2);
		if (strcmp(w1, w2) == 0)
			isValid = 1;
	}
	fclose(fp);
	return isValid;
}

void getWords(char* w1, char* w2)
{
	char input[1024];
	fgets(input, 1024, stdin);
	char* tok = strtok(input, " \n");
	if (tok == NULL)
		w1 = "";
	else
		strcpy(w1, tok);
	
	tok = strtok(NULL, " \n");
	if (tok == NULL)
		w2 = "";
	else
		strcpy(w2, tok);
}

void wordLadder(char* w1, char* w2)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	getWords(w1, w2);
	if (!isValidWord(w1) || !isValidWord(w2))
	{
		printf("a word is not valid\n");
		return;
	}
	if (!isSameLen(w1, w2))
	{
		printf("not same length\n");
		return;
	}

	char* t1 = w2;
	char t2[1024];
	strcpy(t2, w1);
	while (strcmp(t2, w2) != 0)
	{
		while (*t1 != '\0')
		{
			strncpy(t2, t1, 1);
			if (isValidWord(t2))
			{
				
			}
			t1++;
		}
	}


	printf("$%s$\n$%s$\n", w1, w2);
	printf("%d, %d\n", isValidWord(w1), isValidWord(w2));
	printf("%lu\n", strlen(w1));
}

int main(int argc, char* argv[])
{
	
	char w1[1024], w2[1024];
	wordLadder(w1, w2);

	return 0;
}
