#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/*typedef struct no {
  int decimal;
  char binary[33];
  struct no *esq;
  struct no *dir;
} No;

No * createNode(char val) {
  No *newNode = (No *) malloc(sizeof(No));
  newNode->binary = val;
  newNode->esq = NULL;
  newNode->dir = NULL;
  return newNode;
}

No * insert(No * root, char val) {
  if(root == NULL) {
    return createNode(val);
  }
  if(val < root->decimal) {
    root->esq = insert(root->esq, val);
  } else if(val > root->decimal) {
    root->dir = insert(root->dir, val);
  }

  return root;
}


No * remove(No * root, char val) {
  if(root == NULL) {
    return root;
  }
  if(val < root->decimal) {
    root->esq = remove(root->esq, val);
  } else if(val > root->decimal) {
    root->dir = remove(root->dir, val);
  } else {
    if(root->esq == NULL) {
      No *temp = root->dir;
      free(root);
      return temp;
    } else if(root->dir == NULL) {
      No *temp = root->esq;
      free(root);
      return temp;
    }

    No *temp = minValueNode(root->dir);
    root->decimal = temp->decimal;
    root->dir = remove(root->dir, temp->decimal);
  }
  return root;
}*/