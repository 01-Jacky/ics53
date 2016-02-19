#include <stdio.h>
#include <stdlib.h>


void print_arr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}

// O(2N)
int main(int argc, char* argv[])
{
	int n, count = 0;
	int input[1024], output[1024], l[1024], h[1024];

	while(fscanf(stdin, "%d", &n) != EOF)
		input[count++] = n;

	l[0] = 1;
	h[count-1] = 1;

	for (int i = 1, j = count-2; i < count; i++, j--)
	{
		l[i] = l[i-1] * input[i-1];
		h[j] = h[j+1] * input[j+1];
	}
	
	for (int i = 0; i < count; i++)
		output[i] = l[i] * h[i];


	print_arr(input, count);
	printf("\n");
	print_arr(output, count);

	return 0;
}
