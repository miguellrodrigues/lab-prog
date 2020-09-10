/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <malloc.h>

int *multiplos(size_t lowerBound, size_t upperBound, size_t x)
{
    if (lowerBound > upperBound)
        return 0;

    int counter = 0;

    int *numbers = calloc(upperBound, sizeof(int));

    for (size_t i = lowerBound; i <= upperBound; i++)
    {
        if (i % x == 0)
        {
            numbers[counter] = i;
            counter++;
        }
    }

    return numbers;
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

    int *numbers = multiplos(min, max, x);

    for (size_t i = 0; i < max; i++)
    {
        if (numbers[i] != 0)
            printf("%d ", numbers[i]);
    }

    return 0;
}