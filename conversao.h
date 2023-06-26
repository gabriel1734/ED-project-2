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


