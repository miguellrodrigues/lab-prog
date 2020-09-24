#include "stdio.h"
#include "math.h"

int main(void)
{
    unsigned int n = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    float sum = 0, formula = ((n * (n + 1)) * (2 * n + 1)) / 6;

    for (unsigned int i = 1; i < n + 1; i++)
    {
        sum += pow(i, 2.0);
    }

    printf("\n");

    printf("Somatorio: %.3f\nFormula: %.3f\n", sum, formula);

    return 0;
}