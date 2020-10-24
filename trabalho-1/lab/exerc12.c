/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    unsigned int n = 0, sum = 0;

    printf("\nDigite o numero de linhas a serem impressas: ");
    scanf("%d", &n);

    printf("\n");

    for (unsigned int i = 1; i <= n; i++)
    {
        for (unsigned int j = 1; j <= i; j++)
        {
            printf("%d ", ++sum);
        }

        printf("\n");
    }

    return 0;
}