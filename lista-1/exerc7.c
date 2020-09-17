#include "stdio.h"

int main(void) 
{
    float number, media;

    printf("\n");

    for (size_t i = 0; i < 4; i++)
    {
        printf("Digite o %d valor: ", i + 1);
        scanf("%f", &number);

        float weight = i + 1;

        media += number * weight;
    }

    media /= 10.0;

    printf("\nMedia %.2f", media);

    return 0;
}