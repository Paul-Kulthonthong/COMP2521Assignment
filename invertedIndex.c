#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "invertedIndex.h"

InvertedIndexBST newBSTNode(char *inputword);
InvertedIndexBST BSTreeInsert(InvertedIndexBST t, char *inputword);
InvertedIndexBST newBSTree();
int BSTreeNumNodes(InvertedIndexBST t);
void showBSTreeNode(InvertedIndexBST t);

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
//
//  return new_inverted_index_node;
//}

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




void printInvertedIndex(InvertedIndexBST tree){

  return;
}
