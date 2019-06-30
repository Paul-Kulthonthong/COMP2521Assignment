#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <libgen.h>

#include "invertedIndex.h"

#define MAX 100

InvertedIndexBST newBSTNode(char *inputword);
InvertedIndexBST BSTreeInsert(InvertedIndexBST t, char *inputword);
InvertedIndexBST newBSTree();
int BSTreeNumNodes(InvertedIndexBST t);
void showBSTreeNode(InvertedIndexBST t);
char * getfiledir(char * collectionFilename, char *filename);

char * normaliseWord(char *tobenormalised){
  char buf[MAX] = "";
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


InvertedIndexBST * generateInvertedIndex(char *collectionFilename){

  InvertedIndexBST * returnvalue = malloc(sizeof(InvertedIndexBST));
  *returnvalue = newBSTree();
  FILE *f;
  char filestemp[MAX];

  if ((f = fopen(collectionFilename,"r")) == NULL) {
  		fprintf(stderr, "Can't open file %s\n", collectionFilename);
  		return returnvalue; // ASK ABOUT EXIT FAILURE
	}
  fscanf(f, "%s", filestemp);
  printf("This is the first file: %s\n", filestemp);

  char * filename  = getfiledir(collectionFilename, filestemp);
  printf("from currfile[%s]\n", filename);


  char * wtf = "HEYAAAA";
  *returnvalue = BSTreeInsert(*returnvalue, wtf);
  char * wtff = "IWANNACRY";
  *returnvalue = BSTreeInsert(*returnvalue, wtff);
  printf("THIS IS FINAL TEST: ");
	showBSTreeNode(*returnvalue);
	printf("num of nodes: %d\n", BSTreeNumNodes(*returnvalue));
  return returnvalue;
}

InvertedIndexBST newBSTree()
{
	return NULL;
}

InvertedIndexBST newBSTNode(char *inputword)
{
	InvertedIndexBST new = malloc(sizeof(struct InvertedIndexNode));
	assert(new != NULL);
	new->word = inputword;
//  printf("malloced word: %s\n", new->word);
	new->left = new->right = NULL;
  new->fileList = NULL;
	return new;
}

InvertedIndexBST BSTreeInsert(InvertedIndexBST t, char *inputword)
{

	if (t == NULL){
		return newBSTNode(inputword);
  }
	else if (strcmp(inputword, t->word) < 0){
    printf("here to the left");
    t->left = BSTreeInsert(t->left, inputword);
  }
	else if (strcmp(inputword, t->word) > 0){
    printf("here to the right");
		t->right = BSTreeInsert(t->right, inputword);
  }
	else; // (strcmp(inputword, t->word) == 0)
		// don't insert duplicates */
	return t;
}

int BSTreeNumNodes(InvertedIndexBST t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BSTreeNumNodes(t->left)
	             + BSTreeNumNodes(t->right);
}

void showBSTreeNode(InvertedIndexBST t)
{
	if (t == NULL) return;
	printf("%s\n", t->word);
}

char * getfiledir(char * collectionFilename, char *filename){
  char currfile[MAX]= "\0";
  char* dir = dirname(collectionFilename);

  strcat(currfile, dir);
  strcat(currfile, "/");
  strcat(currfile, filename);

  char * filedir = strdup(currfile);
  return filedir;
}















void printInvertedIndex(InvertedIndexBST tree){

  return;
}
