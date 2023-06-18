#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  int decimal;
  char binary[33];
  struct no *esq;
  struct no *dir;
} No;

No * createNode(const char* binary, int decimal) {
  No *newNode = (No *) malloc(sizeof(No));
  newNode->decimal = decimal;
  strcpy(newNode->binary, binary);
  newNode->esq = NULL;
  newNode->dir = NULL;
  return newNode;
}

void queimaArvore(No *root) {
  if (root == NULL) {
    return;
  }

  queimaArvore(root->esq);
  queimaArvore(root->dir);
  free(root);
}

void percorrerEmOrdem(No *root) {
  if (root == NULL) {
    return;
  }

  percorrerEmOrdem(root->esq);        // Percorre a subárvore esquerda
  printf("%s ", root->binary);       // Imprime o valor do nó atual
  percorrerEmOrdem(root->dir);        // Percorre a subárvore direita
}

No * insert(No * root, char *binary, int decimal) {
  if(root == NULL) {
    return createNode(binary, decimal);
  }
  if(decimal < root->decimal) {
    root->esq = insert(root->esq, binary, decimal);
  } else if(decimal > root->decimal) {
    root->dir = insert(root->dir, binary, decimal);
  }

  return root;
}


