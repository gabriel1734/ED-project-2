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

// Função para comparar dois binários
int compararBinarios(const char *binario1, const char *binario2)
{
  return strcmp(binario1, binario2);
}

// Função para contar a ocorrência de cada binário
void contarOcorrencias(const char *sequencia, int k)
{
  int tamanho = strlen(sequencia);
  int numItens = tamanho / k;
  char **binarios = (char **)malloc(numItens * sizeof(char *));
  int *contagem = (int *)calloc(numItens, sizeof(int));

  // Inicializa o array de binários com os itens da sequência
  for (int i = 0; i < numItens; i++)
  {
    binarios[i] = (char *)malloc(5 * sizeof(char));
    strncpy(binarios[i], sequencia + i * k, k);
    binarios[i][k] = '\0';
  }

  // Conta as ocorrências de cada binário
  for (int i = 0; i < numItens; i++)
  {
    if (contagem[i] == 0)
    {
      contagem[i] = 1;
      for (int j = i + 1; j < numItens; j++)
      {
        if (compararBinarios(binarios[i], binarios[j]) == 0)
        {
          contagem[i]++;
          contagem[j] = -1; // Marca o binário como repetido para evitar contagens duplicadas
        }
      }
    }
  }

  // Imprime a contagem de cada binário repetido
  for (int i = 0; i < numItens; i++)
  {
    if (contagem[i] > 1)
    {
      printf("O binário %s se repete %d vezes.\n", binarios[i], contagem[i]);
    }
  }

  // Libera a memória alocada
  for (int i = 0; i < numItens; i++)
  {
    free(binarios[i]);
  }
  free(binarios);
  free(contagem);
}