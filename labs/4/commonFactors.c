#include <stdio.h>
#include <ctype.h>

int isPrime(int number)
{
	for (int i = 2; i < number; ++i)
		if ((number % i) == 0)
			return 0;
	return 1;
}


void getCommonFactors(int arr[], int number, int cnt)
{
	if (isPrime(number))
	{
		arr[cnt] = number;
		return;
	}
	else 
	{
		for (int i = 2; i < number; ++i)
		{
			if ((number % i) == 0)
			{
				arr[cnt++] = i;
				number /= i;
				return getCommonFactors(arr, number, cnt);
			}
		}
	}
}


int main()
{	
	int j = 0;
	int arr[1024] = {0};
	scanf("%d", &j);
	getCommonFactors(arr, j, 0);

	printf("Prime factorization of %d is ", j);
	if (arr[0] != 0)
		printf("%d ", arr[0]);
	for (int i = 1; arr[i] != 0; i++)
		printf("x %d ", arr[i]);
	printf("\n");

	return 0;
}
