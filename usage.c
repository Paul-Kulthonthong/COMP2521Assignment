#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "invertedIndex.h"

#define MAX 100

int main(int argc, char *argv[])
{

	FILE *f;         // file handle
	char fname[MAX]; // file name

	// Check command-line args
  char files[MAX];
  char test[MAX];
  //Test if you input a collection of files txt
	if (argc < 2) {
		fprintf(stderr, "Usage: %s Collection of File Name\n", argv[0]);
		return EXIT_FAILURE;
	}

  strcpy(fname,argv[1]);
  if ((f = fopen(fname,"r")) == NULL) {
  		fprintf(stderr, "Can't open file %s\n", argv[1]);
  		return EXIT_FAILURE;
	}
  fscanf(f, "%s", files);
  printf("File name: %s\n", files);
  FILE *ff;
  if ((ff = fopen(files,"r")) == NULL) {
  		fprintf(stderr, "Can't open file %s\n", argv[1]);
  		return EXIT_FAILURE;
	}

  fscanf(ff, "%s", test);
  printf("Test: %s\n", test);
  char *returned = normaliseWord(test);
  printf("Returned Name: [%s]\n", returned);

  fscanf(ff, "%s", test);
  printf("Test: %s\n", test);
  returned = normaliseWord(test);
  printf("Returned Name: [%s]\n", returned);


  rewind(ff);
  int num_of_words = 0;
  while(fscanf(ff, "%s", test) == 1){
		printf("This is the words in the file: %s\n", test);
    num_of_words ++;
  }
  printf("Num: %d\n", num_of_words);

	fclose(ff);
	fclose(f);

	InvertedIndexBST whatisreturn = generateInvertedIndex(fname);
	printf("THIS IS FINAL TEST: ");
	showBSTreeNode(whatisreturn);
	printf("num of nodes: %d\n", BSTreeNumNodes(whatisreturn));
	printf("\n");






  return 0;
}
