#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "invertedIndex.h"

#define MAX 100

int main(int argc, char *argv[])
{
	FILE *f;
	char fname[MAX];
  char files[MAX];
  char test[MAX];

  //Test if you input a collection of files txt
	if (argc < 2) {
		fprintf(stderr, "Usage: %s Collection of File Name\n", argv[0]);
		return EXIT_FAILURE;
	}
  strcpy(fname,argv[1]);


	InvertedIndexBST whatisreturn = generateInvertedIndex(fname);
	printf("\nOUTSIDE NOW\n\n");
	printInvertedIndex(whatisreturn);

	printf("\n\nTHIS IS FINAL TEST: ");
	showBSTreeNode(whatisreturn);
	printf("num of nodes: %d\n", BSTreeNumNodes(whatisreturn));
	InvertedIndexBST findingnemo = BSTreeFind(whatisreturn, "moon");
	printf("found nemo? [%s]\n", findingnemo->word);

  return 0;
}
