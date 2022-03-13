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
	int startTag; // for char after '<'
	int startTagcloser; // for '>' after start tag
	int endTag; // for char after '</'
	int endTagcloser;

	while ((ch = getchar()) != EOF) {
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')) 
			continue;

		//Checking to see if <a></a> format is followed.
		//Only works if single char and lowercase (ask to make sure this is desired)
		//Printing valid twice, its validating per <>, make so tracks each <> and says invalid/valid only once
		if (ch == '<') {

			startTag = getchar();
			

			if (startTag == '/') {
				endTag = getchar();
				endTagcloser = getchar();

				if (endTagcloser == '>') {
					if (pop() == endTag) {
						fprintf(stdout, "Valid\n");
						continue;
					}
					else {
						fprintf(stdout, "NOT Valid\n");
						continue;
					}
				}
				else  
					continue;
			}

			startTagcloser = getchar();

			if (startTagcloser != '>') {
				fprintf(stdout, "NOT Valid\n");
				continue;
			}

			if (islower(startTag) && startTagcloser == '>')
				push(startTag);
			else { 
				continue;
			}
		}
	}

  exit(0);
}
