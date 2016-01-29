#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my_ls.h"

int main(int argc, char* argv[])
{
	char* filename = argv[1];
	
	if (filename == NULL)
		filename = ".";
	
	do_ls(filename);

	return 0;
}
