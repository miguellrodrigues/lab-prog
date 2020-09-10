/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    size_t n = 0, sum = 0;

    printf("\nDigite o valor de linhas: ");
    scanf("%d", &n);

    printf("\n");

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            printf("%d ", ++sum);
        }
        
        printf("\n");
    }
    
    return 0;
}