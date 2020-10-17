#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[256], str1[256];

    char option, c1, c2;

    printf("\nDigite uma string: ");

    gets(str);

    char cp[strlen(str)];

    printf("\nSelecione uma opcao: (A, B, C, D): ");
    scanf("\n%c", &option);

    switch (option)
    {
    case 'A':
        printf("\nTamanho: %d", strlen(str));

        strcpy(cp, str);
        strcat(cp, "concatenada");
        break;

    case 'B':
        printf("\nDigite a String S2: ");

        fflush(stdin);
        gets(str1);

        if (strcmp(str, str1) == 0)
        {
            printf("\nStrings iguais");
        }
        else
        {
            printf("\nStrings diferentes");
        }

        printf("\nStrings concatenadas: %s", strcat(str, str1));
        break;

    case 'C':
        printf("\nDigite o caractere C1: ");
        scanf(" %c", &c1);

        printf("\nDigite o caractere C2: ");
        scanf(" %c", &c2);

        unsigned int counter = 0;

        for (size_t i = 0; i < strlen(str); i++)
        {
            if (str[i] == c1)
            {
                if (counter++ == 0)
                {
                    str[i] = c2;
                }
            }
        }

        printf("\nResultado: %s", str);

        break;

    case 'D':
        printf("\nDigite a String S2: ");

        fflush(stdin);
        gets(str1);

        if (strstr(str, str1) != NULL)
        {
            printf("\nA string %s e uma substring de %s", str1, str);
        }
        else
        {
            printf("\nA string %s nao e uma substring de %s", str1, str);
        }

        break;

    default:
        break;
    }

    return 0;
}