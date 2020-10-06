#include <stdio.h>

/*
    Escrever um programa que leia a dimensão e os elementos de um vetor, um de cada
    vez. O programa calcula a média aritmética dos elementos do vetor e determina quais
    elementos do vetor são menores que a média. O programa deve imprimir os elementos
    menores e suas posições. Caso não seja encontrado nenhum elementos menor que a
    média, o usuário deve ser notificado através de uma mensagem.
*/

int main(void)
{
    unsigned int n;

    printf("\nDigite a dimensao do array: ");
    scanf("%d", &n);
    
    printf("\n");

    float a[n], media = 0;

    for (size_t i = 0; i < n; i++)
    {
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%f", &a[i]);

        media += a[i];
    }

    media /= n;

    unsigned int minor = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < media)
        {
            minor++;

            printf("\nPos: %d | Val: %.3f", i + 1, a[i]);
        }
    }

    printf("\n");

    if (minor == 0)
    {
        printf("\nNao foram encontrados elementos menores que a media");
    }
    else
    {
        printf("\nQuantidade de elementos menores que a media: %d", minor);
    }

    printf("\n");

    return 0;
}