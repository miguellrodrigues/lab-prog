#include "stdio.h"
#include "math.h"

int main(void)
{
    unsigned int n = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    float sum = 0, formula = ((n * (n + 1)) * (2 * n + 1)) / 6;
    
    for (size_t i = 1; i < n + 1; i++) {
        sum += pow(i, 2.0);
    }

    printf("Somatorio: %.3f, Formula: %.3f", sum, formula);

    return 0;
}