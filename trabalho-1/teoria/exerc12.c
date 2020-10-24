/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float numbers[9999], input, media = 0, dp = 0;

    unsigned int counter = 0;

    do {
        printf("\nDigite o valor do %d numero: ", (counter + 1));
        scanf("%f", &input);

        if (input == 0)
            break;

        numbers[counter] = input;

        counter++;
    }while (input != 0);

    for (unsigned int i = 1; i <= counter; i++)
    {
        media += numbers[i - 1];
    }

    media /= counter;

    for (unsigned int i = 0; i < counter; i++)
    {
        dp += pow((numbers[i] - media), 2.0) / counter;
    }

    dp = sqrt(dp);

    printf("\nMedia: %.3f", media);
    printf("\nDesvio padrao: %f\n", dp);

    return 0;
}