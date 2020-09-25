/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    unsigned int alunos = 0;

    printf("\nDigite o numero de alunos: ");
    scanf("%d", &alunos);

    if (alunos <= 0)
    {
        printf("\nNumero de alunos invalido");
        return -1;
    }

    float input, media = 0;

    for (unsigned int i = 0; i < alunos; i++)
    {
        printf("\nDigite a nota do %d aluno: ", i + 1);

        scanf("%f", &input);

        while (input < 0)
        {
            printf("\nNota invalida, digite novamente a %d nota do aluno: ", i + 1);
            scanf("%f", &input);
        }

        media += input;
    }

    media /= alunos;

    printf("\nMedia das notas: %.3f\n", media);

    return 0;
}