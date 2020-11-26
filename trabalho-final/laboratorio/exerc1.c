#include <stdio.h>
#include <malloc.h>

int main()
{

  int size;

  printf("\nDigite o tamanho do vetor: ");
  scanf("%d", &size);

  int *numbers = malloc(sizeof(int) * size);

  int sumPairs = 0, sumImpars = 0, higher = 0, pairs = 0, impars = 0;

  for (int i = 0; i < size; ++i)
  {
    printf("\nDigite o valor do %d elemento: ", i + 1);
    scanf("%d", &numbers[i]);

    if (numbers[i] % 2 == 0)
    {
      sumPairs += numbers[i];
      pairs++;
    }
    else
    {
      sumImpars += numbers[i];
      impars++;
    }

    if (numbers[i] > higher)
    {
      higher = numbers[i];
    }
  }

  printf("\nQuantidade de numeros pares: %d", pairs);
  printf("\nQuantidade de numeros impares: %d", impars);
  printf("\n\nSoma dos numeros pares: %d", sumPairs);
  printf("\nSoma dos numeros impares: %d", sumImpars);
  printf("\n\nMaior numero: %d\n", higher);

  free(numbers);

  return 0;
}
