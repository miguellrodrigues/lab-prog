#include "stdio.h"
#include "math.h"

int main(void)
{
    float lados[3], x, a = 0, b = 0, c = 0;

    printf("Digite 3 valores de lados: ");
    scanf("%f %f %f", &lados[0], &lados[1], &lados[2]);

    for (size_t i = 0; i <= 2; ++i)
    {
        for (size_t j = i + 1; j <= 2; ++j)
        {
            if (lados[i] < lados[j])
            {
                x = lados[i];

                lados[i] = lados[j];
                lados[j] = x;
            }
        }
    }

    a = lados[0];
    b = lados[1];
    c = lados[2];

    if (a > b + c)
    {
        printf("\nA B e C nao formam triangulo algum");
    }
    else
    {
        if (pow(a, 2.0) == pow(b, 2.0) + pow(c, 2.0))
        {
            printf("\nA B e C formam um triangulo retangulo");
        }

        if (pow(a, 2.0) > pow(b, 2.0) + pow(c, 2.0))
        {
            printf("\nA B e C formam um triangulo obtusangulo");
        }

        if (pow(a, 2.0) < pow(b, 2.0) + pow(c, 2.0))
        {
            printf("\nA B e C formam um triangulo acutangulo");
        }

        if (a == b && a == c)
        {
            printf("\nA B e C formam um triangulo equilatero");
        }

        if (a == b || b == c || a == c)
        {
            printf("\nA B e C formam um triangulo isoceles");
        }

        if (a != b && a != c && b != c)
        {
            printf("\nA B e C formam um triangulo escaleno");
        }
    }

    return 0;
}