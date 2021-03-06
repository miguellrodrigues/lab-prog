#include "stdio.h"

long double fatorial(float x)
{
    if (x == 0)
        return 1;

    return (x * (fatorial(x - 1)));
}

int main(void)
{
    unsigned int n = 0;
    float sum = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    n++;

    unsigned int j = 0;
    for (unsigned int i = 100; i > 100 - n; i--)
    {
        sum += i / fatorial(j++);
    }

    printf("Somatorio: %f", sum);

    return 0;
}