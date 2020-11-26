#include <stdio.h>
#include <malloc.h>

int main()
{

  int *numbers = calloc(5, sizeof(int));

  for (int i = 0; i < 5; ++i)
  {
    printf("\nDigite o valor do %d elemento: ", i + 1);
    scanf("%d", (numbers + i));

    printf("\nDobro de %d: %d\n", *(numbers + i), *(numbers + i) * 2);
  }

  free(numbers);

  return 0;
}
