#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h> // for user name
#include <grp.h> // for group name
#include <time.h> // for localtime


int do_ls(char* file);
