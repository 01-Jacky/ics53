#include <stdio.h>
#include <string.h>
#define require(e) if (!(e)) fprintf(stderr, "FAILED line %d        %s: %s       %s\n", __LINE__, __FILE__, __func__, #e)




/*=============================
STRCHR
	char *strchr(const char *str, int c)
	Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
=============================*/
char* tang_strchr(const char* str, int c)
{	
	for (int i = 0; str[i] != '\0'; ++i)
		if (str[i] == c)
			return str + i;
	return NULL;
}

/*=============================
STRCMP
	int strcmp(const char *str1, const char *str2)
	Compares the string pointed to, by str1 to the string pointed to by str2.
=============================*/
int tang_strcmp(const char* str1, const char* str2)
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
		if (str1[i] - str2[i])
			return str1[i] - str2[i];
	return 0;
}

/*=============================
STRNCMP
	int strncmp(const char *str1, const char *str2, size_t n)
	Compares at most the first n bytes of str1 and str2.
=============================*/
int tang_strncmp(const char* str1, const char* str2, size_t n)
{
	for (int i = 0; i < n; i++)
		if (str1[i] - str2[i])
			return str1[i] - str2[i];
	return 0;
}

/*=============================
STRCPY
	char *strcpy(char *dest, const char *src)
	Copies the string pointed to, by src to dest.
=============================*/
char* tang_strcpy(char* dest, const char* src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}

/*=============================
STRNCPY
	char *strncpy(char *dest, const char *src, size_t n)
	Copies up to n characters from the string pointed to, by src to dest.
=============================*/
char* tang_strncpy(char* dest, const char* src, size_t n)
{
	int i;
	for (i = 0; i < n ; ++i)
		dest[i] = src[i];
	return dest;
}

/*=============================
STRCSPN
	size_t strcspn(const char *str1, const char *str2)
	Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
=============================*/
size_t tang_strcspn(const char *str1, const char *str2)
{
	size_t i;
	for (i = 0; str1[i] != '\0'; ++i)
		if (tang_strchr(str2, str1[i]) != NULL)
			return i;
	return i;
}

/*=============================
STRLEN
	size_t strlen(const char *str)
	Computes the length of the string str up to but not including the terminating null character.
=============================*/
size_t tang_strlen(const char* str)
{
	size_t cnt;
	for (cnt = 0; str[cnt] != '\0'; cnt++) ;// ;
	return cnt;
}

/*=============================
STRCAT
	char *strcat(char *dest, const char *src)
	Appends the string pointed to, by src to the end of the string pointed to by dest.
=============================*/
char* tang_strcat(char* dest, const char* src) 
{
	int len = tang_strlen(dest);
	for(int i = 0; src[i] != '\0'; ++i)
		dest[len + i] = src[i];
	return dest;
}

/*=============================
STRNCAT
	char *strncat(char *dest, const char *src, size_t n)
	Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long.
=============================*/
char* tang_strncat(char* dest, const char* src, size_t n)
{
	int i;
	int len = tang_strlen(dest);
	for(i = 0; src[i] != '\0'; ++i)
		dest[len + i] = src[i];
	dest[len + n] = '\0';
	return dest;
}

/*=============================
STRPBRK
	char *strpbrk(const char *str1, const char *str2)
	Finds the first character in the string str1 that matches any character specified in str2.
=============================*/
char* tang_strpbrk(const char* str1, const char* str2)
{
	for (int i = 0; str1[i] != '\0'; ++i)
		if (tang_strchr(str2, str1[i]) != NULL)
			return str1 + i;
	return NULL;
}

/*=============================
STRRCHR
	char *strrchr(const char *str, int c)
	Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
=============================*/
char* tang_strrchr(const char* str, int c)
{	
	char* pch = tang_strchr(str, c);
	while ((pch) != NULL)
	{
		if ((tang_strchr(pch + 1, c)) == NULL)
			return pch;
		pch = tang_strchr(pch + 1, c);
	}
	return pch;
}

