#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define isFile 0x8
char buff[512];

void grep(char* toFind, char* dirname)
{
	DIR* dir;
	struct dirent* file;

	while((myfile = readdir(mydir)) != NULL)
	{
		printf("%s", myfile->d_name);
		if(myfile->d_type != isFile && (strcmp(myfile->d_name, ".")) != 0 && (strcmp(myfile->d_name, "..")) != 0)
		{
			printf("FOLDER: %s\n", myfile->d_name);
			DIR* newdir;
		}
	}
}


int main(int argc, char* argv[])
{
	DIR* mydir;
	struct dirent* myfile;
	
	mydir = opendir(argv[3]);  
	grep(argv[2], mydir, myfile, argv[3]);
	closedir(mydir);
	return 0;
}
