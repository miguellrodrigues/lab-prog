#include "stdio.h"
#include "windows.h"

int main(void)
{
    SetConsoleOutputCP(65001);

    float factory_price, consumer_price;

    printf("Digite o valor de fábrica: ");
    scanf("%f", &factory_price);

    consumer_price = factory_price + ((28.0 / 100.0) * factory_price) + ((45.0 / 100.0) * factory_price);

    printf("\nValor para o consumidor: %.2f", consumer_price);

    return 0;
}