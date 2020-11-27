/*!
 * \mainpage Programação de computadores 1 - Trabalho Final
 *
 *
 *
 *
 * \section Introdução
 *
 * Este trabalho visa a implementação de um algoritimo
 * de gerenciamento de mesas e clientes de um restaurante
 * fictício
 *
 * \section Funcionamento
 *
 * Ao inializar, o programa faz a requisição de
 * um nome de arquivo binário para carregar os dados
 * criando o mesmo caso não seja possível encontrá-lo.
 *
 * \subsection Carregamento
 *
 * O Carregamento do arquivo para a memória volátil
 * é feito através de uma laço de repetição While,
 * utilizando a função fread da biblioteca stdio.h
 * para fazer a leitura e deslocamento em bytes no cursor
 * do arquivo, além da função feof para verificar se a leitura
 * chegou ao fim do arquivo.
 *
 * Em seguida os dados lidos são copiados para uma array
 * do tipo Reserve através da função memcpy
 *
 * \subsection Reserva
 *
 * Cada reserva é composta por um array de mesas (Table[]),
 * e cada mesa possui 4 ou menos clientes (Client), sendo
 * cada cliente composto por um nome, telefone e email.
 *
 * Cada reserva tem um ID (Identificador Único) do tipo inteiro como variável
 * de identificação.
 *
 * \subsection Mesas
 *
 * A mesa (Table) é a estrutura responsável por armazenar os clientes,
 * podendo ter 4 ou menos clientes ativos.
 * Os clientes são armazenadas em um array de clients (Client[])
 *
 * \subsection Cliente
 *
 * O cliente (Client) é a estrutura onde ficam armazenadas as informações dos clientes,
 * sendo elas: nome, telefone e-mail, todas salvas dentro de array`s de char
 *
 * */

/**
 * @file main.c
 * @author Miguel Lukas Rodrigues
 * @date 21 Nov 2020
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#ifndef MAX_CLIENTS_TABLE
#define MAX_CLIENTS_TABLE 4
#endif

#ifndef MAX_TABLES_PER_RESERVE
#define MAX_TABLES_PER_RESERVE 50
#endif

#ifndef MAX_RESERVES
#define MAX_RESERVES 50
#endif

#ifndef MAX_TABLES
#define MAX_TABLES 50
#endif

typedef unsigned int uint;

/**
 * @brief
 * @struct      client
 * @abstract    Contem informações sobre um cliente
 * @discussion  Todas as informações são armazenadas
 *              em array`s de char
 *
 * @field       name           Nome do cliente
 * @field       telephone      Telefone do cliente
 * @field       email          Email do cliente
 */
struct client
{

    char name[16];
    char telephone[10];
    char email[20];

} typedef Client;

/**
 * @brief
 * @struct      table
 * @abstract    Contem informações sobre uma mesa
 * @discussion  Uma mesa pode ter MAX_CLIENTS_TABLE ou menos clientes ativos
 *
 * @field       name           Nome do cliente
 * @field       telephone      Telefone do cliente
 * @field       email          Email do cliente
 */
struct table
{

    Client clients[MAX_CLIENTS_TABLE];

    uint activeClients;

    uint id;

} typedef Table;

/**
 * @brief
 * @struct      reserve
 * @abstract    Contem informações sobre uma reserva
 *
 * @field       tables         Mesas da reserva
 * @field       id             Id da reserva
 */
struct reserve
{

    Table tables[MAX_TABLES_PER_RESERVE];

    uint id;

} typedef Reserve;

/**
 * @brief
 * Verifica quantas mesas ativas tem uma reserva
 *
 * @param       reserve        Reserva que se deseja analisar
 * @return      Número que mesas em uma reserva
 */
uint activeTables(Reserve *reserve)
{
    uint x = 0;

    for (uint i = 0; i < 50; ++i)
    {
        if (reserve->tables[i].id)
        {
            x++;
        }
    }

    return x;
}

/**
 * @brief
 * Verifica se uma determinada mesa está reservada
 *
 * @param       reserves       Lista de reservas
 * @param       size           Tamanho de reserves
 * @param       id             Id da mesa a verificar
 * @return
 */
