#include "stdio.h"

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

    printf("\nDigite o salario familia: ");
    scanf("%f", &salarioFamilia);

    printf("\nDigite o tempo de servico (Anos): ");
    scanf("%d", &tempoServico);

    salarioBruto = horasTrabalhadas * salarioHora;
    desconto *= salarioBruto;

    salarioFamilia /= filhos;

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

    printf("\nSalario bruto: %.2f\nDesconto INSS: %.2f\nImposto de renda: %.2f\nAdicional: %.2f\nSalario familia: %f\n", salarioBruto, desconto, ir, adicional, salarioFamilia);

    return 0;
}