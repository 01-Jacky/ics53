#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


char* my_fgets(char* str, int num, FILE* stream);


void strip_newline(char* word);


void my_error(const char* s);


int read_from(int sockfd, char* buf);


int write_to(int sockfd, char* buf);
