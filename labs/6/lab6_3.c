#include <stdio.h>
#include <string.h>

void print_n_ch(int n, char ch)
{
	for(int i = 0; i < n; i++)
	{
		printf("%c", ch);
	}
}

void decompress()
{
	int n;
	char ch;
	while(scanf( "%d%c", &n, &ch) != '\n')
		print_n_ch(n, ch);
}

void parse()
{	char c;
	while( (c= getchar()) != '\n' || c != EOF)
	{
		switch(c)
		{
			default:
				break;
		}
	}
}



int main()
{
	decompress();
	return 0;
}
