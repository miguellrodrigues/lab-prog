#include <stdio.h>
#include <stdlib.h>

unsigned int poltronas[12][4] = {{0}};

void showMap()
{
    printf("LADO ESQUERDO                           LADO DIREITO\n");
    printf("------------------------               ----------------------\n");
    printf("JANELA         CORREDOR                 CORREDOR     JANELA\n");
    printf("------------------------               ----------------------\n");

    size_t x = 0;
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            x++;

            if (poltronas[i][j] == 0)
            {
                printf("%d.Livre", x);
            }
            else
            {
                printf("%d.Ocupado", x);
            }

            if (j == 1)
            {
                if (i < 3)
                {
                    if (i == 2)
                    {
                        if (poltronas[i][j] == 0)
                        {
                            printf("                 ");
                        }
                        else
                        {
                            printf("               ");
                        }
                    }
                    else
                    {
                        if (poltronas[i][j] == 0)
                        {
                            printf("                  ");
                        }
                        else
                        {
                            printf("                ");
                        }
                    }
                }
                else
                {
                    if (poltronas[i][j] == 0)
                    {
                        printf("                 ");
                    }
                    else
                    {
                        printf("               ");
                    }
                }
            }
            else
            {
                if (i < 3)
                {
                    if (i == 2 && x == 11)
                    {
                        if (poltronas[i][j] == 0)
                        {
                            printf("       ");
                        }
                        else
                        {
                            printf("     ");
                        }
                    }
                    else
                    {
                        if (poltronas[i][j] == 0)
                        {
                            printf("        ");
                        }
                        else
                        {
                            printf("      ");
                        }
                    }
                }
                else
                {
                    if (poltronas[i][j] == 0)
                    {
                        printf("       ");
                    }
                    else
                    {
                        printf("     ");
                    }
                }
            }
        }

        printf("\n");
    }
}

int main(void)
{
    unsigned int running = 1,
                 option = 0,
                 poltrona = 0,
                 empty = 48;

    printf("\n");

    while (running)
    {
        do
        {
            printf("\nSelecione uma opcao: \n");
            printf("\n1 - Vender passagem");
            printf("\n2 - Mostrar quantidade de lugares livres");
            printf("\n3 - Mostrar mapa de ocupacao do onibus");
            printf("\n4 - Encerrar\n\n");

            scanf("%d", &option);
        } while (option < 1 || option > 4);

        if (option == 4)
            break;

        system("cls");

        switch (option)
        {
        case 1:
            if (empty == 0)
            {
                printf("\nOnibus lotado !");
            }
            else
            {
                printf("\nDigite o numero da poltrona desejada: (1 a 48) ");
                scanf("%d", &poltrona);

                while (poltrona < 1 || poltrona > 48)
                {
                    printf("\nPoltrona invalida, digite um valor valido: ");
                    scanf("%d", &poltrona);
                }

                system("cls");

                unsigned int line = poltrona / 4;

                if (poltrona % 4 == 0)
                    line--;

                unsigned int x = (line * 4);

                unsigned int column = (poltrona - x) - 1;

                if (poltronas[line][column] == 0)
                {
                    printf("\nVenda efetivada !");
                    poltronas[line][column] = 1;

                    empty--;
                }
                else
                {
                    printf("\nPoltrona ocupada !");
                }
            }
            break;
        case 2:
            printf("\nQuantidade de lugares livres: %d", empty);
            break;
        case 3:
            showMap();
            break;
        default:
            break;
        }

        printf("\n");
    }

    return 0;
}