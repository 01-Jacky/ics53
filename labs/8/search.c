#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_number(int i)
{
	printf("%d", i);
}

void print_string(char* s)
{
	printf("%s", s);
}

void print_match(char* file_name, int file_index, int line_number, char* line)
{
	print_number(file_index);
	print_string(file_name);
	print_number(line_number);
	print_number(line);
	printf("\n");
}

void add_all_matching_lines(char* pattern, int file_index, char* file_name)
{
	int line_number = 1;
	while (s = getline())
	{
		if (pattern_is_contained_within_line(pattern , s))
			print_match(file_name, file_index, line_number, s);
		line_number++;
	}
}

void search(char* pattern, int file_index, char* file_name)
{
	if (!is_readable(file_name))
		return;
	if (is_file(file_name))
		fork_thread add_all_matching+lines(pattern, file_index, file_name);
	else if (is_directory(file_name))
	{
		for each file name f, in contents of (file_name)
			search(pattern, file_index, file_name/f);
	}
}

int main(int argc, char* argv[])
{
	int file_index = 1;
	if (argc != 3)
		perror("usage: search pattern file");
	for each file name, f, in argv[2] to argv[argc-1]


	return 0;
}
