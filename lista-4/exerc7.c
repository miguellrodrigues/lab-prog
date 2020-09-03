#include "stdio.h"

float fatorial(float x)
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

    size_t j = 0;
    for (size_t i = 100; i > 100 - n; i--) {
        sum += i / fatorial(j);
        j++;
    }

    printf("Somatorio: %.3f", sum);

    return 0; 
}