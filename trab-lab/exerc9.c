/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    unsigned int lowerBound, upperBound, sum = 0;

    printf("\nDigite o valor minimo do intervalo: ");
    scanf("%d", &lowerBound);

    printf("Digite o valor maximo do intervalo: ");
    scanf("%d", &upperBound);

    if (lowerBound > upperBound)
    {
        printf("\nIntervalo de valores invalido.");
        return -1;
    }

    for (size_t i = lowerBound; i <= upperBound; i++)
    {
        if (i % 2 != 0)
            sum += i;
    }

    printf("\nSomatorio dos valores impares entre: %d e %d -> %d\n", lowerBound, upperBound, sum);

    return 0;
}