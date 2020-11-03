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

  int sum = 0;

  for (size_t i = 0; i < 4; ++i) 
  {
    for (size_t j = 0; j < 4; ++j)
    {
      for (size_t k = 0; k < 6; ++k)
      {
        sum += (m[i][k] + n[k][j]);
      }
    }
  }

  printf("\n\nSoma = %d\n", sum);

  return 0;
}