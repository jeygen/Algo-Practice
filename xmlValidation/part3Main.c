#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);

int main(int argc, char * argv[])
{
  int ch;
	char *temp = "Boom";
push(temp);
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    
    
    
  }
  exit(0);
}
