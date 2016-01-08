#include <stdio.h>

void fromFile(char* filename, int* count, float* total) {
	float temp;
	FILE *fp = fopen(filename, "r");
	while(fscanf(fp, "%f", &temp) != EOF) 
	{
		(*count)++;
		(*total) += temp;
	}
	fclose(fp);
}


int main(int argc, char* argv[]) 
{
	float total = 0;
	int count = 0;
	fromFile(argv[1], &count, &total);	
	printf("The average of %i numbers in file \"%s\" is %f\n", count, argv[1], total/count);
	return 0;
}
