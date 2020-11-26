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

/*! @include stdio.h Inclusão da bibliteca IO */
#include <stdio.h>

/*! @include string.h Inclusão da biblioteca de strings */
#include <string.h>

/*! @include string.h Inclusão da biblioteca de alocação de memória */
#include <malloc.h>

/*! @def Máximo de clientes por mesa */
#ifndef MAX_CLIENTS_TABLE
#define MAX_CLIENTS_TABLE 4
#endif

/*! @def Máximo de mesas por reserva */
#ifndef MAX_TABLES_PER_RESERVE
#define MAX_TABLES_PER_RESERVE 50
#endif

/*! @def Máximo de reservas */
#ifndef MAX_RESERVES
#define MAX_RESERVES 50
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
 * @discussion  Uma mesa pode ter @see MAX_CLIENTS_TABLE ou menos clientes ativos
 *
 * @field       name           Nome do cliente
 * @field       telephone      Telefone do cliente
 * @field       email          Email do cliente
 */
struct table
{

  Client clients[MAX_CLIENTS_TABLE];

  uint activeClients;

  uint reserveId;

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
 * Retorna o número de mesas em uma reserva
 *
 * @param       reserve        Reserva que se deseja analisar
 * @return      Número que mesas em uma reserva
 */
uint activeTables(Reserve *reserve)
{
  uint x = 0;

  for (uint i = 0; i < 50; ++i)
  {
    if (reserve->tables[i].reserveId)
    {
      x++;
    }
  }

  return x;
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
void clients(Reserve *reserves, uint size, uint *result)
{
  uint x = 0;

  for (uint i = 0; i < size; ++i)
  {
    for (uint j = 0; j < activeTables(&reserves[i]); ++j)
    {
      if (reserves[i].tables[j].reserveId)
      {
        x += reserves[i].tables[j].activeClients;
      }
    }
  }

  *result = x;
}

int main()
{
  /*! Declaração do array de reservas */
  Reserve *reserves = calloc(MAX_RESERVES, sizeof(Reserve));

  /*! Inicio da leitura dos dados do arquivo para a memória */

  /*! Leitura do nome do arquivo */

  char fileName[16];

  printf("\nDigite o nome do arquivo a ser carregado: ");
  setbuf(stdin, NULL);

  fgets(fileName, 16, stdin);

  fileName[strlen(fileName) - 1] = '\0';

  strcat(fileName, ".dat");

  /*! Fim leitura do nome do arquivo */

  FILE *file = fopen(fileName, "ab+");

  if (file == NULL)
  {
    printf("\nOcorreu um erro ao criar/abrir o arquivo");
    return 1;
  }

  /*! Variável do tipo Reserve para leitura */
  Reserve *inputReserve = calloc(1, sizeof(Reserve));

  /*! Contador de reservas */
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

  /*! Fim do carregamento dos dados do arquivo para a memória */

  uint running = 1;

  char option;

  while (running)
  {
    /*! Quanto todas as mesas forem reservadas o programa deve ser finalizado */
    if (reservedTables == 50)
    {
      printf("\nTodas as mesas foram reservadas, finalizando programa\n");
      break;
    }

    /*! Leitura da opção desejada */

    do
    {
      printf("\nSelecione uma opcao: ");
      scanf(" %c", &option);
    } while (option < 'a' || option > 'f');

    if (option == 'a')
    {
      uint id = reservesSize == 0 ? 1 : reserves[reservesSize - 1].id + 1;

      /*! Variável para armazenar quantas mesas irão compor a reserva */
      uint reserveTables = 0;

      do
      {
        printf("\nDigite o numero de mesas que deseja reservar: ");
        scanf("%d", &reserveTables);
      } while (reserveTables < 1 || reserveTables > 50);

      /*! Variável do tipo Reserve para construção da reserva que
             *  Posteriormente será adicionada a lista reserves
             * */
      Reserve *reserve = calloc(1, sizeof(Reserve));

      reserve->id = id;

      /*! I é a variável referente a mesa, de 0 á quantidade de mesas informada`s da reserva */
      for (uint i = 0; i < reserveTables; ++i)
      {
        /*! Quantidade de clientes ativos na mesa (i) */
        int tableClients = 0;

        do
        {
          printf("\nDigite o numero de clientes da %d mesa: ", i + 1);
          scanf("%d", &tableClients);
        } while (tableClients < 0 || tableClients > 4);

        reserve->tables[i].activeClients = tableClients;

        /*! Variável para armazenar a entrada de dados
                 *  dos clientes da mesa (i), dados que são
                 *  copiados para o cliente da iteração do
                 *  array de clientes da mesa
                 * */
        char input[20];

        /*! K é a variável referente ao cliente, de 0 á quantidade de clientes informados
                 *  para a mesa (i)
                 * */
        for (uint k = 0; k < tableClients; ++k)
        {
          printf("\nDigite o nome do %d cliente da %d mesa: ", k + 1, i + 1);

          setbuf(stdin, NULL);
          fgets(input, 16, stdin);

          input[strlen(input) - 1] = '\0';

          strcpy(reserve->tables[i].clients[k].name, input);

          printf("\nDigite o telefone do %d cliente da %d mesa: ", k + 1, i + 1);

          setbuf(stdin, NULL);
          fgets(input, 10, stdin);

          input[strlen(input) - 1] = '\0';

          strcpy(reserve->tables[i].clients[k].telephone, input);

          printf("\nDigite o email do %d cliente da %d mesa: ", k + 1, i + 1);

          setbuf(stdin, NULL);
          fgets(input, 20, stdin);

          input[strlen(input) - 1] = '\0';

          strcpy(reserve->tables[i].clients[k].email, input);

          reserve->tables[i].reserveId = reserve->id;
        }
      }

      /*! Incremento das mesas reservadas */
      reservedTables += reserveTables;

      /*! Copia da variável para construção da reserva para dentro
             *  da lista de reservas
             * */
      memcpy(&reserves[reservesSize], reserve, sizeof(Reserve));

      /**!
             * Zerando a variável reserve para a próxima utilização
             */
      free(reserve);

      /*! Incremento da quantidade de reservas */
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
        /*! Identificação da reserva por um id informado */
        if (reserves[i].id == reserveId)
        {

          /*! Move-se a reserva que se deseja remover para
                     *  a última posiçcão da lista, e em seguida
                     *  decrementa-se o tamanho da lista em 1
                     * */
          for (size_t k = i; k < reservesSize - 1; ++k)
          {
            reserves[k] = reserves[k + 1];
          }

          /*! Decrementa-se o valor de mesas ativas com base
                     *  nas mesas ativas da reserva removida
                     * */
          reservedTables -= activeTables(&reserves[i]);
          reservesSize--;

          printf("\nReserva removida com sucesso\n");

          found = 1;
        }
      }

      /*! Caso a reserva não seja encontrada, é enviada uma mensagem */
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
        /*! Identificação da reserva por um id informado */
        if (reserves[i].id == reserveId)
        {
          Reserve reserve = reserves[i];

          /*! Variável para armazenar a quantidade de mesas
                     *  na reserva encontrada
                     * */
          uint reserveTables = activeTables(&reserve);

          printf("\nNumero de mesas: %d\n", reserveTables);

          /*!
                     *  K é a variável referente as mesas da reserva
                     * */
          for (uint k = 0; k < reserveTables; ++k)
          {
            printf("\nMesa %d\n", k + 1);

            printf("\nClientes ativos: %d\n", reserve.tables[k].activeClients);

            /*!
                         *  L é a variável referente aos clientes
                         *  da mesa (k) da reserva (i)
                         * */
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

      /*! Caso a reserva não seja encontrada, é enviada uma mensagem */
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
          Reserve reserve = reserves[i];

          /*! Variável para armazenar a quantidade de mesas
                     *  na reserva encontrada
                     * */
          uint reserveTables = activeTables(&reserve);

          printf("\nId da Reserva: %d", reserve.id);
          printf("\nNumero de mesas: %d", reserveTables);

          /*!
                     *  K é a variável referente as mesas da reserva
                     * */
          for (uint k = 0; k < reserveTables; ++k)
          {
            printf("\n\nMesa %d\n", k + 1);

            printf("Clientes ativos: %d\n", reserve.tables[k].activeClients);

            /*!
                         *  L é a variável referente aos clientes
                         *  da mesa (k) da reserva (i)
                         * */
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
      /*! Cáculo da taxa de ocupação do restaurante */

      uint activeTables = reservedTables;

      /*!
             * Cáculo da ocupação das mesas
             *
             * Mesas      Porcentagem
             *  50     -     100%
             *  x      -       y%
             * */

      printf("\nTaxa de ocupacao das mesas: %d de %d (%.2f por cento)\n", activeTables, 50,
             (float)(activeTables * 10.0) / 5.0);

      uint activeClients = 0;

      clients(reserves, reservesSize, &activeClients);

      /*!
             * Cálculo da ocupação de pessoas
             *
             * pessoas   mesas    porcentagem
             * 200     -  50   -    100%
             * xp      -  xm   -      y%
             * */

      float a = (float)((200.0 / activeClients) * (50.0 / activeTables));
      float b = (100.0F / a);

      printf("\nTaxa de ocupacao de pessoas: %d em %d mesas (%.2f por cento)\n", activeClients, activeTables, b);
    }
    else
    {
      running = 0;
    }
  }

  /*! Inserção das reservas no arquivo */

  file = fopen(fileName, "wb");

  if (reservesSize > 0)
  {
    fwrite(reserves, sizeof(Reserve), reservesSize, file);
  }

  fclose(file);

  free(reserves);

  return 0;
}