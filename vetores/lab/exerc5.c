#include <stdio.h>

/*
    Faça um programa que leia um vetor inteiro de 30 posições e crie um segundo vetor,
    substituindo os valores zeros por 1. Mostre os dois vetores
*/

int main(void)
{
    int a[30], b[30];

    for (size_t i = 0; i < 30; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    for (int i = 29; i > -1; i--)
    {
        int x = a[i];

        if (x == 0)
            x = 1;

        b[i] = x;
    }

    for (size_t i = 0; i < 30; i++)
    {
        printf("\nPos: %d | Val A: %d | Val B: %d", i + 1, a[i], b[i]);
    } 

    printf("\n");

    return 0;
}