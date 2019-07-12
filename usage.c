#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "invertedIndex.h"

#define MAX 100

int main(int argc, char *argv[])
{
	char fname[MAX];

  //Test if you input a collection of files txt
	if (argc < 2) {
		fprintf(stderr, "Usage: %s Collection of File Name\n", argv[0]);
		return EXIT_FAILURE;
	}
  strcpy(fname,argv[1]);
    char *collectionfile = malloc(strlen(fname));
    strcpy(collectionfile, fname);

	InvertedIndexBST whatisreturn = generateInvertedIndex(collectionfile);
	printf("\nOUTSIDE NOW\n\n");
	printInvertedIndex(whatisreturn);


	printf("\n\nTHIS IS FINAL TEST: ");
	printf("num of nodes: %d\n", BSTreeNumNodes(whatisreturn));
	TfIdfList testtdf = calculateTfIdf(whatisreturn, "waves", numofdocuments(collectionfile));
	printTfIdf(testtdf);
	testtdf = calculateTfIdf(whatisreturn, "weather", numofdocuments(collectionfile));
	printTfIdf(testtdf);
	testtdf = calculateTfIdf(whatisreturn, "eu", numofdocuments(collectionfile));
	printTfIdf(testtdf);
	printf("\n");
	char *words[] = { "waves", "weather", "eu", NULL };
	TfIdfList retrived = retrieve(whatisreturn, words , numofdocuments(collectionfile));
	printf("SORTED: ");
	printTfIdf(retrived);
  return 0;
}
