#include <stdio.h>

int main(void)
{
    char clients  [8][16];

    int pizzas    [8];
    int freePizzas[8];

    printf("\n");

    for (size_t i = 0; i < 8; i++)
    {
        printf("Digite o nome do %d cliente: ", i + 1);
        scanf("%s", clients[i]);

        printf("\nDigite a quantidade de pizzas compradas por(a) %s em 2010: ", clients[i]);
        scanf("%d", &pizzas[i]);

        freePizzas[i] = pizzas[i];

        printf("\n");
    }

    for (size_t i = 0; i < 8; i++)
    {
        freePizzas[i] /= 10;

        printf("\nNome: %s | Pizzas gratis: %d", clients[i], freePizzas[i]);
    }
    
    printf("\n"); 

    return 0;
}