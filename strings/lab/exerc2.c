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
        char t[7] = "       ";

        for (size_t i = 0; i <= x; i++)
        {
            if (str[i] == 'T')
            {
                size_t a = i  + 7, b = 0;

                for(size_t j = i; j < a; j++) 
                {   
                    if (str[j] == keyboard[j - i])
                    {
                        if (b++ == 6)
                        {
                            printf("\n%d", j - 6);
                        }
                    }
                }

                //printf("\n%d", b);

                printf("\n");
            }
        }
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
    for (size_t i = 0; i < len && src[offset + i] != '\0'; i++)
    {
        dest[i] = src[i + offset];
    }
}

char *changeString(char str[])
{
    int pos = strpos(str, "TECLADO", 0);

    char c[256], d[256];

    for (size_t i = 0; i <= pos + 6; i++)
    {
        c[i] = str[i];
    }

    substr(d, str, pos + 7, strlen(str));

    strcat(c, " OU MOUSE");
    strcat(c, d);

    return c;
}