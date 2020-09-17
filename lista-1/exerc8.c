#include "stdio.h"

int main(void)
{
    float saldo;

    printf("Digite o valor do saldo: ");
    scanf("%f", &saldo);

    saldo += saldo * (1.0 / 100.0);

    printf("Saldo com reajuste: %.1f", saldo);

    return 0;
}