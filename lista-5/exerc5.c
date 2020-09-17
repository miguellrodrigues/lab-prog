#include "stdio.h"

int main()
{
    unsigned int password = 1234, read = 0;

    printf("\nDigite a senha: ");
    scanf("%d", &read);

    while (password != read)
    {
        printf("\nSenha invalida, tente novamente: ");
        scanf("%d", &read);
    }

    printf("\nAcesso permitido");

    return 0;
}