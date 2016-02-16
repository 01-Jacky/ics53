#include <stdio.h>
#include <string.h>

int isSameLen(char* word1, char* word2)
{
	return strlen(word1) == strlen(word2);
}

void stripNewline(char* word)
{
	char* p;
	if ((p = strchr(word, '\n')) != NULL)
		*p = '\0';
}

int isValidWord(char* word1)
{
	int isValid = 0;
	char word2[1024];
	FILE* fp = fopen("/usr/share/dict/words", "r");
	while (fgets(word2, sizeof(word2), fp) != NULL)
	{
		stripNewline(word2);
		if (strcmp(word1, word2) == 0)
			isValid = 1;
	}
	fclose(fp);
	return isValid;
}

void getWords(char* word1, char* word2)
{
	char input[1024];
	fgets(input, 1024, stdin);
	char* tok = strtok(input, " \n");
	if (tok == NULL)
		word1 = "";
	else
		strcpy(word1, tok);
	
	tok = strtok(NULL, " \n");
	if (tok == NULL)
		word2 = "";
	else
		strcpy(word2, tok);
}


void swapNth(char* dest, char* src, int n)
{
	if(n > 0 && isSameLen(dest, src) && n <= strlen(dest))
	{
		char temp[1024];
		strcpy(temp, dest);
		strncpy(dest, src, n);
		strncpy(dest, temp, n-1);
	}
}

void swapNthC(char* dest, char c, int n)
{
	dest[n-1] = c;
}


char wordBank[1024][1024];
int word_count = 0;

void add_to_wordBank(char* word)
{
	strcpy(wordBank[word_count], word);
	word_count++;
}

int in_wordBank(char* word) 
{
	for (int i = 0; i < word_count; i++)
	{
		if (strcmp(word, wordBank[i])==0)
			return 1;
	}
	return 0;
}

void print_wordBank()
{
	printf("\n");
	for (int i = 0; i < word_count; i++)
	{
		printf("%s->", wordBank[i]);
	}

}

void checkWithWord(char* word1, char* word2)
{
	char temp[1024];
	strcpy(temp, word1);
	for(int i = 1;i < strlen(word1) + 1;i++ )
	{
		swapNth(word1, word2, i);
		if (isValidWord(word1) && strcmp(word1, temp) != 0 && !in_wordBank(word1))
		{
			printf("%s\n", word1);
			return;
		}
		else
		{	
			strcpy(word1, temp);
		}
	}
}

void checkWithAlpha(char* word)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char temp[1024];
	strcpy(temp, word);
	for(int i = 1; i < strlen(word) + 1; i++)
	{
		for(int j = 0; alphabet[j] != '\0'; j++)
		{
			swapNthC(word, alphabet[j], i);
			if (isValidWord(word) && strcmp(word, temp) != 0 && !in_wordBank(word))
			{
				printf("%s\n", word);
				return;
			}
			else
			{	
				strcpy(word, temp);
			}
		}
	}
	printf("\n I FUCKED UP\n\n");
}
void wordLadder(char* word1, char* word2)
{
	getWords(word1, word2);
	if (!isValidWord(word1) || !isValidWord(word2))
	{
		printf("a word is not valid\n");
		return;
	}
	if (!isSameLen(word1, word2))
	{
		printf("not same length\n");
		return;
	}

	char* w2_ptr = word2;
	char cur_word[1024], prev_word[1024];
	strcpy(cur_word, word1);
	strcpy(prev_word, word1);
	while (strcmp(cur_word, word2) != 0)
	{
		add_to_wordBank(prev_word);
		print_wordBank();
		checkWithWord(cur_word, word2);
		if (strcmp(cur_word, prev_word) == 0)
		{
			checkWithAlpha(cur_word);
		}
		strcpy(prev_word, cur_word);
	}
}

int main(int argc, char* argv[])
{
	char word1[1024], word2[1024];
	wordLadder(word1, word2);
	return 0;
}
