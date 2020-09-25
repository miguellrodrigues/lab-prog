#include <stdio.h>

int main(void)
{
    int a[10], b[10];

    for (size_t i = 0; i < 10; i++)
    {
        printf("\nDigite o valor do %d elemento: ", i + 1);
        scanf("%d", &a[i]);
    }

    size_t count = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if (a[i] != 0 && a[i] > 0) {
            b[count++] = a[i];
        }
    }

    for (size_t i = 0; i < count; i++)
    {
        printf("\nPos: %d | Val: %d", i, b[i]);
    }
    
    printf("\n");

    return 0;
}