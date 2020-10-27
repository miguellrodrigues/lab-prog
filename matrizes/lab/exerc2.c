#include <stdio.h>

int main(void)
{
    int a[20][10], sumColumns[10];

    for (size_t i = 0; i < 20; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            printf("\nDigite o valor de A(%d, %d) ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    for (size_t j = 0; j < 10; ++j)
    {
        sumColumns[j] = 0;

        for (size_t i = 0; i < 20; ++i)
        {
            sumColumns[j] += a[i][j];
        }
    }

    for (size_t i = 0; i < 20; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            a[i][j] *= sumColumns[j];
        }
    }

    printf("\nMatriz resultante: \n");

    for (size_t i = 0; i < 20; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            printf("\nA(%d, %d) -> %d", i + 1, j + 1, a[i][j]);
        }
    }

    printf("\n");

    return 0;
}