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

    size_t prev = 1;

    size_t i = 0;

    while (i < 16384)
    {
        i = (i + prev);

        sum += (i / pow(j--, 2.0));

        prev = i;
    }

    printf("\nSomatorio: %f\n", sum);

    return 0;
}