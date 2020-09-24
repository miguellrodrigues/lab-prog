/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    for (unsigned int i = 0; i < 200; i++)
    {
        if (i % 4 == 0)
        {
            printf("\n%d", i);
        }
    }

    printf("\n");

    return 0;
}