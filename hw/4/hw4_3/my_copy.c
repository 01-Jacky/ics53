#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> // open()
#include <unistd.h> // read() write() close()
#include <sys/types.h>
#include <sys/stat.h>
#include "Timer.h"

void method_1(char* infile, char* outfile)
{
	FILE* ifp = fopen(infile, "r");
	FILE* ofp = fopen(outfile, "w");
	char c;

	double wc_time, usr_time, sys_time;
	Timer_start();

	while((c = fgetc(ifp))!= EOF)
		fputc(c, ofp);
		
	Timer_elapsedTime(&wc_time, &usr_time, &sys_time);
	printf("wallclock: %f, user: %f, system time: %f\n", wc_time, usr_time, sys_time);

	fclose(ifp);
	fclose(ofp);
}

void method_2(char* infile, char* outfile)
{
	size_t in_fi_des = open(infile, O_RDONLY);
	size_t out_fi_des = open(outfile, O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
	char buf[1];

	double wc_time, usr_time, sys_time;
	Timer_start();

	while(read(in_fi_des, buf, 1) == 1)
		write(out_fi_des, buf, 1);

	Timer_elapsedTime(&wc_time, &usr_time, &sys_time);
	printf("wallclock: %f, user: %f, system time: %f\n", wc_time, usr_time, sys_time);
	
	close(in_fi_des);
	close(out_fi_des);
}

void method_3(char* infile, char* outfile)
{
	size_t in_fi_des = open(infile, O_RDONLY);
	size_t out_fi_des = open(outfile, O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
	char buf[BUFSIZ];
	int n_char = 0;
	
	double wc_time, usr_time, sys_time;
	Timer_start();

	while((n_char = read(in_fi_des, buf, BUFSIZ)) != 0)
		write(out_fi_des, buf, n_char);

	Timer_elapsedTime(&wc_time, &usr_time, &sys_time);
	printf("wallclock: %f, user: %f, system time: %f\n", wc_time, usr_time, sys_time);

	close(in_fi_des);
	close(out_fi_des);
}



int main(int argc, char** argv)	// argv[1]: method || argv[2]: input filename || argv[3]: output filename || argv[4]: repeat this many times
{
	int i;
	for (i = 0; i < atoi(argv[4]); i++)
	{
		if(strcmp(argv[1], "1") == 0)
			method_1(argv[2], argv[3]);
		else if(strcmp(argv[1], "2") == 0)
			method_2(argv[2], argv[3]);
		else if(strcmp(argv[1], "3") == 0)
			method_3(argv[2], argv[3]);
	}

	return 0;
}
