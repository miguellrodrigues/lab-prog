#include <stdio.h>

/*
    Faça um programa que leia um vetor de 15 posições de números inteiros e divida
    todos os seus elementos pelo maior valor do vetor. Mostre o vetor após os cálculos.
*/

#include <math.h>

int main(void)
{
    int a[15], higher = 0;

    for (size_t i = 0; i < 15; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);

        if (a[i] > higher)
        {
            higher = a[i];
        }
    }

    for (size_t i = 0; i < 15; i++)
    {
        a[i] /= higher;

        printf("\nPos: %d | Val: %d", i + 1, a[i]);
    }

    return 0;
}