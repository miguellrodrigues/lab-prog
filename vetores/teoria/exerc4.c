#include <stdio.h>
#include <math.h>

/*
    Escrever um programa que leia a dimensão e os elementos de um vetor, um de cada
    vez. O programa determina quantos elementos são positivos, nulos e negativos, e
    imprime essas informações. Para os elementos positivos, é calculado o valor da
    função f(x) = 2x – cos(x) para esses elementos. Deve ser impresso o valor do elemento
    positivo e o valor da função.
*/

int main(void)
{
    unsigned int n, nl = 0, p = 0, ng = 0;

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
        float x = a[i];

        if (x > 0)
        {
            float fx = (2 * x) - cos(x);

            printf("\nValor: %.3f | V. Funcao: %.3f", x, fx);

            p++;
        }
        else if (x < 0)
        {
            ng++;
        }
        else
        {
            nl++;
        }
    }

    printf("\n\nQuantidade de elementos positivos: %d", p);
    printf("\nQuantidade de elementos negativos: %d", ng);
    printf("\nQuantidade de elementos nulos: %d", nl);

    printf("\n");

    return 0;
}