#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int a[15];

    for (size_t i = 0; i < 15; i++)
    {
        a[i] = i * pow(2, i);
    }

    for (size_t i = 0; i < 15; i++)
    {
        printf("\n%d %d", a[i], i);
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

    printf("\nMaior elemtno: %d posicao: %d", higher, posHigher);
    printf("\nMenor elemento: %d posicao: %d", lower, posLower);

    return 0;
}