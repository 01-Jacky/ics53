#include <stdio.h>
#include <string.h> // for strcmp

#define LIBRARY_SIZE 1024



/*============================
	SONG STRUCT
============================*/
typedef struct Song 
{
	char title[40];
	char artist[40];
	int year;
} Song; 


/*============================
	GLOBAL VARIABLES
============================*/
Song library[LIBRARY_SIZE];
int song_count = 0;
char* m_filename;
FILE* m_fp;

/*============================
	GET TITLE
============================*/
void getTitle(char* song_title) 
{
	printf("Title: ");
	fgets(song_title, 40, stdin);

	char* p;
	if ((p = strchr(song_title, '\n')) != NULL)
		*p = '\0';
}

/*============================
	GET ARTIST
============================*/
void getArtist(char* song_artist) 
{
	printf("Artist: ");
	fgets(song_artist, 40, stdin);
	
	char* p;
	if ((p = strchr(song_artist, '\n')) != NULL)
		*p = '\0';
}

/*============================
	GET YEAR
============================*/
int getYear() 
{
	int song_year;
	printf("Year Published: ");
	scanf("%d", &song_year);
	return song_year;
}

/*============================
	MAKE SONG
============================*/
Song make_song() 
{
	Song song;
	
	getTitle(song.title);
	getArtist(song.artist);
	song.year = getYear();

	return song;
}

/*============================
	WRITE SONG
============================*/
void write_song(Song song)
{
	fprintf(m_fp, "Title: %s, Artist: %s, Year Published: %d\n", song.title, song.artist, song.year);
}

/*============================
	PRINT SONG
============================*/
void print_song(int i)
{
	printf("Title: %s, Artist: %s, Year Published: %d\n", library[i].title, library[i].artist, library[i].year);
}

/*============================
	STORE LIBRARY TO FILE
============================*/
void store_MusicLibrary() 
{
	for(int i = 0; i < song_count; i++ )
		write_song(library[i]);
}

void parseTitleArtist(char* word )
{
	char ch;
	int	count = 0;
	while((ch = fgetc(m_fp)) != ' ')
	{
	}
	while((ch = fgetc(m_fp)) != ',')
	{
		word[count++] = ch;
	}
	word[count] = '\0';
	printf("%s", word);
}

int parse_year() 
{	
	int year;
	fscanf(m_fp, " %d", &year);
	printf("this year is %d", year);
	return year;
}

/*============================
	READ SONG TODO!!
============================*/
void read_song()
{
	char title[50];
	char artist[50];
	parseTitleArtist(title);
	parseTitleArtist(artist);
	parse_year();

}

/*============================
	LOAD LIBRARY FROM FILE
============================*/
void load_MusicLibrary()
{	
	char ch;
	while ((ch = fgetc(m_fp)) != EOF)
	{
		ungetc(ch, m_fp);
		read_song();
	}
	
}

/*============================
	OPTAIN FILENAME
============================*/
char* get_filename(char* name) 
{
	return name==NULL ? "myMusic" : name;
}

/*============================
	OPEN FILE
============================*/
void open_file(char* filename, char* mode) 
{
	m_fp = fopen(filename, mode);
	
	if(m_fp == NULL) 
	{
		m_fp = fopen(filename, "w");
	}
}

/*============================
	TO LOWER CASE
============================*/
char* lower_case(const char* word, char* buffer) 
{	
	strcpy(buffer, word);
	for(int i = 0; buffer[i] != '\0'; ++i) 
		if (buffer[i] >= 65 && buffer[i] <= 90)
			buffer[i] += 32;
	return buffer;
}

/*============================
	BINARY SEARCH
============================*/
int binary_search(char* key, int min_index, int max_index)
{
	int mid_index = (max_index-min_index)/2 + min_index;
	char lc_title[40], lc_key[40];
	int cmp = strcmp(lower_case(library[mid_index].title, lc_title), lower_case(key, lc_key));
	if (max_index < min_index) 
		return min_index;
	else
		return cmp > 0 ? binary_search(key, min_index, mid_index-1) : cmp < 0 ? binary_search(key, mid_index+1, max_index) : mid_index;
}

