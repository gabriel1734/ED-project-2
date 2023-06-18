#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct {
  char binario[5];
  int contador;
} ItemBinario;

// Função para gerar todos os binários possíveis do tamanho k
void gerarBinarios(int k, ItemBinario **binarios)
{
  int totalBinarios = 1 << k; // 2^k

  // Aloca memória para o array de binários
  *binarios = (ItemBinario *)malloc(totalBinarios * sizeof(ItemBinario));
  if (*binarios == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return;
  }

  // Gera todos os binários possíveis
  for (int i = 0; i < totalBinarios; i++)
  {
    for (int j = k - 1; j >= 0; j--)
    {
      (*binarios)[i].binario[j] = (i & (1 << (k - j - 1))) ? '1' : '0';
    }
    (*binarios)[i].binario[k] = '\0';
    (*binarios)[i].contador = 0;
  }
}

void concatenarBinarios(No *root, char *sequencia)
{
  if (root == NULL)
  {
    return;
  }

  // Concatena o binário do nó atual com a sequência existente
  strcat(sequencia, root->binary);

  concatenarBinarios(root->esq, sequencia); // Percorre a subárvore esquerda
  concatenarBinarios(root->dir, sequencia); // Percorre a subárvore direita
}

void dividirBinarios(const char *sequencia, int k)
{
  int tamanho = strlen(sequencia);
  int numItens = tamanho / k;

  printf("Itens de tamanho %d: ", k);
  for (int i = 0; i < numItens; i++)
  {
    for (int j = 0; j < k; j++)
    {
      printf("%c", sequencia[i * k + j]);
    }
    printf(" ");
  }
  printf("\n");
}

int compararItemBinario(const void *a, const void *b)
{
  const ItemBinario *item1 = (const ItemBinario *)a;
  const ItemBinario *item2 = (const ItemBinario *)b;
  return item2->contador - item1->contador;
}

// Função para contar a ocorrência de cada binário
void contarOcorrencias(const char *sequencia, int k, ItemBinario *itensBinarios)
{
  int totalBinarios = 1 << k; // 2^k
  int numItens = strlen(sequencia) / k;

  

  // Conta as aparições de cada binário na sequência
  for (int i = 0; i < numItens; i++)
  {
    for (int j = 0; j <= numItens - k; j++)
    {
      if (strncmp(sequencia + j, itensBinarios[i].binario, k) == 0)
      {
        itensBinarios[i].contador++;
      }
    }
  }

  // Ordena os itens binários em ordem decrescente pelo contador
  qsort(itensBinarios, totalBinarios, sizeof(ItemBinario), compararItemBinario);

  // Exibe todos os binários em ordem decrescente pelo número de aparições
  printf("Binários de tamanho %d em ordem decrescente pelo número de aparições:\n", k);
  for (int i = 0; i < totalBinarios; i++)
  {
    printf("%s: %d\n", itensBinarios[i].binario, itensBinarios[i].contador);
  }

  // Libera a memória alocada
  free(itensBinarios);
}