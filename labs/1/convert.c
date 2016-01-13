#include <stdio.h>
#include <ctype.h>

void wuns(int dig)
{
	switch (dig) 
	{
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		default:
			break;
	}
}

void teens(int ones)
{
	switch (ones)
	{
		case 1:
			printf("eleven");
			break;
		case 2:
			printf("twelve");
			break;
		case 3:
			printf("thirteen");
			break;
		case 4:
			printf("fourteen");
			break;
		case 5:
			printf("fifteen");
			break;
		case 6:
			printf("sixteen");
			break;
		case 7:
			printf("seventeen");
			break;
		case 8:
			printf("eighteen");
			break;
		case 9:
			printf("nineteen");
			break;
		default:
			printf("ten");
			break;
	}
}

void tins(int tens, int ones)
{
	switch (tens) 
	{
		case 1:
			teens(ones);
			return;
		case 2:
			printf("twenty");
			break;
		case 3:
			printf("thirty");
			break;
		case 4:
			printf("forty");
			break;
		case 5:
			printf("fifty");
			break;
		case 6:
			printf("sixty");
			break;
		case 7:
			printf("seventy");
			break;
		case 8:
			printf("eighty");
			break;
		case 9:
			printf("ninety");
			break;
		default:
			break;
	}
	if(tens && ones)
	{	
		printf(" ");
	}
		wuns(ones);
}

void hunnets(int tree_dig) 
{
	if(tree_dig / 100)
	{
		wuns(tree_dig / 100);
		printf(" hundred");
	}
	if(tree_dig / 100 && tree_dig % 100)
		printf(" ");
	tins((tree_dig % 100) / 10, (tree_dig % 100) % 10);
}

void iToEng(int i) 
{
	if(i/1000)
	{
		hunnets(i/1000);
		printf(" thousand");
	}
	if(i%1000 && i/1000)
		printf(" ");
	if(i%1000) 
	{
		hunnets(i%1000);
	}
	printf("\n");
}

//=========================================================

//=========================================================

//=========================================================
char* digits[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char* multers[2] = {"hundred", "thousand"};
char* adders[18] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char peekc() {
	char ch = getc(stdin);
	ungetc(ch, stdin);
	return ch;
}
void parseWord(char A[]) {
	
}

void engToInt() {
	char ch;
	while((ch = getchar()) != EOF)
	{
		switch (ch) 
		{
			case ' ':
				break;
			default:
				if(isalpha(ch))
					char word[20];
					word[0] = ch;
					return parseWord(word);
				break;
				


		}
	}
}


//=========================================================

//=========================================================

//=========================================================

int main (int argc, char* argv[])
{	
	/*
	iToEng(1);
	iToEng(5);
	iToEng(10);
	iToEng(13);
	iToEng(27);
	iToEng(101);
	iToEng(1169);
	iToEng(84177);
	iToEng(111111);
	iToEng(999999);
	*/

	//engToInt();
	char ch;
	while((ch=getchar()) != EOF) 
	{
		printf("%c", ch);
		if(isdigit(peekc()))
			printf("\nNUM");
	}

	return 0;
}
