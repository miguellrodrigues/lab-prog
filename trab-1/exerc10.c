/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int *numbers = calloc(100, sizeof(int)), input = 0;

    int counter = 0;

    printf("\n");

    while (1)
    {
        printf("Digite o valor do %d numero: ", (counter + 1));
        scanf("%d", &input);

        if (input == 0)
            break;

        numbers[counter] = input;

        counter++;
    }

    size_t pares      = 0;

    float  media      = 0,
           mediaPares = 0;

    int sum        = 0,
        higher     = numbers[0],
        lower      = numbers[0];

    for (size_t i = 0; i < counter; i++)
    {
        int num = numbers[i];

        sum += num;

        if (num % 2 == 0) {
           mediaPares += num;
           ++pares;
        }
    }
    
    media = (float) sum / counter;
    mediaPares /= pares;

    for (size_t i = 0; i < counter; i++)
    {
        if (numbers[i] > higher)
            higher = numbers[i];
        
        if (numbers[i] < lower) 
            lower = numbers[i];
    }

    printf("\nSoma dos numeros digitados: %d", sum);
    printf("\nQuantidade de numeros digitados: %d", counter);
    printf("\nMedia dos numeros digitados: %.3f", media);
    printf("\nO maior numero digitado: %d", higher);
    printf("\nO menor numero digitado: %d", lower);
    printf("\nMedia dos numeros pares: %.3f\n", mediaPares);

    return 0;
}