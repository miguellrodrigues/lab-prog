#include "stdio.h"

int main(void)
{
    float a, b, c, media;
  
    printf("Digite o valor do primeiro numero: ");
    scanf("%f", &a);
    
    printf("Digite o valor do segundo numero: ");
    scanf("%f", &b);

    printf("Digite o valor do terceiro numero: ");
    scanf("%f", &c);
    
    media = (a + b + c) / 3;
    
    printf("Media = %.1f\n", media);

    return 0;
}