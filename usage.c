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
  printf("Returned Name: %s\n", returned);

  fscanf(ff, "%s", test);
  printf("Test: %s\n", test);
  returned = normaliseWord(test);
  printf("Returned Name: %s\n", returned);

  char * wtf = "HEY;";
  printf("Test: %s\n", wtf);
  returned = normaliseWord(wtf);
  printf("Returned Name: %s\n", returned);
  newBSTNode(returned);

  rewind(ff);
  int num_of_words = 0;
  while(fscanf(ff, "%s", test) == 1){
    num_of_words ++;
  }
  printf("Num: %d\n", num_of_words);



  InvertedIndexBST testTree = newBSTree();
  testTree = BSTreeInsert(testTree, wtf);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  showBSTreeNode(testTree);
  if(testTree != NULL){
    printf("NOTNULL\n");
  }
  showBSTreeNode(testTree);
  printf("curr: %s\n", testTree->word);
  if(testTree->right == NULL){
    printf("NULL right\n");
  }
  if(testTree->left == NULL){
    printf("NULL left\n");
  }

  char * wtff = "NASA?";
  testTree = BSTreeInsert(testTree, wtff);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("r curr: %s\n", testTree->right->word);

  char * wtfff = "AVA";
  testTree = BSTreeInsert(testTree, wtfff);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("l curr: %s\n", testTree->left->word);

  char * wtffff = "NOM";
  testTree = BSTreeInsert(testTree, wtffff);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("r r curr: %s\n", testTree->right->right->word);

  char * wtfffff = "NAA";
  testTree = BSTreeInsert(testTree, wtfffff);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("r l curr: %s\n", testTree->right->left->word);

  char * wtffffff = "BAA";
  testTree = BSTreeInsert(testTree, wtffffff);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("l r curr: %s\n", testTree->left->right->word);

  char * wtfffffdf = "A";
  testTree = BSTreeInsert(testTree, wtfffffdf);
  showBSTreeNode(testTree);
  printf("num of nodes: %d\n", BSTreeNumNodes(testTree));
  printf("l l curr: %s\n", testTree->left->left->word);






  return 0;
}
