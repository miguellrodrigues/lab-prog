/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

float sum(float num1, float num2) { return num1 + num2; }

int main(void)
{
    float a, b;

    printf("\nDigite o valor de 2 numeros reais: ");
    scanf("%f %f", &a, &b);

    printf("\nA soma entra %.3f e %.3f e` %.3f\n", a, b, sum(a, b));

    return 0;
}