/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    for (size_t i = 0; i < 20; i++)
    {
        if (i % 2 != 0)
        {
            printf("\n%d", i);
        }
    }

    printf("\n");

    return 0;
}