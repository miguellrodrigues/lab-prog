#include <stdio.h>

/*
    Faça um programa que leia dois vetores (A e B) de cinco posições de números
    inteiros. O programa deve, então. subtrair o primeiro elemento de A do último de B,
    acumulando o valor, subtrair o segundo elemento de A do penúltimo de B,
    acumulando o valor e assim por diante. Mostre o resultado da soma de todas as
    subtrações.
*/

int main(void)
{
    int a[5], b[5];

    for (size_t i = 0; i < 5; i++)
    {
        printf("\nDigite o valor do %d elemento de A: ", i + 1);
        scanf("%d", &a[i]);

        printf("Digite o valor do %d elemento de B: ", i + 1);
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        int bx = b[4 - i];

        printf("\n%d - %d = %d", a[i], bx, a[i] - bx);
    }
    
    printf("\n");

    return 0;
}