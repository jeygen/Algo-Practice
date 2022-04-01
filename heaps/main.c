#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern void addHeap(int);

int main(int argc, char * argv[])
{
  int value;

  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    //if (isdigit(value)) 
    	addHeap(value);
  }

  exit(0);
}
