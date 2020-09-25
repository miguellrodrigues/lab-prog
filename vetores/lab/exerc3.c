#include <stdio.h>

int main(void)
{
    int a[50];

    for (size_t i = 0; i < 10; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (size_t i = 0; i < 10; i++)
    {
        if (a[i] > 0)
        {
            printf("\nPos: %d | Val: %d", i, a[i]);
        }
    }

    return 0;
}