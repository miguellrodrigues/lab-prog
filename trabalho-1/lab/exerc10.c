/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int numbers[9999];

    int counter = 0,
        input = 0;

    printf("\n");

    do
    {
        printf("Digite o valor do %d numero: ", (counter + 1));
        scanf("%d", &input);

        if (input == 0)
            break;

        numbers[counter] = input;

        counter++;
    } while (input != 0);

    unsigned int pares = 0;

    float media = 0,
          mediaPares = 0;

    int sum = 0,
        higher = numbers[0],
        lower = numbers[0];

    for (unsigned int i = 0; i < counter; i++)
    {
        int num = numbers[i];

        sum += num;

        if (num % 2 == 0)
        {
            mediaPares += num;
            ++pares;
        }
    }

    media = (float)sum / counter;

    if (pares > 0)
    {
        mediaPares /= pares;
    }
    else
    {
        mediaPares = 0;
    }

    for (unsigned int i = 0; i < counter; i++)
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