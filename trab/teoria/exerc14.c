/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float sum = 0, j = 15;

    unsigned int prev = 1;

    unsigned int i = 0;

    while (i < 16384)
    {
        i += prev;

        sum += (i / pow(j--, 2.0));

        prev = i;
    }

    printf("\nSomatorio: %f\n", sum);

    return 0;
}