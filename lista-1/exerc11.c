#include "stdio.h"

int main(void)
{
    float base, altura, area;

    printf("Digite o valor da base: ");
    scanf("%f", &base);

    printf("Digite o valor da altura: ");
    scanf("%f", &altura);

    area = (base * altura) / 2.0;

    printf("\nValor da area: %.1f", area);

    return 0;
}