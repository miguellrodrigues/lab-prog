#include "stdio.h"

int main(void)
{
    float num;

    printf("Digite um numero: ");
    scanf("%f", &num);

    printf("\nA terca parte de %.f e` %.3f", num, (num / 3.0));

    return 0;
}