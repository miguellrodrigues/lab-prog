/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int numbers[9999];

    int num = 0, counter = 0;
    do {
        printf("\nDigite o valor do %d numero: ", counter + 1);
        scanf("%d", &num);

        numbers[counter] = num;
        counter++;
    } while (num >= 0);

    int higher = 0, pos = 0;
    for (unsigned int i = 0; i < counter; i++)
    {
        if (numbers[i] > higher)
        {
            higher = numbers[i];
            pos = i;
        }
    }

    printf("\nO maior numero digitado foi: %d Na posicao: %d\n", higher, ++pos);

    return 0;
}
