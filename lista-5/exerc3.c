#include "stdio.h"
#include "stdbool.h"

bool inRange(float number, float min, float max)
{
    return number >= min && number < max;
}

int main()
{  
    float salarioAtual, salarioReajuste, aumento;

    printf("Digite o valor do salario atual: ");
    scanf("%f", &salarioAtual);

    if (inRange(salarioAtual, 1000, 1500)) {
        aumento = 100;
    } else if (inRange(salarioAtual, 1500, 2500)) {
        aumento = 90;
    } else if (inRange(salarioAtual, 2500, 3000)) {
        aumento = 80;
    } else if (inRange(salarioAtual, 3000, 3500)) {
        aumento = 70;
    } else if (inRange(salarioAtual, 3500, 4000)) {
        aumento = 60;
    } else if (salarioAtual >= 4000) {
        aumento = 50;
    }

    salarioReajuste = salarioAtual + ((aumento / 100.0) * salarioAtual);

    printf("\nSalario atual: %.3f", salarioAtual);
    printf("\nAumento: %.3f ", ((aumento / 100.0) * salarioAtual));
    printf("\nSalario com reajuste: %.3f", salarioReajuste);

    return 0;
}