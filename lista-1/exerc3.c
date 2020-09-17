#include "stdio.h"

int main(void)
{
    float number;

    printf("Digite um numero: ");
    scanf("%f", &number);

    printf("Antecessor %.1f\n", number - 1);
    printf("Sucessor %.1f", number + 1);

    return 0;
}