#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
    char str[256], keyboard[7] = "TECLADO";

    fflush(stdin);

    printf("\nDigite uma frase: ");
    gets(str);

    int x = strlen(str) - 7;

    if (x < 0)
    {
        printf("\n\nNenhuma ocorrencia encontrada");
    }
    else if (x == 0)
    {
        if (strcmp(str, "TECLADO") == 0)
        {
            printf("\n\nTECLADO OU MOUSE\n");
        }
    }
    else
    {
        for (size_t i = 0; i < strlen(str) - 6; i++)
        {
            if (str[i] == 'T')
            {
                size_t a = i + 7, b = 0;

                for (size_t j = i; j < a; j++)
                {
                    if (str[j] == keyboard[j - i])
                    {
                        if (b++ == 6)
                        {
                            changeString(str, j + 1);
                        }
                    }
                }
            }
        }

        printf("\n%s\n", str);
    }

    return 0;
}

int strpos(char *str, char *find, int offset)
{
    char stack[strlen(str)];
    strncpy(stack, str + offset, strlen(str) - offset);

    char *p = strstr(stack, find);
    if (p)
        return p - stack + offset;

    return -1;
}

substr(char dest[], char src[], int offset, int len)
{
    size_t i;

    for (i = 0; i < len && src[offset + i] != '\0'; i++)
    {
        dest[i] = src[i + offset];
    }

    dest[i] = '\0';
}

changeString(char str[], size_t end)
{
    char c[256], d[256];

    for (size_t i = 0; i < end; i++)
    {
        c[i] = str[i];
    }

    substr(d, str, end, strlen(str));

    strcat(c, " OU MOUSE");
    strcat(c, d);

    str[0] = '\0';

    strcpy(str, c);
}