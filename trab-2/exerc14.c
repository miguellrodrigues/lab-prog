/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    float sum = 0, j = 225;

    size_t decrement = 29, prev = 1;

    size_t i = 0;

    while (i < 16384)
    {
        i = (i + prev);

        sum += (i / j);
        
        prev = i;

        j -= decrement;
        decrement -= 2;
    }

    printf("\nSomatorio: %f", sum);

    return 0;
}