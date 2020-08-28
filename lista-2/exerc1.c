#include "stdio.h"

int main()
{
    float num1, num2;

    printf("Digite o valor de dois numeros: ");
    scanf("%f %f", &num1, &num2);

    printf("O maior numero e` %.f", num1 > num2 ? num1 : num2);

    return 0;
}