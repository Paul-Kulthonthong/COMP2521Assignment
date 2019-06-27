#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "invertedIndex.h"


char * normaliseWord(char *tobenormalised){
//  char * normalised = "";
  char buf[100] = "";
  int i = 0;
  while( tobenormalised[i] ) {
      buf[i] = tolower(tobenormalised[i]);
      i++;
  }
  printf("This is buf: %s\n", buf);
  char * normalised = buf;
  return normalised;
}
//InvertedIndexBST * generateInvertedIndex(char *collectionFilename){

  //return new_inverted_index_node;
//}
void printInvertedIndex(InvertedIndexBST tree){

  return;
}
