/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

void multiplos(unsigned int lowerBound, unsigned int upperBound, unsigned int x)
{
    if (lowerBound > upperBound)
        printf("%d", lowerBound % x == 0 ? lowerBound : 0);

    for (unsigned int i = lowerBound; i <= upperBound; i++)
    {
        if (i % x == 0)
        {
            printf("%d ", i);
        }
    }
}

int main(void)
{
    unsigned int min, max, x;

    printf("\nDigite o valor minimo: ");
    scanf("%d", &min);

    printf("Digite o valor maximo: ");
    scanf("%d", &max);

    printf("\nDigite o valor de x: ");
    scanf("%d", &x);

    printf("\nMultiplos de %d entre %d e %d -> \n\n", x, min, max);

    multiplos(min, max, x);

    printf("\n\n");

    return 0;
}