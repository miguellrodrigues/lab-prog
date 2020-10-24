/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float notas[3], media;

    for (size_t i = 0; i < 3; i++)
    {
        printf("Digite o valor da %d nota: ", (i + 1));
        scanf("%f", &notas[i]);

        while (notas[i] < 0)
        {
            printf("Valor invalido, digite novamente o valor da %d nota: ", (i + 1));
            scanf("%f", &notas[i]);
        }
    }

    char option;

    printf("\nQual media voce deseja calcular ? Aritimetica (A) | Ponderada (P) | Harmonica (H) ");
    scanf("\n%c", &option);

    while (option != 'A' && option != 'P' && option != 'H')
    {
        printf("\nOpcao invalida, digite uma opcao valida: Aritimetica (A) | Ponderada (P) | Harmonica (H) ");
        scanf("%s", &option);
    }

    switch (option)
    {
    case 'A':
        for (size_t i = 1; i <= 3; i++)
        {
            media += notas[i - 1];
        }

        media /= 3;

        break;

    case 'P':
        media = (notas[0] * 3) + (notas[1] * 3) + (notas[2] * 4);

        media /= 10;
        break;
    case 'H':
        for (size_t i = 1; i <= 3; i++)
        {
            media += 1 / notas[i - 1];
        }

        media = 3 / media;

        break;
    default:
        break;
    }

    printf("\nMedia: %.3f\n", media);

    return 0;
}