/*=============================
STRSPN
	size_t strspn(const char *str1, const char *str2)
	Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
=============================*/
size_t tang_strspn(const char* str1, const char* str2)
{
	size_t i;
	for (i = 0; str1[i] != '\0'; ++i)
		if (tang_strchr(str2, str1[i]) == NULL)
			return i;
	return i;
}

/*=============================
STRSTR
	char *strstr(const char *haystack, const char *needle)
	Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
=============================*/
char* tang_strstr(const char* haystack, const char* needle)
{
	for (;*haystack;haystack++)
		for (int i = 0; needle[i] == *(haystack + i); ++i)
			if (!*(needle + i + 1))
				return haystack;
	return NULL;
}

/*=============================
STRTOK
	char *strtok(char *str, const char *delim)
	Breaks string str into a series of tokens separated by delim.
=============================*/
char* tang_strtok(char* str, const char* delim)
{
	static char* my_strtok_buffer;
	char* pch;
	if (str != NULL)
		my_strtok_buffer = str;

	if (my_strtok_buffer[0] == '\0' || my_strtok_buffer == NULL)
		return NULL;
	
	if (tang_strpbrk(my_strtok_buffer, delim) == NULL) 
	{
		pch = my_strtok_buffer;
		my_strtok_buffer += tang_strlen(my_strtok_buffer);
		return pch;
	}

	my_strtok_buffer += tang_strspn(my_strtok_buffer , delim);
	pch = my_strtok_buffer;
	
	my_strtok_buffer += tang_strcspn(my_strtok_buffer, delim);
	my_strtok_buffer += tang_strspn(my_strtok_buffer , delim);

	pch[tang_strcspn(pch, delim)] = '\0';

	return pch;
}

/*=============================
TESTS
=============================*/
void test_strchr()
{
	char str[] = "this is some string";
	require(strcmp(strchr(str, 'i'), "is is some string") == 0);
	require(strcmp(strchr(str, 's'), "s is some string") == 0);
	require(strcmp(strchr(str, 'o'), "ome string") == 0);
}

void test_strcmp()
{
	char *r = "hello", *s = "hello", *t = "he";
	require(tang_strcmp(r,s) == 0);
	require(tang_strcmp(t,r) < 0);
	require(tang_strcmp(s,t) > 0);

	require(tang_strcmp(r,s) == strcmp(r,s));
	require(tang_strcmp(t,r) == strcmp(t,r));
	require(tang_strcmp(s,t) == strcmp(s,t));
}

void test_strncmp()
{	
	char *f = "hellfire", *w = "helloworld", *z = "he";
	require(tang_strncmp(z, f, 2) == 0);
	require(tang_strncmp(z, f, 5) < 0);
	require(tang_strncmp(w, f, 4) == 0);
	require(tang_strncmp(f, w, 5) < 0);

	require(tang_strncmp(z, f, 2) == strncmp(z, f, 2));
	require(tang_strncmp(z, f, 5) == strncmp(z, f, 5));
	require(tang_strncmp(w, f, 4) == strncmp(w, f, 4));
}

void test_strcpy()
{
	char dst[10];
	char* src = "greatness";
	require(strcmp(tang_strcpy(dst, src), src) == 0);
	require(strcmp(tang_strcpy(dst, "sweet"), "sweet") == 0);
	require(strcmp(dst, "sweet") == 0);
	
	tang_strcpy(dst, "holy moly");
	require(strcmp(dst, "holy moly") == 0);
	
}

void test_strncpy()
{
	char d1[] = "point";
	char s1[] = "tail";
	tang_strncpy(d1, s1, 4);
	require(strcmp(d1, "tailt") == 0);
	char d2[] = "point";
	char s2[] = "tail";
	tang_strncpy(d2, s2, 2);
	require(strcmp(d2, "taint") == 0);
	char d3[] = "tail";
	char s3[] = "cool";
	tang_strncpy(d3, s3, 2);
	require(strcmp(d3, "coil") == 0);
}

