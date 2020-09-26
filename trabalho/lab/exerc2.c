#include <stdio.h>

unsigned int poltronas[12][4] = {{0}};

unsigned int showMap()
{
    printf("LADO ESQUERDO                LADO DIREITO\n");
    printf("-------------------          -------------------\n");
    printf("JANELA     CORREDOR          CORREDOR     JANELA\n");
    printf("-------------------          -------------------\n");

    size_t c = 0, x = 0;
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (poltronas[i][j] == 0)
            {
                printf("%d.Livre", ++x);
            }
            else
            {
                printf("%d.Ocupado", ++x);
            }

            c++;

            if (c == 4)
            {
                printf("\n");
                c = 0;
            }
            else if (c == 2)
            {
                printf("              ");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

unsigned int empty()
{
    unsigned int x = 0;

    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (poltronas[i][j] == 0)
            {
                x++;
            }
        }
    }

    return x;
}

int main(void)
{
    unsigned int running = 1, option = 0;

    while (running)
    {
        do
        {
            printf("\nSelecione uma opcao: ");
            printf("\n1 - Vender passagem");
            printf("\n2 - Mostrar quantidade de lugares livres");
            printf("\n3 - Mostrar mapa de ocupacao do onibus"); 
            printf("\n4 - Encerrar");     
        } while (option < 1 || option > 4);

        
    }   

    return 0;
}