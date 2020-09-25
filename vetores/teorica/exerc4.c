#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n;

    printf("\nDigite a dimensao do array: ");
    scanf("%d", &n);

    float a[n];

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%f", &a[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        double x = a[i];

        if (x > 0)
        {
            float fx = (2 * x) - cos(x);

            printf("\nValor: %.3f | V. Funcao: %.3f", x, fx);
        }
    }

    printf("\n");

    return 0;
}