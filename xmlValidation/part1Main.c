#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty(); // I added this, check if thats allowed

/*
Part 1
Reads stdin and determines if valid <foo> </foo> format
If valid, stdout "Valid" and exit eith code 0
If invalid, stdout "Invalid" and exit with code 1
Can print under, overdflow and other desired info to stderr

TO DO:
Code stack-ish from the lab manual into main()
Implement stack funcitions push(), pop(), isEmpty() in intStack.c
*/

int main(int argc, char * argv[])
{
	int ch;
	int startTag;
	int startTagcloser;

	while ((ch = getchar()) != EOF) {
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
			continue;

			//Checking startTag section
			//Working so far
			if (ch == '<') {
				startTag = getchar();
			        startTagcloser = getchar();
				if (islower(startTag) && startTagcloser == '>')
					push(startTag);
				else { 
					fprintf(stdout, "NOT valid\n");
					continue;
				}
			}

/*
			if (ch == '<' && getchar() == '/' && getchar() == startTag)
				pop();
		if (isEmpty() == 0)
			fprintf(stdout, "Valid");
		else
			fprintf(stdout, "Invalid");
 */   
	}	
  exit(0);
}
