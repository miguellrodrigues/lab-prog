#include <stdio.h>

int checkArrayEqualities(int *array, int size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] != array[i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{

    size_t m, n;

    printf("\nDigite o numero de linhas: ");
    scanf("%d", &m);

    printf("\nDigite o numero de colunas: ");
    scanf("%d", &n);

    if (m != n)
    {
        printf("\nNumero de linhas difere do numero de colunas");
        return;
    }

    int a[m][n];

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("\nDigite o valor do elemento: A(%d %d) ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    int sumDp = 0, sumDs = 0, sumLines = 0;

    for (size_t i = 0; i < m; i++)
    {
        sumDp += a[i][i];
    }

    for (size_t i = 0; i < m; i++)
    {
        sumDs += a[i][m - i - 1];
    }

    int sumLinesArray[m];

    for (size_t i = 0; i < m; i++)
    {
        sumLinesArray[i] = 0;

        for (size_t j = 0; j < n; j++)
        {
            sumLinesArray[i] += a[i][j];
        }
    }

    int sumColumnsArray[n];

    for (size_t i = 0; i < m; i++)
    {
        sumColumnsArray[i] = 0;

        for (size_t j = 0; j < n; j++)
        {
            sumColumnsArray[i] += a[i][j];
        }
    }

    int equalLines = checkArrayEqualities(sumLinesArray, m);
    int equalColumns = checkArrayEqualities(sumColumnsArray, n);

    if (equalLines && equalColumns && (sumDs == sumDp) && (sumDs == sumLinesArray[0]))
    {
        printf("\n\nA matriz A(%d, %d) e um quadrado magico\n", m, n);
    }
    else
    {
        printf("\n\nA matriz A(%d, %d) nao e um quadrado magico\n", m, n);
    }

    return 0;
}