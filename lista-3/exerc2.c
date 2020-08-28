#include "stdio.h"

int main(void)
{
    float altura, pesoIdeal;
    char sex[1];

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("Digite seu sexo: (H ou M): ");
    scanf("%s", &sex);

    while (sex[0] != 'H' && sex[0] != 'M') {
        printf("Sexo invalido, digite seu sexo: (H ou M): ");
        scanf("%s", &sex);
    }

    pesoIdeal = sex[0] == 'H' ? (72.7 * altura) - 58 : (62.1 * altura) - 44.7;

    printf("\nSeu peso ideal e`: %f", pesoIdeal);

    return 0;
}