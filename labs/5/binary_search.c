#include <stdio.h>
#include <string.h>
char arr[10][1024] = {"cool", "beans", "sweet", "sauce", "awesome", "possum", "funky", "monkey", "cheese", "tart"}; 


int spaces(int n)
{
	int tot = n;
	for(int i = 0; i < n; i++)
	{
		tot += strlen(arr[i]);
	}
	return tot;
}
void print_positions(int i, int j, int p)
{
	char pos[1024] = "";
	for(int k = 0; k < spaces(10); k++)
	{
		strcat(pos, " ");
	}
	int jp = spaces(j);
	int ip = spaces(i);
	int pp = spaces(p);
	if(jp == ip)
		jp += 1;
	if(jp == pp)
		jp += 1;
	if(ip == pp)
		ip += 1;

	pos[jp] = 'j';
	pos[ip] = 'i';
	pos[pp] = 'p';
	printf("%s\n", pos);
}

int binary_search(char* key, int min, int max)
{
	int mid = ((max - min ) / 2) + min;
	int cmp = strcmp(arr[mid], key);
	if (max < min)
		return mid;
	else
		return cmp > 0 ? binary_search(key, min, mid - 1) : cmp < 0 ? binary_search(key, mid + 1, max) : mid; 
}


void print_arr(int sz)
{
	for(int i = 0 ; i < sz ; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}

void swap_str(char* a, char* b)
{
	char temp[1024];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}	


int 

void quick_sort( int low, int high)
{
	if(low < high)
	{
		printf("Start QS: \n");
		print_arr( 10);
		int piv = low;
		char pivotVal[1024];
		strcpy(pivotVal, arr[low]);
		int i = low + 1, j = high -1;
		for( ; i <= j; )
		{
			if(strcmp(arr[i], pivotVal) > 0)
			{
				if(strcmp(arr[j], pivotVal) <= 0)
				{
					swap_str(arr[i], arr[j]);
					printf("Swapped %s and %s\n", arr[i], arr[j]);
					print_arr(10);
					print_positions(i, j, piv);
				}
				else
				{
					j--;
					print_arr(10);
					print_positions(i, j, piv);
				}
			}
			else 
			{
				i++;
					print_arr(10);
					print_positions(i, j, piv);
			}
		}
		swap_str(arr[j], arr[low]);
		printf("End QS: \n");
		print_arr(10);
		if (j > low)
			quick_sort(low, j);
		quick_sort(j+1, high);
		return;
	}
}


int main() 
{
	quick_sort(0, 10);


	return 0;
}
