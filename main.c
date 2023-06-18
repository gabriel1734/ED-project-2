#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"
#include "conversao.h"
#include "comparacao.h"
#define MAX 1000000




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
  
  
  No *root = NULL;
  char sequencia[1000000] = "";

  while(fgets(linha, sizeof(MAX), arq) != NULL){
    linha[strlen(linha)] = '\0';
    
    char *token = strtok(linha, ";");
    
    
   

    while (token != NULL){
      int decimal = atoi(token);
      char binary[33];
      decimalParaBinario(decimal, binary, n);
      root = insert(root, binary, decimal);
      //printf("%s\n", token);
      //printf("%s\n", binary);
      token = strtok(NULL, ";");

      i++;
    }
  }

  ItemBinario *binarios;

  // Gera todos os binários de tamanho k
  gerarBinarios(k, &binarios);

  //printf("k = %d\n", k);
  //printf("n = %d\n", n);
  //printf("Percurso em ordem: ");
  //percorrerEmOrdem(root);
  //printf("\n");
  //printf("Raiz: %d\n", root->decimal);

  concatenarBinarios(root, sequencia);
  printf("Sequência: %s\n", sequencia);
  //dividirBinarios(sequencia, k);
  contarOcorrencias(sequencia, k, binarios);


  

  fclose(arq);

  return 0;
}