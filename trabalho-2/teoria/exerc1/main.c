#include <stdio.h>

int main(void)
{
    char clients  [8][16];

    int pizzas    [8];

    printf("\n");

    for (size_t i = 0; i < 8; i++)
    {
        printf("Digite o nome do %d cliente: ", i + 1);
        scanf("%s", clients[i]);

        printf("Digite a quantidade de pizzas compradas por(a) %s em 2010: ", clients[i]);
        scanf("%d", &pizzas[i]);

        printf("\n");
    }

    for (size_t i = 0; i < 8; i++)
    {
        pizzas[i] /= 10;

        printf("\nNome: %s | Pizzas gratis: %d", clients[i], pizzas[i]);
    }
    
    printf("\n"); 

    return 0;
}