#include <stdio.h>

int main(void)
{
    int a[5], b[5];

    for (size_t i = 0; i < 5; i++)
    {
        printf("\nDigite o valor do %d elemento de A: ", i + 1);
        scanf("%d", &a[i]);

        printf("Digite o valor do %d elemento de B: ", i + 1);
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d - %d = %d", a[i], b[4 - i], a[i] - b[4 - i]);
    }
    
    printf("\n");

    return 0;
}