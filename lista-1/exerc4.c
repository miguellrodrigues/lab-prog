#include "stdio.h"

int main(void)
{
    float a, b;

    printf("Digite o valor do primeiro numero: ");
    scanf("%f", &a);

    printf("Digite o valor do segundo numero: ");
    scanf("%f", &b);

    printf("\nSoma: %.f", a + b);

    return 0;
}