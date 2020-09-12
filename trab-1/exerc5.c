/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int x = 0, y = 1, next = 0;

    for (size_t i = 0; i < 15; i++)
    {
        next = x + y;

        printf("\n%d", next);

        x = y;
        y = next;
    }

    return 0;
}