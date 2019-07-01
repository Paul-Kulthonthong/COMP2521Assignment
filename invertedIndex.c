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
void BSTreeInfix(InvertedIndexBST t);
void BSTreePrefix(InvertedIndexBST t);
void BSTreePostfix(InvertedIndexBST t);
void showBSTreeNodeandList(InvertedIndexBST t);
InvertedIndexBST BSTreeFind(InvertedIndexBST t, char *inputword);
void fileNodeInsert(InvertedIndexBST indexWordNode, FileList fileNode);


FileList newFileNode(char *inputfile);
void addFileNode(InvertedIndexBST indexWordNode, FileList fileNode);
int fileNodeExist(InvertedIndexBST t, char *inputfile);
double calculatetf(char *file, char *word);

char * normaliseWord(char *tobenormalised){
  int i = 0;
  while( tobenormalised[i] ) {
    tobenormalised[i] = tolower(tobenormalised[i]);
    i++;
  }
  if(tobenormalised[i-1] == '.'|| tobenormalised[i-1] == ',' || tobenormalised[i-1] == ';' || tobenormalised[i-1] == '?'){
    tobenormalised[i-1] = '\0';
  }
  return tobenormalised;
}


InvertedIndexBST generateInvertedIndex(char *collectionFilename){

  InvertedIndexBST newtree = malloc(sizeof(InvertedIndexBST));
  newtree = newBSTree();
  FILE *f;
  FILE *ff;
  char filestemp[MAX];
  char infileword[MAX];

  if ((f = fopen(collectionFilename,"r")) == NULL) {
  		fprintf(stderr, "Can't open file %s\n", collectionFilename);
  		return newtree; // ASK ABOUT EXIT FAILURE
	}
//  fscanf(f, "%s", filestemp);
  while(fscanf(f, "%s", filestemp) != EOF){
  //  printf("This is the file: %s\n", filestemp);

    char * filename  = getfiledir(collectionFilename, filestemp);
  //  printf("from currfile[%s]\n", filename);

    if ((ff = fopen(filename,"r")) == NULL) {
    		fprintf(stderr, "Can't open file %s\n", filename);
    		return newtree;
  	}
    rewind(ff);
    int num_of_words = 0;
    while(fscanf(ff, "%s", infileword) != EOF){
      char* returned = strdup(normaliseWord(infileword));
  		//printf("This is the words in the file that has been normalised: [%s]\n", returned);
      newtree = BSTreeInsert(newtree, returned);
      int check = fileNodeExist(BSTreeFind(newtree, returned), filestemp);
      if(check == 0){
        FileList newfn = newFileNode(filestemp);
        newfn->tf = calculatetf(filename, returned);
        addFileNode(BSTreeFind(newtree, returned), newfn);
      }
      //printf("FileNODE: [%s]\n", newfn->filename);

      num_of_words ++;
    }
    fclose(ff);
  }
  fclose(f);

  return newtree;
}

double calculatetf(char *file, char *word){
  double tf = 0;
  double wordcount = 0;
  double wordpresent = 0;
  FILE *fff;
  char infileword[MAX];
  if ((fff = fopen(file,"r")) == NULL) {
      fprintf(stderr, "Can't open file %s\n", file);
      return EXIT_FAILURE;
  }
  rewind(fff);
  while(fscanf(fff, "%s", infileword) != EOF){
    if(strcmp(normaliseWord(infileword), word) == 0){
      wordpresent++;
    }
    wordcount++;
  }
  fclose(fff);
  tf = wordpresent/wordcount;
  return tf;
}


FileList newFileNode(char *inputfile)
{
  FileList new = malloc(sizeof(struct FileListNode));
  assert(new != NULL);
  new->filename = strdup(inputfile);
  new->tf = 0; // CREATE TF CALCULATION FILE
  new->next = NULL;
  return new;
}

void addFileNode(InvertedIndexBST indexWordNode, FileList fileNode)
{
  if(indexWordNode->fileList == NULL){
    indexWordNode->fileList = fileNode;
  }
  else{
    fileNodeInsert(indexWordNode, fileNode);
  }
}

void fileNodeInsert(InvertedIndexBST indexWordNode, FileList fileNode){

  FileList itterativepointer = indexWordNode->fileList;
  if (strcmp(itterativepointer->filename,  fileNode->filename) > 0) {
    fileNode->next = itterativepointer;
    indexWordNode->fileList = fileNode;
    return;
  }
  else{
    while(strcmp(itterativepointer->filename,  fileNode->filename) < 0){
      if(itterativepointer->next == NULL){
        itterativepointer->next = fileNode;
        return;
      }
      else if(strcmp(itterativepointer->next->filename,  fileNode->filename) > 0){
        break;
      }
      else{
        itterativepointer = itterativepointer->next;
      }
    }
    fileNode->next = itterativepointer->next;
    itterativepointer->next = fileNode;
    return;
  }

}

int fileNodeExist(InvertedIndexBST t, char *inputfile){
  FileList itterative = t->fileList;
  int returnvalue = 0;
  while(itterative != NULL){
    if(strcmp(itterative->filename, inputfile) == 0){
      returnvalue = 1;
    }
    itterative = itterative->next;
  }
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
    //printf("here to the left");
    t->left = BSTreeInsert(t->left, inputword);
  }
	else if (strcmp(inputword, t->word) > 0){
    //printf("here to the right");
		t->right = BSTreeInsert(t->right, inputword);
  }
	else; // (strcmp(inputword, t->word) == 0)
		// don't insert duplicates */
	return t;
}

InvertedIndexBST BSTreeFind(InvertedIndexBST t, char *inputword)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(inputword, t->word) < 0)
		return BSTreeFind(t->left, inputword);
	else if (strcmp(inputword, t->word) > 0)
		return BSTreeFind(t->right, inputword);
	else // (v == t->value)
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

void showBSTreeNodeandList(InvertedIndexBST t)
{
	if (t == NULL) return;
	printf("%s ", t->word);
  FileList itterative = t->fileList;
  while(itterative != NULL){
    printf("%s [tf:%f] ", itterative->filename, itterative->tf);
    itterative = itterative->next;
  }
  printf("\n");
}

void BSTreeInfix(InvertedIndexBST t)
{
	if (t == NULL) return;
	BSTreeInfix(t->left);
	showBSTreeNode(t);
	BSTreeInfix(t->right);
}

void BSTreePrefix(InvertedIndexBST t)
{
	if (t == NULL) return;
	showBSTreeNode(t);
	BSTreePrefix(t->left);
	BSTreePrefix(t->right);
}

void BSTreePostfix(InvertedIndexBST t)
{
	if (t == NULL) return;
	BSTreePostfix(t->left);
	BSTreePostfix(t->right);
	showBSTreeNode(t);
}

char * getfiledir(char * collectionFilename, char *filename)
{
  char currfile[MAX]= "\0";
  char* dir = dirname(collectionFilename);

  strcat(currfile, dir);
  strcat(currfile, "/");
  strcat(currfile, filename);

  char * filedir = strdup(currfile);
  return filedir;
}

void printInvertedIndex(InvertedIndexBST tree)
{
  if (tree == NULL) return;
	printInvertedIndex(tree->left);
	showBSTreeNodeandList(tree);
	printInvertedIndex(tree->right);
  return;
}
