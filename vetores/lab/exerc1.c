#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que carregue dois vetores de dez posições cada um. Calcule e
    mostre um terceiro vetor que contenha os elementos dos dois vetores anteriores
    ordenados de maneira decrescente.
*/

int main(void)
{
    srand(time(NULL));

    int a[10], b[10], c[20];

    for (size_t i = 0; i < 10; i++)
    {
        a[i] = (rand() % 100) + 1;
        b[i] = (rand() % 100) + 1;
    }

    for (size_t i = 0; i < 10; i++)
    {
        c[i] = a[i];
        c[i + 10] = b[i];
    }

    int key;
    for (size_t i = 0; i < 20; ++i)
    {
        key = c[i];

        int j = (int)i - 1;

        while (j >= 0 && c[j] < key)
        {
            c[j + 1] = c[j];
            j--;
        }

        c[j + 1] = key;
    }

    for (int i = 0; i < 20; i++)
    {
        printf("\n%d", c[i]);
    }

    return 0;
}