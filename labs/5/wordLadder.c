#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node {
	char word[1024];
	char other_words[1024][1024];
};


char word_list[500000][46];

void stripNewline(char* word)
{
	char* p;
	if ((p = strchr(word, '\n')) != NULL)
		*p = '\0';
}

int fill_word_list(const int size) {
	char word[46];
	FILE* fp = fopen("/usr/share/dict/words", "r");
	int count = 0;
	while (fgets(word, sizeof(word), fp)) {
        if (strlen(word) == size + 1) {
            stripNewline(word);
		for (int i = 0, limit = strlen(word); i < limit; ++i) {
        	word[i] = tolower(word[i]);
		}
			strcpy(word_list[count++], word);
		}
	}
	return count;
}


int isSameLen(char* word1, char* word2)
{
	return strlen(word1) == strlen(word2);
}


int isValidWord(char* word, int left, int right)
{
	int mid = (right + left) / 2;
	
	int valid = strcmp(word, word_list[mid]);
	if(valid == 0)
		return 1;
	else
		if (left <= right)
			return valid < 0 ? isValidWord(word, left, mid - 1) : isValidWord(word, mid + 1, right); 
		else
			return 0;

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

	for (int i = 0, limit = strlen(word1); i < limit; ++i) {
        word1[i] = tolower(word1[i]);
        word2[i] = tolower(word2[i]);
	}
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
	int i = 0;
	for (i; i < word_count; i++)
	{
		if (strcmp(word, wordBank[i])==0)
			return 1;
	}
	return 0;
}

void print_wordBank()
{
	printf("\n");
	int i = 0;
	for (i; i < word_count; i++)
	{
		printf("%s->", wordBank[i]);
	}
}

void checkWithWord(char* word1, char* word2, int w_cnt)
{
	char temp[1024];
	strcpy(temp, word1);
	for(int i = 1, limit = strlen(word1); i < limit; i++ )
	{
		swapNth(word1, word2, i);
		if (isValidWord(word1, 0,w_cnt) && strcmp(word1, temp) != 0 && !in_wordBank(word1))
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

void checkWithAlpha(char* word, int w_cnt)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char temp[1024];
	strcpy(temp, word);
	for(int i = 1, limit = strlen(word) + 1; i < limit; i++)
	{
		int j = 0;
		for(j; alphabet[j] != '\0'; j++)
		{
			swapNthC(word, alphabet[j], i);
			if (isValidWord(word, 0,w_cnt) && strcmp(word, temp) != 0 && !in_wordBank(word))
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

	// TODO: we fucked up here
//	while (strcmp(wordBank[word_count - 1], temp)
	strcpy(word, wordBank[word_count -2]);
	printf("$$%s$$", temp);
}

void wordLadder(char* word1, char* word2)
{
	getWords(word1, word2);
	int w_cnt = fill_word_list(strlen(word1));
	if (!isValidWord(word1,0, w_cnt ) || !isValidWord(word2,0, w_cnt))
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
		checkWithWord(cur_word, word2, w_cnt);
		if (strcmp(cur_word, prev_word) == 0)
		{
			checkWithAlpha(cur_word, w_cnt);
		}
		strcpy(prev_word, cur_word);
	}
}

int main(int argc, char* argv[])
{
	char word1[1024], word2[1024];
	wordLadder(word1, word2);
/*
	int c = fill_word_list(4);
	for (int i = 0; i < c; i++)
	{
		printf("%s\n", word_list[i]);
	}
*/
	return 0;
}
