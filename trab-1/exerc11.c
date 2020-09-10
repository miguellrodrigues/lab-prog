/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

int main(void)
{
    float num1, num2, result = 0;
    int operation, run = 1;

    while (run)
    {
        printf("\nDigite o valor do primeiro numero: ");
        scanf("%f", &num1);

        printf("Digite o valor do segundo numero: ");
        scanf("%f", &num2);

        printf("\n");

        printf("Digite a operacao: \n\nadicao (1)\nsubtracao (2)\nmultiplicacao (3)\ndivisao (4)\nsair (5)\n\n");
        scanf("%d", &operation);

        while (operation == 4 && num2 <= 0)
        {
            printf("O divisor nao pode ser 0, digite o valor do segundo numero novamente: ");
            scanf("%f", &num2);
        }

        result = num1;

        switch (operation)
        {
        case 1:
            result += num2;
            break;
        case 2:
            result -= num2;
            break;
        case 3:
            result *= num2;
            break;
        case 4:
            result /= num2;
            break;
        case 5:
            run = 0;
            break;
        default:
            break;
        }

        if (run == 0)
            break;

        printf("\nResultado: %.3f", result);
    }

    return 0;
}