uint tableReserved(Reserve *reserves, uint size, uint id)
{
    if (id < 0 || id > 50)
    {
        return 0;
    }

    for (uint i = 0; i < size; ++i)
    {
        Reserve reserve = *(reserves + i);

        for (uint j = 0; j < activeTables(&reserve); ++j)
        {
            if (reserve.tables[j].id == id)
            {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * @brief
 * Retorna o número de clientes ativos em uma lista de reservas
 *
 * @param       reserves       Lista contento as reservas
 * @param       size           Tamanho da lista
 * @param       result         Ponteiro para a variável que irá armazenar
 *                             o número de clientes ativos da lista
 */
uint clients(Reserve *reserves, uint size)
{
    uint x = 0;

    for (uint i = 0; i < size; ++i)
    {
        for (uint j = 0; j < activeTables(&reserves[i]); ++j)
        {
            if (reserves[i].tables[j].id)
            {
                x += reserves[i].tables[j].activeClients;
            }
        }
    }

    return x;
}

int main()
{
    Reserve *reserves = calloc(MAX_RESERVES, sizeof(Reserve));

    char fileName[16];

    printf("\nDigite o nome do arquivo a ser carregado: ");
    setbuf(stdin, NULL);

    fgets(fileName, 16, stdin);

    fileName[strlen(fileName) - 1] = '\0';

    strcat(fileName, ".dat");

    FILE *file = fopen(fileName, "ab+");

    if (file == NULL)
    {
        printf("\nOcorreu um erro ao criar/abrir o arquivo");
        return 1;
    }

    Reserve *inputReserve = calloc(1, sizeof(Reserve));

    uint j = 0, reservedTables = 0;

    while (1)
    {
        fread(inputReserve, sizeof(Reserve), 1, file);

        if (feof(file))
            break;

        reservedTables += activeTables(inputReserve);

        memcpy(&reserves[j], inputReserve, sizeof(Reserve));

        j++;
    }

    free(inputReserve);

    uint reservesSize = j;

    fclose(file);

    uint running = 1;

    char option;

    while (running)
    {
        if (reservedTables == 50)
        {
            printf("\nTodas as mesas foram reservadas, finalizando programa\n");
            break;
        }

        do
        {
            printf("\nSelecione uma opcao: ");
            scanf(" %c", &option);

            option = (char)tolower(option);
        } while (option < 'a' || option > 'f');

        if (option == 'a')
        {
            uint reserveTables = 0;

            do
            {
                printf("\nDigite o numero de mesas que deseja reservar: ");
                scanf("%d", &reserveTables);
            } while ((reserveTables < 1 || reserveTables > 50) || (reservedTables + reserveTables) > 50);

            uint id = reservesSize == 0 ? 1 : (reserves + (reservesSize - 1))->id + 1;

            Reserve *reserve = calloc(1, sizeof(Reserve));

            reserve->id = id;

            for (uint i = 0; i < reserveTables; ++i)
            {
                uint tableId = 0;

                do
                {
                    printf("\nDigite o numero da mesa %d: ", i + 1);
                    scanf("%d", &tableId);
                } while (tableReserved(reserves, reservesSize, tableId));

                reserve->tables[i].id = tableId;

                int tableClients = 0;

                do
                {
                    printf("\nDigite o numero de clientes da %d mesa: ", i + 1);
                    scanf("%d", &tableClients);
                } while (tableClients < 0 || tableClients > 4);

                reserve->tables[i].activeClients = tableClients;

                char input[20];
                char name[16];

                for (uint k = 0; k < tableClients; ++k)
                {
                    printf("\nDigite o nome do %d cliente da %d mesa: ", k + 1, i + 1);

                    setbuf(stdin, NULL);
                    fgets(input, 16, stdin);

                    input[strlen(input) - 1] = '\0';

                    strcpy(name, input);

                    strcpy(reserve->tables[i].clients[k].name, input);

                    printf("\nDigite o telefone do(a) %s: ", name);

                    setbuf(stdin, NULL);
                    fgets(input, 10, stdin);

                    input[strlen(input) - 1] = '\0';

                    strcpy(reserve->tables[i].clients[k].telephone, input);

                    printf("\nDigite o email do(a) %s: ", name);

                    setbuf(stdin, NULL);
                    fgets(input, 20, stdin);

                    input[strlen(input) - 1] = '\0';

                    strcpy(reserve->tables[i].clients[k].email, input);
                }
            }

            reservedTables += reserveTables;

            memcpy(&reserves[reservesSize], reserve, sizeof(Reserve));

            free(reserve);

            reservesSize++;

            printf("\nReserva realizada com sucesso \n");
        }
        else if (option == 'b')
        {
            uint reserveId, found = 0;

            printf("\nDigite o id da reserva que voce deseja remover: ");
            scanf("%d", &reserveId);

            for (uint i = 0; i < reservesSize; ++i)
            {
                if ((reserves + i)->id == reserveId)
                {
                    for (uint k = i; k < reservesSize - 1; ++k)
                    {
                        reserves[k] = reserves[k + 1];
                    }

                    reservedTables -= activeTables(reserves + i);
                    reservesSize--;

                    printf("\nReserva removida com sucesso\n");

                    found = 1;
                }
            }

            if (!found)
            {
                printf("\nReserva nao encontrada\n");
            }
        }
        else if (option == 'c')
        {
            uint reserveId, found = 0;

            printf("\nDigite o id da reserva que voce procura: ");
            scanf("%d", &reserveId);

            for (uint i = 0; i < reservesSize; ++i)
            {
                if ((reserves + i)->id == reserveId)
                {
                    Reserve reserve = *(reserves + i);

                    uint reserveTables = activeTables(&reserve);

                    printf("\nNumero de mesas: %d\n", reserveTables);

                    for (uint k = 0; k < reserveTables; ++k)
                    {
                        printf("\nMesa %d\n", k + 1);

                        printf("\nClientes ativos: %d\n", reserve.tables[k].activeClients);

                        for (uint l = 0; l < reserve.tables[k].activeClients; ++l)
                        {
                            printf("\nNome cliente %d: %s", l + 1, reserve.tables[k].clients[l].name);
                            printf("\nTelefone cliente %d: %s", l + 1, reserve.tables[k].clients[l].telephone);
                            printf("\nEmail cliente %d: %s", l + 1, reserve.tables[k].clients[l].email);

                            printf("\n");
                        }

                        printf("\n");
                    }

                    found = 1;
                }
            }

            if (!found)
            {
                printf("\nReserva nao encontrada\n");
            }
        }
        else if (option == 'd')
        {
            if (reservesSize > 0)
            {
                for (uint i = 0; i < reservesSize; ++i)
                {
                    Reserve reserve = *(reserves + i);

                    uint reserveTables = activeTables(&reserve);

                    printf("\nId da Reserva: %d", reserve.id);
                    printf("\nNumero de mesas: %d", reserveTables);

                    for (uint k = 0; k < reserveTables; ++k)
                    {
                        printf("\n\nMesa %d\n", k + 1);

                        printf("Clientes ativos: %d\n", reserve.tables[k].activeClients);

                        for (uint l = 0; l < reserve.tables[k].activeClients; ++l)
                        {
                            printf("\nNome cliente %d: %s", l + 1, reserve.tables[k].clients[l].name);
                            printf("\nTelefone cliente %d: %s", l + 1, reserve.tables[k].clients[l].telephone);
                            printf("\nEmail cliente %d: %s", l + 1, reserve.tables[k].clients[l].email);

                            printf("\n");
                        }

                        printf("\n");
                    }
                }
            }
            else
            {
                printf("\nNao foram encontradas reservas\n");
            }
        }
        else if (option == 'e')
        {
            uint activeTables = reservedTables;

            printf("\nTaxa de ocupacao das mesas: %d de %d (%.2f por cento)\n", activeTables, 50,
                   (float)(activeTables * 10.0) / 5.0);

            uint activeClients = clients((Reserve *)reserves, reservesSize);

            float a = (float)((200.0 / activeClients) * (50.0 / activeTables));
            float b = (100.0F / a);

            printf("\nTaxa de ocupacao de pessoas: %d em %d mesas (%.2f por cento)\n", activeClients, activeTables, b);
        }
        else
        {
            running = 0;
        }
    }

    file = fopen(fileName, "wb");

    if (file == NULL)
    {
        printf("\nErro ao carregar o arquivo");
        return 1;
    }

    if (reservesSize > 0)
    {
        fwrite((Reserve *)reserves, sizeof(Reserve), reservesSize, file);
    }

    fclose(file);

    free((Reserve *)reserves);

    return 0;
}