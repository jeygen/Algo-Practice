#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int entries;
	
	for (entries = 0; entries < 35; entries++) 
		fprintf(stdout, "%d\n", rand() % 200);

	exit(0);
}
