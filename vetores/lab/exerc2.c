#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que carregue um vetor com 15 posições, calcule e mostre:
    
    a. o maior elemento do vetor e em que posição esse elemento se encontra:
    b. o menor elemento do vetor e em que posição esse elemento se encontra.
*/

int main(void)
{
    srand(time(NULL));

    unsigned int a[15];

    for (size_t i = 0; i < 15; i++)
    {
        a[i] = (rand() % 100) + 1;
    }

    for (size_t i = 0; i < 15; i++)
    {
        printf("\nPos: %d | Val: %d", i + 1, a[i]);
    }

    unsigned int higher = a[0], lower = a[0], posHigher = 0, posLower = 0;

    for (size_t i = 0; i < 15; i++)
    {
        if (a[i] > higher)
        {
            higher = a[i];
            posHigher = i;
        }
        
        if (a[i] < lower)
        {
            lower = a[i];
            posLower = i;
        }
    }

    printf("\n\nMaior elemento: %d posicao: %d", higher, ++posHigher);
    printf("\nMenor elemento: %d posicao: %d\n", lower, ++posLower);

    return 0;
}