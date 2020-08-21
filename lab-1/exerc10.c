#include "stdio.h"

int main(void)
{
    float raio, perimetro, area;
    
    printf("Digite o valor do raio: ");
    scanf("%f", &raio);

    perimetro = 2 * 3.1415 * raio;
    area = 3.1415 * (raio * raio);

    printf("\nValor do perimetro: %.1f \nValor da area: %.1f", perimetro, area);

    return 0;
}