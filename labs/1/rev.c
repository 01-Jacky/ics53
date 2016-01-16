#include <stdio.h>


int main() {
	char* string = "somestring";
	int count = 0;
	for(int i = 0; string[i] != '\0'; ++i) 
		count++;

	char rev[count];
	for(int i = 0; string[i] != '\0'; ++i) {
		rev[count-1-i] = string[i];
	}
	
	printf("%s", rev);


	return 0;
}
