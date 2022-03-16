#include <stdlib.h>
#include <string.h>

// hash table size is not prime - not sure why, maybe it can be changed?
// need to add collision protection

#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};

Entry hash_table[HASH_TABLE_SIZE]; // array of Entries 

void add(char * tag)
{
  //char tempArr[50];
  //strcpy(tempArr, tag); 
  Entry *currentEntry = (Entry*) malloc(sizeof(Entry)); // creating and mem allocating currentEntry
  int temp = atoi(tag); // converting string to integer
  currentEntry->count = temp % HASH_TABLE_SIZE; // determining what bin to put entry // div method I think
  currentEntry->string = tag; // storing unconverted string to *string 
}
