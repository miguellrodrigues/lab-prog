#include "stdio.h"

int main(void) 
{
    float indice;

    printf("Digite o valor do indice: ");
    scanf("%f", &indice);

    if (indice >= 0.3) {
        printf("\nAs empresas do primeiro grupo devem suspender as atividades");
    } else if (indice >= 0.4) {
        printf("\nAs empresas do primeiro e segundo grupos devem suspender as atividades");
    } else if (indice >= 0.5) {
         printf("\nTodas as empresas devem suspender as atividades");
    } else {
         printf("\nNenhuma das empresas devem suspender as atividades");
    }

    return 0;
}