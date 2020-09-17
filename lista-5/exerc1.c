#include "stdio.h"

float higher(float a, float b, float c)
{
    return (a > b && a > c) ? a : (b > a && b > c) ? b : (c > a && c > b) ? c : -1;
}

int main(void)
{
    float a, b, c, maior;

    printf("Digite o valor de 3 numeros: ");
    scanf("%f %f %f", &a, &b, &c);

    maior = higher(a, b, c);

    if (maior != -1)
    {
        printf("O maior valor foi: %.3f", maior);
    }

    return 0;
}