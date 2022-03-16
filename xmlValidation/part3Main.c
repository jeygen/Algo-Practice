#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
#define MAX_TAG_LENGTH 50

int main(int argc, char * argv[])
{
	int ch;
	char startTag[MAX_TAG_LENGTH]; // for string after '<'
	int startTagcloser; // for '>' after start tag
	int endTag[MAX_TAG_LENGTH]; // for char after '</'
	int endTagcloser;
  int i = 0;
  // I added this
	char *temp = "Boom";
  push(temp);
  //
  //TOP:
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    i = 0;
		if (ch == '<') {
      
			startTag[0] = getchar();

      if (isalpha(startTag[0]) && startTag[0] != '/') { //this skips over non-alpha but doesnt invalidate
        while ((ch = getchar()) != '>') {//&& isalpha(ch)) {
          if (isdigit(ch)) {
            fprintf(stdout, "NOT valid\n");
            exit(1);
          //  goto TOP;
          }
          if (i < MAX_TAG_LENGTH)
            startTag[++i] = ch;
        }
        push(startTag);
      fprintf(stdout, "%s", startTag); // will delete, just to check
      for (i = 0; i < MAX_TAG_LENGTH; i++)
        startTag[i] = 0;
      }

      if (startTag[0] == '/') { // this section not working, prob alis in stringStack probably
        while ((ch = getchar()) != '>') {
          if (isdigit(ch)) {
            fprintf(stdout, "NOT valid\n");
            exit(1);
          //  goto TOP;
          }
          if (i < MAX_TAG_LENGTH)
            endTag[++i] = ch;
          if(strcmp(endTag, pop()))
            fprintf(stdout, "Valid");
        }
        for (i = 0; i < MAX_TAG_LENGTH; i++)
        startTag[i] = 0;
      }


    }		
  }
  

  exit(0);
}
