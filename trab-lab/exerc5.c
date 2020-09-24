/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int x = 0, y = 1, next = 0;

    for (unsigned int i = 0; i < 15; i++)
    {
        next = x + y;

        printf("\n%d", next);

        x = y;
        y = next;
    }

    printf("\n");

    return 0;
}