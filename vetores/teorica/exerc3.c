#include <stdio.h>

int main(void)
{
    int a[15], higher = 0;

    for (size_t i = 0; i < 15; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);

        if (a[i] > higher)
        {
            higher = a[i];
        }
    }

    for (size_t i = 0; i < 15; i++)
    {
        /*float x = (float) a[i] / higher;   //TODO: Nao ficou claro se era pra 
        printf("\nPos: %d | Val: %d", i, x);         fazer assim ou com divisao inteira
        */

        a[i] /= higher;

        printf("\nPos: %d | Val: %d", i, a[i]);
    }

    return 0;
}