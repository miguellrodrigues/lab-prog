#include "stdio.h"

int main(void)
{
    float base, altura, perimetro, area;

    printf("Digite o valor da base: ");
    scanf("%f", &base);

    printf("Digite o valor da altura: ");
    scanf("%f", &altura);

    perimetro = (altura * 2) + (base * 2);
    area = base * altura;

    printf("\nValor do perimetro: %.1f \nValor da area: %.1f", perimetro, area);

    return 0;
}