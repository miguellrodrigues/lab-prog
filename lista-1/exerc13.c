#include "stdio.h"

int main(void)
{
    float prestacao, valor, taxa, tempo;

    printf("Informe o valor da prestacao: ");
    scanf("%f", &valor);

    printf("Informe o valor da taxa: ");
    scanf("%f", &taxa);

    printf("Informe o tempo de atraso: ");
    scanf("%f", &tempo);

    prestacao = valor + (valor * (taxa / 100.0) * tempo);

    printf("\nValor da prestacao: %.2f", prestacao);

    return 0;
}