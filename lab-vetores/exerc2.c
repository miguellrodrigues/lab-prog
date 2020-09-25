#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));

    unsigned int a[15];

    for (size_t i = 0; i < 15; i++)
    {
        a[i] = (rand() % 100) + 1;
    }

    for (size_t i = 0; i < 15; i++)
    {
        printf("\nPos: %d | Val: %d", i, a[i]);
    }

    unsigned int higher = a[0], lower = a[0], posHigher, posLower;

    for (size_t i = 0; i < 15; i++)
    {
        if (a[i] > higher)
        {
            higher = a[i];
            posHigher = i;
        }
        
        if (a[i] < lower)
        {
            lower = a[i];
            posLower = i;
        }
    }

    printf("\n\nMaior elemetno: %d posicao: %d", higher, posHigher);
    printf("\nMenor elemento: %d posicao: %d", lower, posLower);

    return 0;
}