#include "stdio.h"

int main(void)
{
    float repuplicPopulation = 90000000;
    float federalistPopulation = 200000000;

    unsigned int counter = 0;

    for (float a = repuplicPopulation, b = federalistPopulation; a < b; a += a * 0.03, b += b * 0.015)
    {
        counter++;
    }

    printf("Anos necessarios para que a populacao de Bruzundangas alcance ou ultrapasse a populacao de Milanos: %d", counter);

    return 0;
}