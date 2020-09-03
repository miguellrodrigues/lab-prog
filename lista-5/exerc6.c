#include "stdio.h"

int main()
{
    unsigned int a, b, run = 1;

    while (run == 1)
    {
        char cont[1];

        printf("\nDigite dois valores inteiros (x > 0): ");
        scanf("%d %d", &a, &b);

        while (b <= 0)
        {
            printf("\nValor do segundo digito invalido, digite novamente: ");
            scanf("%d", &b);
        }

        printf("\nResultado da divisao: %f", (float)a / b);

        printf("\nVoce deseja outro calculo? (S/N): ");
        scanf("%s", &cont);

        while (cont[0] != 'S' && cont[0] != 'N')
        {
            printf("\nVoce deseja outro calculo? (S/N): ");
            scanf("%s", &cont);
        }

        if (cont[0] != 'S')
            run = 0;
    }

    return 0;
}