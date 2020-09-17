#include "stdio.h"

int main(void)
{
    int ano;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (ano % 4 == 0 && ano % 100 != 0) {
        printf("O ano %d e` bissexto", ano);
    } else {
        printf("O ano %d nao e` bissexto", ano);
    }

    return 0;
}