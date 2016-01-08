#include <stdio.h>
#include <string.h>
#define LIBRARY_SIZE 1024

struct Song {
	char* title;
	char* artist;
	int year;
};

void loadMemory(FILE* inputFile, struct Song arr[]) {

}

// load_MusicLibrary() {}

// store_MusicLibrary() {}



int main(int argc, char* argv[]) {
	struct Song library[LIBRARY_SIZE];




	FILE* ifp;

	char* inputFilename;

	if (argc > 1) { // if argument is given
		inputFilename = argv[1];
	}
	else { // if no argument then default to myMusic
		inputFilename = "myMusic";
	}

	ifp = fopen(inputFilename, "r+");
	if (ifp == NULL) { // file does not exist
		ifp = fopen(inputFilename, "w+");
	}
	
	


	fclose(ifp);
	return 0;
}
