#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int data[5][4];

    for (size_t i = 0; i < 5; i++)
    {
        size_t x = i + 1;

        printf("\nDigite o numero de matricula do %d aluno: ", x);
        scanf("%d", &data[i][0]);

        printf("\nDigite a media das provas do %d aluno: ", x);
        scanf("%d", &data[i][1]);

        printf("\nDigite a media dos trabalhos do %d aluno: ", x);
        scanf("%d", &data[i][2]);

        data[i][3] = data[i][1] + data[i][2];
    }

    int higher = data[0][3], matricula = data[0][0];

    for (size_t i = 0; i < 5; i++)
    {
        if (data[i][3] > higher)
        {
            higher = data[i][3];
            matricula = data[i][0];
        }
    }
    
    printf("\nMaior nota final: Matricula: %d | Nota: %d\n", matricula, higher);

    for (size_t i = 0; i < 5; ++i)
    {
        if (data[i][3] == higher && data[i][0] != matricula)
        {
            printf("\nMatricula: %d | Nota: %d", data[i][0], data[i][3]);
        }
    }

    float media = 0;

    for (size_t i = 0; i < 5; ++i)
    {
        media += (int)data[i][3];
    }

    media /= 5;

    printf("\n\nMedia aritimetica das notas finais: %.3f\n", media);

    return 0;
}
