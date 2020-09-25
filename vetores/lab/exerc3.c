#include <stdio.h>

/*
    Faça um programa que leia um vetor de 50 posições de números inteiros e mostre
    somente os números positivos.
*/

int main(void)
{
    int a[50];

    for (size_t i = 0; i < 50; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (size_t i = 0; i < 50; i++)
    {
        if (a[i] > 0)
        {
            printf("\nPos: %d | Val: %d", i + 1, a[i]);
        }
    }

    printf("\n");

    return 0;
}