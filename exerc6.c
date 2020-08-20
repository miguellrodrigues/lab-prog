#include "stdio.h"

int main(void)
{
    float numbers[2];

    printf("Digite o valor do primeiro numero: ");
    scanf("%f", &numbers[0]);

    printf("Digite o valor do segundo numero: ");
    scanf("%f", &numbers[1]);

    for (size_t i = 0; i < sizeof(numbers) / sizeof(float); i++)
    {
        float dividendo = numbers[i], divisor = i == 0 ? numbers[i + 1] : numbers[i - 1];

        printf("\nDividendo %.f", dividendo);

        printf("\nDivisor %.f", divisor);

        printf("\nQuociente %.1f", (dividendo / divisor));

        printf("\nResto %d", (int) dividendo % (int) divisor);

        printf("\n");
    }

    return 0;
}