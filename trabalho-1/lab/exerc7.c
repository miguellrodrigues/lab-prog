/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int data[3][2];

char *getHigher()
{
    return (data[0][0] > data[1][0] && data[0][0] > data[2][0]) ? "Atletico" : 
           (data[1][0] > data[0][0] && data[1][0] > data[2][0]) ? "Cruzeiro" : 
           (data[2][0] > data[0][0] && data[2][0] > data[1][0]) ? "America"  : "Nenhum";
}

int main(void)
{
    unsigned int golsAtletico = 0,
                 golsCruzeiro = 0,
                 golsAmerica  = 0,
                 result       = 0,
                 counter      = 0,
                 empates      = 0,
                 opt          = 0,
                 exit         = 1;
    
    do {

        printf("\nInforme os times a se confrontarem: \n\n1 (Cruzeiro x Atletico)\n2 (Atletico x America)\n3 (Cruzeiro x America)\n\n");
        scanf("%d", &opt);

        while (opt != 1 && opt != 2 && opt != 3)
        {
            printf("\nInforme os times a se confrontarem: \n\n1 (Cruzeiro x Atletico)\n2 (Atletico x America)\n3 (Cruzeiro x America)\n\n");
            scanf("%d", &opt);
        }

        switch (opt)
        {
        case 1:
            printf("\nDigite o numero de gols marcado pelo Cruzeiro: ");
            scanf("%d", &golsCruzeiro);

            printf("\nDigite o numero de gols marcado pelo Atletico: ");
            scanf("%d", &golsAtletico);

            data[0][1] += golsAtletico;
            data[1][1] += golsCruzeiro;
            break;

        case 2:
            printf("\nDigite o numero de gols marcado pelo Atletico: ");
            scanf("%d", &golsAtletico);

            printf("\nDigite o numero de gols marcado pelo America: ");
            scanf("%d", &golsAmerica);

            data[0][1] += golsAtletico;
            data[2][1] += golsAmerica;
            break;

        case 3:
            printf("\nDigite o numero de gols marcado pelo Cruzeiro: ");
            scanf("%d", &golsCruzeiro);

            printf("\nDigite o numero de gols marcado pelo America: ");
            scanf("%d", &golsAmerica);

            data[1][1] += golsCruzeiro;
            data[2][1] += golsAmerica;
            break;

        default:
            break;
        }

        result = opt == 1 ? (golsCruzeiro > golsAtletico ? 2 : golsCruzeiro == golsAtletico ? 0 : 1) : 
                 opt == 2 ? (golsAmerica  > golsAtletico ? 3 : golsAtletico == golsAmerica  ? 0 : 1) : 
                 opt == 3 ? (golsAmerica  > golsCruzeiro ? 3 : golsCruzeiro == golsAmerica  ? 0 : 2) : 0;

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

        printf("\nDeseja iniciar um novo duelo ? 1 (sim) ou 0 (nao) ");
        scanf("%d", &exit);

        counter++;

    } while (exit);
    
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
    printf("\nTime com maior numero de vitorias: %s", getHigher());
    printf("\n");

    return 0;
}