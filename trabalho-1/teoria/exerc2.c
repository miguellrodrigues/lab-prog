/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>

float calculoAumento(float salario, int aumento) { return salario * (aumento / 100.0); }

int main(void)
{
    float salario, novoSalario;
    int aumento;

    printf("\nDigite o valor do salario: ");
    scanf("%f", &salario);

    printf("\nDigite o valor do aumento (0 a 100) porcento: ");
    scanf("%d", &aumento);

    novoSalario = salario + calculoAumento(salario, aumento);

    printf("\nNovo salario: %.3f\nAumento: %.3f\n", novoSalario, novoSalario - salario);

    return 0;
}