/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <stdbool.h>

int data[3][2];

int main(void)
{
    bool run = true;
    char message[3], yes[3] = {'s', 'i', 'm'};

    unsigned int golsAtletico = 0,
                 golsCruzeiro = 0,
                 golsAmerica  = 0,
                 result       = 0,
                 counter      = 0,
                 empates      = 0;
    for (;;)
    {
        printf("\nDigite o numero de gols marcado pelo Atletico: ");
        scanf("%d", &golsAtletico);

        printf("\nDigite o numero de gols marcado pelo Cruzeiro: ");
        scanf("%d", &golsCruzeiro);

        printf("\nDigite o numero de gols marcado pelo America: ");
        scanf("%d", &golsAmerica);

        data[0][1] += golsAtletico;
        data[1][1] += golsCruzeiro;
        data[2][1] += golsAmerica;

        result = (golsAtletico > golsCruzeiro && golsAtletico > golsAmerica)  ? 1 :
                 (golsCruzeiro > golsAtletico && golsCruzeiro > golsAmerica)  ? 2 :
                 (golsAmerica  > golsAtletico && golsAmerica  > golsCruzeiro) ? 3 : 0;

        switch (result)
        {
        case 1:
            printf("\nVitoria do Atletico!");
            data[0][0]++;
            break;

        case 2:
            printf("\nVitoria do Cruzeiro!");
            data[1][0]++;
            break;

        case 3:
            printf("\nVitoria do America!");
            data[2][0]++;
            break;

        default:
            printf("\nEmpate!");
            empates++;
            break;
        }

        printf("\n");

        printf("\nDeseja iniciar um novo duelo ? (sim ou nao) ");
        scanf("%s", &message);

        for (size_t i = 0; i < 3; i++)
        {
            if (message[i] != yes[i])
            {
                run = false;
            }
        }

        counter++;

        if (!run)
            break;
    }

    for (size_t i = 0; i < 100; i++)
    {
        printf("\n");
    }

    
    printf("\nQuantidade de jogos: %d", counter);
    printf("\n");
    printf("\nNumero de vitorias do Atletico: %d", data[0][0]);
    printf("\nQuantidade de gols do Atletico: %d", data[0][1]);
    printf("\n");
    printf("\nNumero de vitorias do Cruzeiro: %d", data[1][0]);
    printf("\nQuantidade de gols do Cruzeiro: %d", data[1][1]);
    printf("\n");
    printf("\nNumero de vitorias do America: %d", data[2][0]);
    printf("\nQuantidade de gols do America: %d", data[2][1]);
    printf("\n");
    printf("\nQuantidade de empates: %d", empates);
    printf("\nTime com maior numero de vitorias: %s", (data[0][1] > data[1][1] && data[0][1] > data[2][1]) ? "Atletico" :
                                                      (data[1][1] > data[0][1] && data[1][1] > data[2][1]) ? "Cruzeiro" :
                                                      (data[2][1] > data[0][1] && data[2][1] > data[1][1]) ? "America"  : "Nenhum");
    printf("\n");

    return 0;
}