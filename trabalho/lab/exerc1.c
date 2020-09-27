#include <stdio.h>
#include <stdlib.h>

unsigned int inArray(unsigned int val, unsigned int *array, unsigned int m)
{
    for (size_t i = 0; i < m; i++)
    {
        if (array[i] == val)
            return 1;
    }

    return 0;
}

unsigned int pos(unsigned int val, unsigned int *array, unsigned int m)
{
    for (size_t i = 0; i < m; i++)
    {
        if (array[i] == val)
            return i;
    }

    return 0;
}

int main(void)
{
    unsigned int accounts[10];
    float        balance [10];

    unsigned int inputCode = 0,
                 running   = 1;

    for (size_t i = 0; i < 10; i++)
    {
        printf("\nDigite o codigo da %d conta: ", i + 1);
        scanf("%d", &inputCode);

        while (inArray(inputCode, accounts, 10))
        {
            printf("\nEste codigo ja esta em uso, tente outro codigo: ");
            scanf("%d", &inputCode);
        }

        accounts[i] = inputCode;

        printf("Digite o saldo da %d conta: ", i + 1);
        scanf("%f", &balance[i]);
    }

    system("cls");

    unsigned int option = 0, selectedAccount = 0, ps = 0;
    float deposit = 0.f, withdraw = 0.f;

    do
    {
        do
        {
            printf("\nSelecione uma opcao: \n\n");
            printf("1 - Consulta de saldo\n");
            printf("2 - Efetuar deposito em conta\n");
            printf("3 - Efetuar saque em conta\n");
            printf("4 - Sair\n\n");

            scanf("%d", &option);
        } while (option < 1 || option > 4);

        if (option == 4)
            break;

        printf("\nDigite o numero da conta: ");
        scanf("%d", &selectedAccount);

        while (!inArray(selectedAccount, accounts, 10))
        {
            printf("\nConta invalida, tente outra conta: ");
            scanf("%d", &selectedAccount);
        }

        ps = pos(selectedAccount, accounts, 10);

        system("cls");

        switch (option)
        {
        case 1:
            printf("\nSaldo da conta %d: %.3f", selectedAccount, balance[ps]);
            break;

        case 2:
            printf("\nDigite o valor a ser depositado: ");
            scanf("%f", &deposit);

            while (deposit <= 0)
            {
                printf("\nValor invalido, utilize valores maiores que 0: ");
                scanf("%f", &deposit);
            }

            balance[ps] += deposit;

            printf("\nNovo saldo: %.3f", balance[ps]);

            break;

        case 3:
            printf("\nDigite o valor a ser sacado: (%.3f disponiveis) ", balance[ps]);
            scanf("%f", &withdraw);

            while (balance[ps] - withdraw < 0)
            {
                printf("\nSaldo insuficiente, digite um valor valido: ");
                scanf("%f", &withdraw);
            }

            balance[ps] -= withdraw;

            printf("\nNovo saldo: %.3f", balance[ps]);

            break;

        default:
            break;
        }

        printf("\n");

    } while (running);

    system("cls");

    float sum = 0;

    for (size_t i = 1; i <= 10; i++)
    {
        sum += balance[i - 1];
    }

    printf("\nAtivo bancario: %.3f\n", sum);

    return 0;
}