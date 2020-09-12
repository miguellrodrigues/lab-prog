/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    printf("\n");

    size_t x = 0;

    for (size_t i = 1000; i <= 1999; i++)
    {
        if (i % 11 == 5)
        {
            printf("%d, ", i);
            if (++x == 10)
            {
                printf("\n");
                x = 0;
            }
        }
    }

    printf("\n");

    return 0;
}