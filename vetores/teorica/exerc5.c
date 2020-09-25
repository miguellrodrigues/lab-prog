#include <stdio.h>

int main(void)
{
    unsigned int n;

    printf("\nDigite a dimensao do array: ");
    scanf("%d", &n);

    printf("\n");

    float a[n], media = 0;

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%f", &a[i]);

        media += a[i];
    }

    media /= n;

    unsigned int minor = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < media)
        {
            minor++;

            printf("\nPos: %d | Val: %.3f", i, a[i]);
        }
    }

    printf("\n");

    if (minor == 0)
    {
        printf("\nNao foram encontrados elementos menores que a media");
    }
    else
    {
        printf("\nQuantidade de elementos menores que a media: %d", minor);
    }

    printf("\n");

    return 0;
}