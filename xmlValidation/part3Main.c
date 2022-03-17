#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
#define MAX_TAG_LENGTH 100

int main(int argc, char * argv[])
{
	int ch;
	char startTag[MAX_TAG_LENGTH]; // for string after '<'
	int startTagcloser; // for '>' after start tag
	char endTag[MAX_TAG_LENGTH]; // for char after '</'
	int endTagcloser;
  int i = 0;
  // I added this
	//char *temp = "Boom";
  char *temp2 = (char*)malloc(50*sizeof(char));
  //push(temp);
  
  for (i = 0; i < MAX_TAG_LENGTH; i++) { 
          startTag[i] = '\0';
          endTag[i] = '\0';
  }
  
  
  //TOP:
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    i = 0;
		if (ch == '<') {
      
			startTag[0] = getchar();

      if (isalpha(startTag[0]) && startTag[0] != '/') { //this skips over non-alpha but doesnt invalidate
        while ((ch = getchar()) != '>') {//&& isalpha(ch)) 
            if (isdigit(ch)) {
              fprintf(stdout, "NOT valid\n");
              exit(1);
            //  goto TOP;
            }
            if (i < MAX_TAG_LENGTH)
              startTag[++i] = ch;
        }
        push(startTag);
        fprintf(stdout, "print startTag: %s\n", startTag); // will delete, just to check
        for (i = 0; i < MAX_TAG_LENGTH; i++) // important, dont leave commented out by end of session
          startTag[i] = 0;


        fprintf(stdout, "\nthis is pop: %s\n", pop());
            
      }
    }

/*
      if (startTag[0] == '/') { // this section not working, prob alis in stringStack probably
        i = 0;
        //endTag[0] = '/';
        while ((ch = getchar()) != '>') {
          if (isdigit(ch)) {
            fprintf(stdout, "NOT valid\n");
            exit(1);
          //  goto TOP;
          }
          if (i < MAX_TAG_LENGTH)
            endTag[++i] = ch;
        }
        push(endTag);
        temp2 = endTag;
         fprintf(stdout, "\nthis is pop: %s", pop());
         fprintf(stdout, "\nthis is temp: %s", temp2);

       
        if(strlen(temp) == (1 + strlen(pop())))
          fprintf(stdout, "Valid\n");
        else
          fprintf(stdout, "NOT valid\n");
          exit(1);
         
   for (i = 0; i < MAX_TAG_LENGTH; i++)
         endTag[i] = '\0';
     }
*/


    } // main while brace		
  
  

  exit(0);
}
