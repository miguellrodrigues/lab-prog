#include "stdio.h"
#include "stdbool.h"

struct game_data
{
    unsigned int partidas;

    unsigned int scoreAtletico;
    unsigned int golsAtletico;

    unsigned int scoreCruzeiro;
    unsigned int golsCruzeiro;

    unsigned int empates;
};

int main(void)
{
    bool run = true;
    char message[3], yes[3] = {'s', 'i', 'm'};

    struct game_data data;

    data.empates = 0;
    data.partidas = 0;

    data.golsAtletico = 0;
    data.scoreAtletico = 0;

    data.golsCruzeiro = 0;
    data.scoreCruzeiro = 0;

    while (run)
    {
        data.partidas++;

        unsigned int golsAtletico = 0, golsCruzeiro = 0, result = 0;

        printf("\nDigite o numero de gols marcado pelo Atletico: ");
        scanf("%d", &golsAtletico);

        printf("\nDigite o numero de gols marcado pelo Cruzeiro: ");
        scanf("%d", &golsCruzeiro);

        data.golsAtletico += golsAtletico;
        data.golsCruzeiro += golsCruzeiro;

        result = golsAtletico > golsCruzeiro ? 1 : golsAtletico < golsCruzeiro ? 2 : 0;

        switch (result)
        {
        case 1:
            printf("\nVitoria do Atletico!");
            data.scoreAtletico++;
            break;

        case 2:
            printf("\nVitoria do Cruzeiro!");
            data.scoreCruzeiro++;
            break;

        default:
            printf("\nEmpate!");
            data.empates++;
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
    }

    for (size_t i = 0; i < 100; i++)
    {
        printf("\n");
    }

    printf("\nQuantidade de jogos: %d", data.partidas);
    printf("\n");
    printf("\nNumero de vitorias do Atletico: %d", data.scoreAtletico);
    printf("\nQuantidade de gols do Atletico: %d", data.golsAtletico);
    printf("\n");
    printf("\nNumero de vitorias do Cruzeiro: %d", data.scoreCruzeiro);
    printf("\nQuantidade de gols do Atletico: %d", data.golsCruzeiro);
    printf("\n");
    printf("\nQuantidade de empates: %d", data.empates);
    printf("\nTime com maior numero de vitorias: %s", data.scoreAtletico > data.scoreCruzeiro ? "Atletico" : data.scoreAtletico > data.scoreCruzeiro ? "Cruzeiro" : "Nenhum");
    printf("\n");

    return 0;
}