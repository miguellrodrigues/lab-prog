#include <stdio.h>

int isPrime(int n)
{
  size_t m = 0;

  for(size_t i = n; i > 0; --i)
  {
    if (n % i == 0)
      m++;
  }

  return m == 2;
}

int main(void)
{
  int numbers[15], count = 0;

  for(size_t i = 0; i < 15; ++i)
  {
    printf("\nDigite o valor do %d elemento: ", i + 1);
    scanf("%d", &numbers[i]);

    if (isPrime(numbers[i]))
    {
      count++;
    }
  }

  int primes[count];

  for(size_t i = 0, j = 0; i < 15; ++i)
  {
    if (isPrime(numbers[i]))
    {
      primes[j++] = numbers[i];
    }
  }

  printf("\nVetor resultante: \n\n");

  for(size_t i = 0; i < count; ++i)
  {
    printf("%d\n", primes[i]);
  }

  printf("\n");

  return 0;
}