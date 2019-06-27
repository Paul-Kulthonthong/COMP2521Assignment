#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "invertedIndex.h"


char * normaliseWord(char *tobenormalised){
  char buf[100] = "";
  int i = 0;
  while( tobenormalised[i] ) {
      buf[i] = tolower(tobenormalised[i]);
      i++;
  }
//  printf("This is size of buf: %lu\n", sizeof(buf));
  char test[i+1];
  strcpy(test, buf);
//  printf("This is size of norm: %lu\n", sizeof(test));
//  printf("This is word: %s\n", test);
  printf("This is i and word last letter: %d & %c\n", i, test[i-1]);

  if(test[i-1] == '.'|| test[i-1] == ',' || test[i-1] == ';' || test[i-1] == '?'){
    test[i-1] = '\0';
  }

  char * normalised = strdup(test);
  return normalised;
}



//InvertedIndexBST * generateInvertedIndex(char *collectionFilename){

  //return new_inverted_index_node;
//}




void printInvertedIndex(InvertedIndexBST tree){

  return;
}
