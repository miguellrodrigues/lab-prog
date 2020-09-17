#include "stdio.h"
#include "stdlib.h"

unsigned int bois[10][2];

int main()
{
    srand(time(NULL));

    for (size_t i = 0; i < 10; i++)
    {
        bois[i][0] = (rand() % 1000) + 1;
        bois[i][1] = (rand() % 300) + 150;
    }

    int troca = 0;
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = i + 1; j < 10; j++)
        {
            if (bois[i][1] > bois[j][1])
            {
                troca = bois[i][1];

                bois[i][1] = bois[j][1];
                bois[j][1] = troca;
            }
        }
    }

    printf("\nBoi mais gordo: Id - %d, Peso - %d", bois[9][0], bois[9][1]);
    printf("\nBoi mais magro: Id - %d, Peso - %d", bois[0][0], bois[0][1]);

    return 0;
}