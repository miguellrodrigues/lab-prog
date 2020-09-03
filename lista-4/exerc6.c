#include "stdio.h"

int main(void)
{
    float repuplicPopulation = 90000000;
    float federalistPopulation = 200000000;

    unsigned int counter = 0;
    while (repuplicPopulation < federalistPopulation) {
        repuplicPopulation += repuplicPopulation * 0.03;

        federalistPopulation += federalistPopulation * 0.015;

        counter++;
    }

    printf("Anos necessarios para que a populacao de Bruzundangas alcance ou ultrapasse a populacao de Milanos: %d", counter);

    return 0;
}