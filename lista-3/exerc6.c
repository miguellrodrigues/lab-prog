#include "stdio.h"
#include "math.h"

int main(void)
{
    float lados[3], a;

    printf("Digite 3 valores de lados: ");
    scanf("%f %f %f", &lados[0], &lados[1], &lados[2]);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            if (lados[i] < lados[j])
            {
                a = lados[i];

                lados[i] = lados[j];
                lados[j] = a;
            }
        }
    }

    if (lados[0] > lados[1] + lados[2])
    {
        printf("\nA B e C nao formam triangulo algum");
    }
    if (pow(lados[0], 2.0) == pow(lados[1], 2.0) + pow(lados[2], 2.0))
    {
        printf("\nA B e C formam um triangulo retangulo");
    }
    if (pow(lados[0], 2.0) > pow(lados[1], 2.0) + pow(lados[2], 2.0))
    {
        printf("\nA B e C formam um triangulo obtusangulo");
    }
    if (pow(lados[0], 2.0) < pow(lados[1], 2.0) + pow(lados[2], 2.0))
    {
        printf("\nA B e C formam um triangulo acutangulo");
    }
    if (lados[0] == lados[1] && lados[0] == lados[2])
    {
        printf("\nA B e C formam um triangulo equilatero");
    }
    if (lados[0] == lados[1] || lados[1] == lados[2] || lados[0] == lados[2])
    {
        printf("\nA B e C formam um triangulo isoceles");
    }
    if (lados[0] != lados[1] && lados[0] != lados[2] && lados[1] != lados[2])
    {
        printf("\nA B e C formam um triangulo escaleno");
    }

    return 0;
}