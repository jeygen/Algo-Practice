#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);

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
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
   

    
    
    
  }
  exit(0);
}
