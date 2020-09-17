/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <malloc.h>

char *cargo(unsigned int codigo)
{
    switch (codigo)
    {
    case 101:
        return "Vendedor";
        break;

    case 102:
        return "Atendente";
        break;

    case 103:
        return "Auxiliar tecnico";
        break;

    case 104:
        return "Assistente";
        break;

    case 105:
        return "Coordenador de grupo";
        break;

    case 106:
        return "Gerente";
        break;

    default:
        return ".";
        break;
    }

    return ".";
}

int main(void)
{
    unsigned int codigo;

    printf("\nDigite o codigo: (101 .. 106) ");
    scanf("%d", &codigo);

    char *c = cargo(codigo);

    while (c[0] == '.')
    {
        printf("\nCodivo invalido, digite um codigo valido (101 .. 106): ");
        scanf("%d", &codigo);

        c = cargo(codigo);
    }

    printf("\nCargo: %s\n", c);

    return 0;
}