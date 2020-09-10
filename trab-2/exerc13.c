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

    double notas[5] = {100, 50, 10, 5, 1};

    int qtd[5];

    for (size_t i = 0; i < 5; i++)
    {
        qtd[i] = (valor / notas[i]);
        valor -= (qtd[i] * notas[i]);
    }

    printf("\nQuantida de notas de 100: %d", qtd[0]);
    printf("\nQuantida de notas de 50: %d", qtd[1]);
    printf("\nQuantida de notas de 10: %d", qtd[2]);
    printf("\nQuantida de notas de 5: %d", qtd[3]);
    printf("\nQuantida de notas de 1: %d\n", qtd[4]);

    return 0;
}