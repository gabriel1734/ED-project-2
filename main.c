#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"
#define MAX 100




int main(int argc, char *argv[]){
  int k, n;
  char linha[100];

  if(argc < 2){
    printf("Você deve passar o nome do arquivo como argumento!\n");
    return 1;
  }
  FILE *arq = fopen(argv[1], "r");
  if(arq == NULL){
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  fscanf(arq, "%d", &k);
  fscanf(arq, "%d", &n);
  fgetc(arq); // Pula o \n

  // Separa os números usando strtok()
  
  
  int i = 0;


  while(fgets(linha, sizeof(MAX), arq) != NULL){
    linha[strlen(linha)] = '\0';
    
    char *token = strtok(linha, ";");

    No *root = createNode(NULL);

    while (token != NULL){
      int decimal = atoi(token);
      char binary[33];
      decimalParaBinario(decimal, binary, k);
      root = insert(root, binary);
      printf("%s\n", binary);
      printf("%s\n", token);
      token = strtok(NULL, ";");

      i++;
    }
  }
  

  printf("k = %d\n", k);
  printf("n = %d\n", n);


  fclose(arq);

  return 0;
}