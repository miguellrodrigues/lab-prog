#include "stdio.h"

void sort(int size, int op, float list[])
{
    float change = 0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            change = list[i];

            if (op == 1 && list[i] > list[j])
            {

                list[i] = list[j];
                list[j] = change;
            }
            else if (op == 2 && list[i] < list[j])
            {

                list[i] = list[j];
                list[j] = change;
            }
        }
    }
}

int main(void)
{
    int i;
    float real[3], a, higher = 0;

    printf("Digite um valor inteiro de 1 a 3: ");
    scanf("%d", &i);

    printf("Digite o valor de a, b e c: ");
    scanf("%f %f %f", &real[0], &real[1], &real[2]);

    if (i == 1)
    {
        sort(3, 1, real);
        printf("\n%f, %f, %f", real[0], real[1], real[2]);
    }
    else if (i == 2)
    {
        sort(3, 2, real);
        printf("\n%f, %f, %f", real[0], real[1], real[2]);
    }
    else if (i == 3)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (real[i] > higher)
                higher = real[i];
        }

        printf("O maior valor e`: %f", higher);
    }

    return 0;
}