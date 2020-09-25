#include <stdio.h>

int main(void)
{
    unsigned int n;

    printf("Digite a dimensao do vetor (x > 2): ");
    scanf("%d", &n);

    while (n < 2)
    {
        printf("Digite a dimensao do vetor (x > 2): ");
        scanf("%d", &n);
    }
    
    int a[n];

    a[0] = 0;
    a[1] = 1;

    for (size_t i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("\nPos: %d | Val: %lu", i, a[i]);
    }
    
    return 0;
}