/*============================
	CONTAINS
============================*/
int contains_song(char* key, int min_index, int max_index) 
{
	int mid_index = (max_index-min_index)/2 + min_index;
	char lc_title[40], lc_key[40];
	int cmp = strcmp(lower_case(library[mid_index].title, lc_title), lower_case(key, lc_key));
	if (max_index < min_index) 
		return 0;
	else
		return cmp > 0 ? contains_song(key, min_index, mid_index-1) : cmp < 0 ? contains_song(key, mid_index+1, max_index) : 1;
}

/*============================
	FIND INDEX
============================*/
int find_index_of_song_with_name(char* key) 
{
	return binary_search(key, 0, song_count-1);
}

/*============================
	LOOK UP SONG
============================*/
void look_up_song_with_name(char* key)
{
	if (contains_song(key, 0, song_count-1))
		print_song(find_index_of_song_with_name(key));
}

/*============================
	LOOK UP COMMAND
============================*/
void look_up_command()
{
	char title[40];
	getTitle(title);
	look_up_song_with_name(title);
}

/*============================
	CRUNCH DOWN
============================*/
void crunch_down_from_index(int index) 
{
	for(int i = song_count; i >= index; i--)
		library[i+1] = library[i];
}

/*============================
	CRUNCH UP
============================*/
void crunch_up_from_index(int index) 
{
	for(int i = index; i < song_count; i++)
		library[i] = library[i+1];
}

/*============================
	REMOVE SONG FROM LIBRARY
============================*/
void remove_song_from_MusicLibrary_by_name(char* key)
{
	if (contains_song(key, 0, song_count-1))
	{
		crunch_up_from_index(find_index_of_song_with_name(key));
		song_count--;
	}
	
}

/*============================
	DELETE COMMAND
============================*/
void delete_command() 
{
	char title[40];
	getTitle(title);
	remove_song_from_MusicLibrary_by_name(title);
}

/*============================
	ADD TO LIBRARY
============================*/
void add_song_to_MusicLibrary() 
{
	Song new_song = make_song();
	int index = find_index_of_song_with_name(new_song.title);
	crunch_down_from_index(index);
	library[index] = new_song;
	song_count++;
}

/*============================
	PRINT LIBRARY
============================*/
void print_MusicLibrary() 
{
	for(int i = 0; i < song_count; i++ )
		print_song(i);
}


/*============================
	ENSURE VALID COMMAND
============================*/
int ensure_valid_command(char command)
{
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
			return 1;
		default:
			break;
	}
	return 0;
}

/*============================
	READ COMMAND INPUT
============================*/
char read_command() 
{	
	char cmd;
	scanf(" %c%*c", &cmd);
	return ensure_valid_command(cmd) ? cmd : '\0';
}

/*============================
	EVALUATE COMMAND
============================*/
char evaluate_command(char cmd)
{
	switch (cmd)
	{
		case 'i':
		case 'I':
			add_song_to_MusicLibrary();
			break;
		case 'p':
		case 'P':
			print_MusicLibrary();
			break;
		case 'd':
		case 'D':
			delete_command();
			break;
		case 'l':
		case 'L':
			look_up_command();
			break;
		case 'q':
		case 'Q':
			store_MusicLibrary();
			fclose(m_fp);
			printf("quitting\n");
			return 'q';
		default:
			break;
	}
	return 'a';
}

/*============================
	TAKE COMMANDS
============================*/
char command_loop() 
{
	printf("prompt: \n");
	char ch = read_command();
	return evaluate_command(ch);
}


/*=========================================================================================================
	MAIN
=========================================================================================================*/
int main(int argc, char* argv[]) 
{
	m_filename = get_filename(argv[1]);
	open_file(m_filename, "r+");
	load_MusicLibrary();
	char ch;
	do
	{
		ch = command_loop();
	} while (ch != 'q');

	return 0;
}

