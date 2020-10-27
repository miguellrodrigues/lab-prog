#include <stdio.h>

int main(void)
{
    float m1[3][3], m2[3][3], result[3][3];

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("\nDigite o valor do elemento (%d, %d) da primeira matriz: ", i + 1, j + 1);
            scanf("%f", &m1[i][j]);

            printf("\nDigite o valor do elemento (%d, %d) da segunda matriz: ", i + 1, j + 1);
            scanf("%f", &m2[i][j]);
        }
    }

    float aux = 0;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            result[i][j] = 0;

            for (size_t k = 0; k < 3; k++)
            {
                aux += m1[i][k] * m2[k][j];
            }

            result[i][j] = aux;
            aux = 0;
        }
    }

    printf("\nMatriz resultante: \n");

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("\nR (%d, %d) %.3f ", i + 1, j + 1, result[i][j]);
        }
    }

    printf("\n");

    return 0;
}