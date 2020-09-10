/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

size_t impares(size_t lowerBound, size_t upperBound)
{
    if (lowerBound > upperBound)
        return lowerBound % 2 == 0 ? 0 : 1;

    size_t counter = 0;

    for (size_t i = lowerBound; i <= upperBound; i++)
    {
        if (i % 2 != 0)
            counter++;
    }

    return counter;
}

int main(void)
{
    size_t min, max;

    printf("\nDigite o valor minimo: ");
    scanf("%d", &min);

    printf("\nDigite o valor maximo: ");
    scanf("%d", &max);

    printf("\nQuantidade de numeros impares entre: %d a %d: %d", min, max, impares(min, max));

    return 0;
}