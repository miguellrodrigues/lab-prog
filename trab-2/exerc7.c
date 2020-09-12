/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    float kiloWatts = 0, result = 0;

    printf("\nDigite o valor dos KW: ");
    scanf("%f", &kiloWatts);

    result = (kiloWatts * 1.46);
    result += result * 0.18;

    printf("\nTotal a pagar: R$ %.3f", result);

    return 0;
}