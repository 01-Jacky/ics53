// an int is 4 bytes || 32 bits

#include <stdio.h>

struct some {
	int one;
	char thing;
};

struct some makeSome();

int main() {
	int i = 40;
	printf("Enter a number:\n");
	scanf("%d", &i);
	printf("I is %d\n", i);

	struct some a = makeSome();
	printf("%c\n", a.thing);
	printf("%i\n", a.one);


	int c = -3%2;
	printf("%i", c);

	return 0;
}

// c only has value parameters.. must explicitly pass the address
// can only pass by value.

/*	
	for hw1 use a fixed size array..
	do not use malloc.. Memory ALLOCation

	implement as an array of structures STRUCT
*/


// char* s = "Hello"; // has 6 characters.. last character is a null character

struct some makeSome() {
	struct some a;
	a.one = 15;
	a.thing = 'a';
	return a;
}
