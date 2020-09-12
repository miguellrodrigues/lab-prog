/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    unsigned int repuplicPopulation = 90000000, federalistPopulation = 200000000, counter = 0;

    while (repuplicPopulation < federalistPopulation)
    {
        repuplicPopulation += repuplicPopulation * 0.03;
        federalistPopulation += federalistPopulation * 0.015;

        counter++;
    }

    printf("\nAnos necessarios para que a populacao de Bruzundangas alcance ou ultrapasse a populacao de Milanos: %d\n", counter);

    return 0;
}