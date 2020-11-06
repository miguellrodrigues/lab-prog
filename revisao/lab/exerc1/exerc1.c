#include <stdio.h>

int main(void)
{
  int m[4][6], n[6][4];

  for (size_t i = 0; i < 4; ++i) 
  {
    for (size_t j = 0; j < 6; ++j)
    {
      printf("\nDigite o valor do elemento M(%d, %d): ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
    }
  }

  for (size_t i = 0; i < 6; ++i) 
  {
    for (size_t j = 0; j < 4; ++j)
    {
      printf("\nDigite o valor do elemento N(%d, %d): ", i + 1, j + 1);
      scanf("%d", &n[i][j]);
    }
  }

  int sumLineColumn[4];

  for (size_t i = 0; i < 4; ++i) 
  {
    sumLineColumn[i] = 0;

    for (size_t j = 0; j < 6; ++j)
    {
      sumLineColumn[i] += m[i][j] + n[j][i];
    }
  }

  for (size_t i = 0; i < 4; ++i)
  {
    printf("\nSoma da %d linha com a %d coluna: %d", i + 1, i + 1, sumLineColumn[i]);
  }

  return 0;
}