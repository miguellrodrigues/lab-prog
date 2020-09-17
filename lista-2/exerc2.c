#include "stdio.h"

int main()
{
    float diarias, total;

    printf("Digite o numero de diarias: ");
    scanf("%f", &diarias);

    total = diarias < 15 ? 2.5 * diarias : diarias == 15 ? 1.5 * diarias : 0.5 * diarias;

    printf("\nTotal a ser pago: %.2f", total);
}