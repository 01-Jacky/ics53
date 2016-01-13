#include <stdio.h>
#include <string.h> // for strcmp
#define LIBRARY_SIZE 1024

//=================================================================
//	SONG
//=================================================================
typedef struct Song 
{
	char title[40];
	char artist[40];
	int year;
} Song; 

Song library[LIBRARY_SIZE];
int song_count = 0;

Song make_song() 
{
	Song song;

	printf("Title: ");
	fgets(song.title, 40, stdin);
	printf("Artist: ");
	fgets(song.artist,40, stdin);
	printf("Year Published: ");
	scanf("%d", &song.year);

	return song;
}


void write_song(FILE* fp, Song song)
{
	fprintf(fp, "Title: %s, Artist: %s, Year Published: %d", song.title, song.artist, song.year);
}


//=================================================================
//	FILE
//=================================================================
char* get_filename(char* name) 
{
	return name==NULL ? "myMusic" : name;
}

FILE* open_file(char* filename, char* mode) 
{
	FILE* fp = fopen(filename, mode);
	
	if(fp == NULL) 
	{
		fp = fopen(filename, "w");
	}

	return fp;
}



//=================================================================
//	COMMAND
//=================================================================
int ensure_valid_command(char command){
	switch (command) 
	{
		case 'i':
		case 'I':
		case 'p':
		case 'P':
		case 'd':
		case 'D':
		case 'l':
		case 'L':
		case 'q':
		case 'Q':
			printf("valid\n");
			return 1;
	}
	return 0;
}

char read_command() 
{	
	char cmd;
	scanf("%c", &cmd);
	return cmd;
}


// returns non-zero or zero if Q
int evaluate_command(char* filename)
{
	char cmd;
	printf("%s Command:\t", filename);
	scanf(" %c", &cmd);
	switch (cmd)
	{
		case 'i':
		case 'I':
			printf("inserting\n");
			break;
		case 'p':
		case 'P':
			printf("printing\n");
			break;
		case 'd':
		case 'D':
			printf("deleting\n");
			break;
		case 'l':
		case 'L':
			printf("looking up\n");
			break;
		case 'q':
		case 'Q':
			printf("quitting\n");
			return 0;
		default:
			return evaluate_command(filename);
	}
	return 1;
}

int binary_search(char* key, char* A[], int min, int max)
{
	if (max < min) 
		return -1;
	else
	{
		int mid = (max-min)/2 + min;
		return A[mid] > key ? binary_search(key, A, min, mid-1): A[mid] < key ? binary_search(key, A, mid+1, max) : mid; 
	}
}

int insert(char* key, char* A[], int min, int max) 
{


}

int find_index_of_song_with_name() 
{
	return 1;
}

//=================================================================
//	MAIN
//=================================================================
int main(int argc, char* argv[]) {
	char* filename = get_filename(argv[1]);
	FILE* fp = open_file(filename, "r");
	int is_on = 1;
	do 
	{
		is_on = evaluate_command(filename);
	} while (is_on);
	fclose(fp);

	return 0;
}

















