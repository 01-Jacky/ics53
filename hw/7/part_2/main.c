
#include <fcntl.h> // for open()
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read() write() close()
#include <sys/types.h>
#include <limits.h>


int main() {
	
	char input[1024];
	fgets(input, 1024, stdin); // get input
	int pip[2];

	if(pipe(pip) == -1)
		return 1;

	
	return 0;


}
