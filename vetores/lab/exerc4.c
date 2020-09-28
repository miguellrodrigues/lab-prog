#include <stdio.h>

/*
    Escreva um programa que peça ao usuário para digitar a dimensão de um vetor. A
    dimensão digitada deve ser maior do que 2. Em seguida, crie um vetor do tamanho
    solicitado pelo usuário e preencha o primeiro elemento desse vetor com zero, e o
    segundo com um. A partir do terceiro elemento, utiliza-se a fórmula abaixo para
    completar o vetor:
    
    Vetor(i) = vetor (i-1) + vetor (i-2)

    Por fim, imprima o vetor gerado, o qual representa a série de Fibonacci com 20
    elementos.
*/

int main(void)
{
    int n;

    printf("Digite a dimensao do vetor (x > 2): ");
    scanf("%d", &n);

    while (n <= 2)
    {
        printf("Digite a dimensao do vetor (x > 2): ");
        scanf("%d", &n);
    }
    
    int a[n];

    a[0] = 0;
    a[1] = 1;

    for (size_t i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("\nPos: %d | Val: %d", i, a[i]);
    }

    printf("\n");
    
    return 0;
}