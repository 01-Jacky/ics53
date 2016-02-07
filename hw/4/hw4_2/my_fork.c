/*
Thomas Tang
82502633
ICS 53 hw 4
my_fork.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define DEFAULT_SIZE 10000
#define NUM_CHILDREN 4

void printnc(int n, char c)
{
	int i = 0;
	while(i++ < n)
	{
		putchar(c);
		fflush(stdout);
	//	sleep(1);
	}
}

void runChildren(int sz, char c[])
{
	pid_t pid[NUM_CHILDREN];
	int i, status;
	for (i = 0; i < NUM_CHILDREN; ++i)
	{
		switch(pid[i] = fork()) 
		{
			case -1: 
				perror("fork failed");
				exit(1);
				break;
			case 0:
				printnc(sz, c[i]);
				exit(0);
				break;
			default:
				break;
		}
	}
	while (i-- > 0)
	{
		int child_pid = wait(&status);
	}
}


int main(int argc, char* argv[], char* envp[])
{
	int i;
	char letter[4] = {'A', 'B', 'C', 'D'};
	if (argc == 1)
	{
		i = DEFAULT_SIZE;
		runChildren(i, letter);

	}
	else if (argc == 2)
	{
		i = atoi(argv[1]);
		runChildren(i, letter);
	}
	putchar('\n');	
	return 0;
}
