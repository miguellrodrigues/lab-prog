#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    char feedback [8];

    int students [12];
    char answers [12][8];
    
    int score    [12][1];

    int approved = 0;

    printf("\n");

    for (size_t i = 0; i < 8; i++)
    {
        printf("Digite o gabarito da questao %d: ", i + 1);
        scanf("\n%c", &feedback[i]);
    }
    
    system("cls");

    for (size_t i = 0; i < 12; i++)
    {
        printf("\nDigite o id do estudante %d: ", i + 1);
        scanf("%d", &students[i]);

        score[i][0] = 0;

        printf("\n");

        for (size_t j = 0; j < 8; j++)
        {    
            printf("Digite a %d resposta do estudante %d: ", j + 1, i + 1);
            scanf("\n%c", &answers[i][j]);

            char answer = answers[i][j];

            if (answer == feedback[j])
            {
                if (++score[i][0] == 6)
                {
                    approved++;
                }
            }
        }

        system("cls");
    }
    
    for (size_t i = 0; i < 12; i++)
    {
        printf("\nMatricula: %d | Nota final: %d", students[i], score[i][0]);
    }
    
    printf("\n\nTaxa de aprovacao: %.3f\n", (float) approved / 12);
    
    return 0;
}