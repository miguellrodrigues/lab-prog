/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    printf("\n");

    for (size_t i = 1000; i <= 1999; i++)
    {
        if (i % 11 == 5)
        {
            printf("%d, ", i);
        }
    }

    printf("\n");

    return 0;
}