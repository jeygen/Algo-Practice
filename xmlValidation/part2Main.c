#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty(); // I added this, check if thats allowed

/*
* Part 2
* Same as part 1, but now counting and saving each tag
*/

int main(int argc, char * argv[])
{
	int ch;
	int startTag; // for char after '<'
	int startTagcloser; // for '>' after start tag
	int endTag; // for char after '</'
	int endTagcloser;
	//int **table;
	int j = 0;
	int i = 'a';
	int table [26][2] = {    {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, 
				 {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
				 {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
				 {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
				 {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0},
	  		         {'z', 0}}; 


	for (i = 'a'; i <= 'z'; i++) {
		fprintf(stdout, "%c %d\n", table[i][0], table[i][1]);
	} // this array is printing wonky
		

	while ((ch = getchar()) != EOF) {
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')) 
			continue;

		//Checking to see if <a></a> format is followed.
		//Only works if single char and lowercase (ask to make sure this is desired)
		//
		if (ch == '<') {

			startTag = getchar();
			

			if (startTag == '/') {
				endTag = getchar();
				endTagcloser = getchar();

				if (endTagcloser == '>') {
					if (pop() == endTag) {
						for (i = 'a'; i <= 'z'; i++) {
							if (table[i][1] > 0)
								fprintf(stdout, "%c %d\n", table[i][0], table[i][1]);
						}	
						fprintf(stdout, "Valid\n");
						exit(0);
						//continue;
					}
					else {
						fprintf(stdout, "NOT Valid\n");
						exit(1);
						//continue;
					}
				}
				else  
					continue;
			}

			startTagcloser = getchar();

			if (startTagcloser != '>') {
				fprintf(stdout, "NOT Valid\n");
				exit(1);
				//continue;
			}

			if (islower(startTag) && startTagcloser == '>') {
				push(startTag);
				table[startTag][j++];
			}
			else { 
				continue;
			}
		}
	}

  exit(0);
}
