/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int valor;

    printf("\nDigite um valor em reais: ");
    scanf("%d", &valor);

    unsigned int notas[5] = {100, 50, 10, 5, 1};

    unsigned int qtd[5];

    for (unsigned int i = 0; i < 5; i++)
    {
        qtd[i] = (valor / notas[i]);
        valor -= (qtd[i] * notas[i]);
    }

    for (unsigned int i = 0; i < 5; i++)
    {
        printf("\nQuantida de notas de %d: %d", notas[i], qtd[i]);
    }

    printf("\n");

    return 0;
}