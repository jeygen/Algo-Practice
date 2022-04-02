#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern void addHeap(int);
extern void printHeap();

int main(int argc, char * argv[])
{
  int value;

  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    //if (isdigit(value)) 
    	addHeap(value);
  }

  printHeap();

  exit(0);
}
