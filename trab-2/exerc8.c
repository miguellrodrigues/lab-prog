/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

float mediaCombustivel(float km, float comb)
{
    return km / comb;
}

int main(void)
{
    float km, combustivel;

    printf("\nDigite o numero de kilometros rodados: ");
    scanf("%f", &km);

    printf("\nDigite a quantidade de combustivel gasta em litros: ");
    scanf("%f", &combustivel);

    printf("\nMedia de combustivel gasto: %.2f Km/Litro\n", mediaCombustivel(km, combustivel));

    return 0;
}