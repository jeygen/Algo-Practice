#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

	int entries;
	
	for (entries = 0; entries < atoi(argv[1]); entries++) 
		fprintf(stdout, "%d\n", rand() % 3000);

	exit(0);
}
