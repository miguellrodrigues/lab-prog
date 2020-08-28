/*
. Faça um algoritmo que lê o número de matrícula um funcionário, o número de
horas trabalhadas, o valor que recebe por hora, o número de filhos com idade
inferior a 14 anos, a idade, o tempo de serviço do funcionário e o valor do salário
família por filho.
a. Calcular o salário bruto (SB), o desconto do INSS (8,5% do salário bruto)
e o salário família.
b. Calcular o IR (Imposto de Renda) como segue:
i. Se SB > R$2.743,25 então IR = 27,5% SB;
ii. Se SB de R$1.372,82 até R$2.743,25 então IR = 15% SB;
iii. Se SB <= R$1.372,81 então IR = 0.
c. Calcular o adicional conforme especificado:
i. Se idade superior a 40 anos, adicional de 2% sobre o SB.
ii. Se tempo de serviço superior a 15 anos, adicional de 3,5% sobre o
SB.
iii. Se tempo de serviço inferior a 15, mas superior a 5 anos adicional
de 1,5% sobre o SB.
*/

#include "stdio.h"
#include "stdbool.h"

bool inRange(float number, float min, float max)
{
    return number >= min && number <= max;
}

int main(void)
{
    float horasTrabalhadas = 0,
          salarioHora = 0,
          salarioFamilia = 0,
          salarioBruto = 0,
          ir = 0,
          adicional = 0,
          desconto = 0.085;

    int filhos = 0, idade = 0, tempoServico = 0, matricula;

    printf("Digite o numero da matricula: ");
    scanf("%d", &matricula);

    printf("\nDigite o numero de horas trabalhadas: ");
    scanf("%f", &horasTrabalhadas);

    printf("\nDigite o salario hora: ");
    scanf("%f", &salarioHora);

    printf("\nDigite o numero de filhos com idade inferior a 14 anos: ");
    scanf("%d", &filhos);

    printf("\nDigite o tempo de servico (Anos): ");
    scanf("%d", &tempoServico);

    salarioBruto = horasTrabalhadas * salarioHora;
    desconto *= salarioBruto;

    salarioFamilia = salarioBruto / filhos;

    if (salarioBruto <= 1372.82)
    {
        ir = 0;
    }
    else if (salarioBruto >= 2743.25)
    {
        ir = 0.275 * salarioBruto;
    }
    else
    {
        ir = 0.15 * salarioBruto;
    }

    if (idade > 40)
    {
        adicional += 0.02 * salarioBruto;
    }

    if (tempoServico > 15)
    {
        adicional += 0.035 * salarioBruto;
    }
    else if (tempoServico < 15 && tempoServico > 5)
    {
        adicional += 0.015 * salarioBruto;
    }

    printf("\nSalario bruto: %.3f\nDesconto INSS: %.3f\nImposto de renda: %.3f\nAdicional: %.3f\n", salarioBruto, desconto, ir, adicional);

    return 0;
}