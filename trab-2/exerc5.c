/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

void multiplos(size_t lowerBound, size_t upperBound, size_t x)
{
    if (lowerBound > upperBound)
        return 0;

    for (size_t i = lowerBound; i <= upperBound; i++)
    {
        if (i % x == 0)
        {
            printf("%d ", i);
        }
    }
}

int main(void)
{
    size_t min, max, x;

    printf("\nDigite o valor minimo: ");
    scanf("%d", &min);

    printf("\nDigite o valor maximo: ");
    scanf("%d", &max);

    printf("\nDigite o valor de x: ");
    scanf("%d", &x);

    printf("\n");

    multiplos(min, max, x);

    return 0;
}