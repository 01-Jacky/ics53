#include <stdio.h>


/*=============================
STRCAT
	char *strcat(char *dest, const char *src)
	Appends the string pointed to, by src to the end of the string pointed to by dest.
=============================*/
char* strcat(char* dest, const char* src) 
{
	return 0;
}

/*=============================
STRNCAT
	char *strncat(char *dest, const char *src, size_t n)
	Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
=============================*/
char* strncat(char* dest, const char* src, size_t n)
{
	return 0;
}

/*=============================
STRCHR
	char *strchr(const char *str, int c)
	Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
=============================*/
char* strchr(const char* str, int c)
{	
	return 0;
}

/*=============================
STRCMP
	int strcmp(const char *str1, const char *str2)
	Compares the string pointed to, by str1 to the string pointed to by str2.
=============================*/
int strcmp(const char* str1, const char* str2)
{
	return str1 - str2;
}

/*=============================
STRNCMP
	int strncmp(const char *str1, const char *str2, size_t n)
	Compares at most the first n bytes of str1 and str2.
=============================*/
int strncmp(const char* str1, const char* str2, size_t n)
{
	return 0;
}

/*=============================
STRCPY
	char *strcpy(char *dest, const char *src)
	Copies the string pointed to, by src to dest.
=============================*/
char* strcpy(char* dest, const char* src)
{
	return 0;
}

/*=============================
STRNCPY
	char *strncpy(char *dest, const char *src, size_t n)
	Copies up to n characters from the string pointed to, by src to dest.
=============================*/
char* strncpy(char* dest, const char* src, size_t n)
{
	return 0;
}


/*=============================
	STRCSPN
=============================*/


/*=============================
	STRLEN
=============================*/


/*=============================
	STRPBRK
=============================*/


/*=============================
	STRRCHR
=============================*/


/*=============================
	STRSPN
=============================*/


/*=============================
	STRSTR
=============================*/


/*=============================
	STRTOK
=============================*/


/*==================================================
	MAIN
==================================================*/
int main() 
{
	printf("b - a %d\n", strcmp("b", "a"));
	printf("a - b %d\n", strcmp("a", "b"));
	printf("as - a %d\n", strcmp("as", "a"));

	return 0;
}
