#include "stdio.h"

int main(void) 
{
    float numbers[4], media;

    printf("\n");

    for (size_t i = 0; i < sizeof(numbers) / sizeof(float); i++)
    {
        printf("Digite o %d valor: ", i + 1);
        scanf("%f", &numbers[i]);

        float weight = i + 1;

        media += numbers[i] * weight;
    }

    media /= 10.0;

    printf("\nMedia %.2f", media);

    return 0;
}