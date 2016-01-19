#include <stdio.h>
#include <string.h>

// NOTE cant assign or compare  c strings

typedef struct Song {
	char title[40];
	char album[40];
	int year;

} Song;



void print_vertical()
{
	char c;
	int pos = 0;
	char buffer[1024];
	while((c = getchar()) != '\n')
	{
		buffer[pos++] = c;
	}
	buffer[pos] = '\0';

	for(int i = 0; buffer[i] != '\0'; i++) {
		printf("%c\n", buffer[i]);
	}

	printf("%s", buffer);

}

char* getTitle(char* title) {
	fgets(title, 40, stdin);
	return title;
}

Song make_song (){

	Song song;// = {.title = *getTitle(), .album = "beans", .year = 1990};
	getTitle(song.title);
	strcpy(song.album,  "beans");
	song.year = 1990;

	return song;
}



//=========================================================================

char* names[100]={"andy", "donald", "eric", "john", "kay", "pete", "quom", "richard", "tom", "xena"};

int bin(char* name, int min, int max)
{
	if(max < min)
	{
		return min;
	}
	else
	{
		int mid = (max-min)/2 + min;
		int cmp = strcmp(names[mid], name);
		printf("%d\t%d\n", mid, cmp);
		return cmp > 0 ? bin(name, min, mid-1) : cmp < 0 ? bin(name, mid+1, max) : mid;
	}
}


char* lower_case(const char* word, char* buffer)
{
	strcpy(buffer, word);
	for (int i = 0;buffer[i]!='\0';++i)
		if(buffer[i] >= 65 && buffer[i] <= 90)
			buffer[i] += 32;
	return buffer;
}


int main(int argc, char* argv[]) {
	//bin("donald", 0, 9);
	/*char ch;
	while((ch = getchar()) != '\n')
	{
		if(ch >= 65 && ch <= 90)
			ch += 32;
		printf("%c\n", ch);
	}
*/
	char buffer[1024];

	lower_case("CoolBeaNs", buffer);

	printf("%s\n", buffer); 


	return 0;
}











