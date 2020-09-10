/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    int alunos = 0;

    printf("\nDigite o numero de alunos: ");
    scanf("%d", &alunos);

    if (alunos <= 0)
    {
        printf("\nNumero de alunos invalido");
        return -1;
    }

    float notas[alunos], media = 0;

    for (size_t i = 0; i < alunos; i++)
    {
        printf("\nDigite a nota do %d aluno: ", i + 1);

        scanf("%f", &notas[i]);
    }

    for (size_t j = 0; j < alunos; j++)
    {
        media += notas[j];
    }

    media /= alunos;

    printf("\nMedia das notas: %.3f", media);

    return 0;
}