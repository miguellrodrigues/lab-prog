#include "stdio.h"

int main(void)
{
    float factory_price, consumer_price;

    printf("Digite o valor de fabrica: ");
    scanf("%f", &factory_price);

    consumer_price = factory_price + ((28.0 / 100.0) * factory_price) + ((45.0 / 100.0) * factory_price);

    printf("\nValor para o consumidor: %.2f", consumer_price);

    return 0;
}