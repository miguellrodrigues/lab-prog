#include "stdio.h"

int main()
{
    unsigned int a, b;
    char cont;

    while (1)
    {
        printf("\nDigite dois valores inteiros (x != 0): ");
        scanf("%d %d", &a, &b);

        while (b == 0)
        {
            printf("\nValor do segundo digito invalido, digite novamente: ");
            scanf("%d", &b);
        }

        printf("\nResultado da divisao: %f", (float)a / b);

        printf("\nVoce deseja outro calculo? (S/N): ");
        scanf("%s", &cont);

        while (cont != 'S' && cont != 'N')
        {
            printf("\nVoce deseja outro calculo? (S/N): ");
            scanf("\n%c", &cont);
        }

        if (cont != 'S')
            break;
    }

    return 0;
}