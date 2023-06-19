#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void decimalParaBinario(int k, char *binary, int kBits)
{
  for (int i = kBits - 1; i >= 0; i--)
  {
    binary[i] = (k % 2) + '0';
    k /= 2;
  }
}

void printBinaryUtil(int binary[], int n, int i, int *count, int **binaries)
{
  if (i == n)
  {
    // Imprime o número binário atual
    for (int j = 0; j < n; j++)
    {
      printf("%d", binary[j]);
    }
    printf("\n");

    // Armazena o número binário para posterior comparação
    for (int j = 0; j < n; j++)
    {
      binaries[*count][j] = binary[j];
    }
    (*count)++;

    return;
  }

  // Preenche o bit atual com 0 e chama recursivamente para o próximo bit
  binary[i] = 0;
  printBinaryUtil(binary, n, i + 1, count, binaries);

  // Preenche o bit atual com 1 e chama recursivamente para o próximo bit
  binary[i] = 1;
  printBinaryUtil(binary, n, i + 1, count, binaries);
}

