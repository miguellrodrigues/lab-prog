/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <malloc.h>

int cargo(unsigned int codigo)
{
    switch (codigo)
    {
    case 101:
        return 1;
        break;

    case 102:
        return 2;
        break;

    case 103:
        return 3;
        break;

    case 104:
        return 4;
        break;

    case 105:
        return 5;
        break;

    case 106:
        return 6;
        break;

    default:
        return -1;
        break;
    }

    return -1;
}

int main(void)
{
    unsigned int codigo;

    printf("\nDigite o codigo: ");
    scanf("%d", &codigo);

    int c = cargo(codigo);

    while (c < 0)
    {
        printf("\nCodivo invalido, digite o codigo: ");
        scanf("%d", &codigo);

        c = cargo(codigo);
    }

    printf("\nCargo: ");

    switch (c)
    {
    case 1:
        printf("Vendedor");
        break;
    case 2:
        printf("Atendente");
        break;
    case 3:
        printf("Auxiliar tecnico");
        break;
    case 4:
        printf("Assistente");
        break;
    case 5:
        printf("Coordenador de group");
        break;
    case 6:
        printf("Gerente");
        break;
    default:
        break;
    }

    printf("\n");

    return 0;
}