void test_strcspn()
{
	require(tang_strcspn("hello 12 worlds", "1234567890") == 6);
	require(tang_strcspn("1hello 12 worlds", "1234567890") == 0);
	require(tang_strcspn("do 2 things 4 me", "1234567890") == 3);
	require(tang_strcspn("1259 Newport Beach", " ") == 4);
	require(tang_strcspn("No Spaces 4 A, While Now", ",") == 13);
}

void test_strlen()
{
	require(strlen("") == 0);
	require(strlen("hello") == 5);
	require(strlen("okie dokie") == 10);
	require(strlen("artichokie") == 10);
	require(strlen("world") == 5);
}

void test_strcat()
{
	char d[30] = "cool";
	require(strcmp(tang_strcat(d, "beans"), "coolbeans") == 0);

	char d2[30] = "french";
	require(strcmp(tang_strcat(d2, " toast"), "french toast") == 0);

	char d3[30] = "key";
	require(strcmp(tang_strcat(d3, "board"), "keyboard") == 0);
}

void test_strncat()
{
	char d1[30] = "cool";
	require(strcmp(tang_strncat(d1, "whiplash", 4), "coolwhip") == 0);
	char d2[30] = "car";
	require(strcmp(tang_strncat(d2, "toonland", 4), "cartoon") == 0);
	char d3[30] = "steak";
	require(strcmp(tang_strncat(d3, "and eggs and bacon and cheese", 8), "steakand eggs") == 0);
}

void test_strpbrk()
{
	char str[] = "This is a sample string";
	char key[] = "aeiou";
    char * pch;
	pch = strpbrk (str, key);
	require(strcmp(pch, "is is a sample string") == 0);
	
	pch = tang_strpbrk (pch+1,key);
	require(strcmp(pch, "is a sample string") == 0);
	
	pch = tang_strpbrk (pch+1,key);
	require(strcmp(pch, "a sample string") == 0);

	pch = tang_strpbrk (pch+1,key);
	require(strcmp(pch, "ample string") == 0);
}

void test_strrchr()
{
	require(strcmp(tang_strrchr("hello", 'l'), "lo") == 0);
	require(strcmp(tang_strrchr("mississippi", 's'), "sippi") == 0);
	require(strcmp(tang_strrchr("totoro", 't'), "toro") == 0);
	require(strcmp(tang_strrchr("kokokakikekoo", 'k'), "koo") == 0);
}

void test_strspn()
{
	require(tang_strspn("19d846afpajfij9499", "1234567890") == 2);
	require(tang_strspn("19846afpajfij9499", "1234567890") == 5);
	require(tang_strspn("198646afpajfij9499", "1234567890") == 6);
}

void test_strstr()
{
	require(strcmp(tang_strstr("helloworld", "low"), "loworld") == 0);
	require(strcmp(tang_strstr("ooh okay", "ka"), "kay") == 0);
	require(strcmp(tang_strstr("okokay okay", "ko"), "kokay okay") == 0);
	require(strcmp(tang_strstr("str stri string stringy", "strin"), "string stringy") == 0);
}	

void test_strtok() 
{
	char str[] = "a book is on fire";
	require(strcmp(tang_strtok(str, " "), "a") == 0);
	require(strcmp(tang_strtok(NULL, " "), "book") == 0);
	require(strcmp(tang_strtok(NULL, " "), "is") == 0);
	require(strcmp(tang_strtok(NULL, " "), "on") == 0);
	require(strcmp(tang_strtok(NULL, " "), "fire") == 0);
}

int main()
{
	test_strchr();
	test_strcmp();
	test_strncmp();
	test_strcpy();
	test_strncpy();
	test_strcspn();
	test_strlen();
	test_strcat();
	test_strncat();
	test_strpbrk();
	test_strrchr();
	test_strspn();
	test_strstr();
	test_strtok();
	return 0;
}
