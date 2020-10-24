#include <stdio.h>
#include <string.h>

void substr(char dest[], char src[], int offset, int len)
{
    size_t i;

    for (i = 0; i < len && src[offset + i] != '\0'; i++)
    {
        dest[i] = src[i + offset];
    }

    dest[i] = '\0';
}

void changeString(char str[], size_t end)
{
    char c[120], d[120];
    size_t i;

    for (i = 0; i < 120; i++)
    {
        c[i] = '\0';
        d[i] = '\0';
    }

    for (i = 0; i < end; i++)
    {
        c[i] = str[i];
    }

    substr(d, str, end, strlen(str));

    strcat(c, " OU MOUSE");
    strcat(c, d);

    str[0] = '\0';

    strcpy(str, c);
}

int main(void)
{
    char str[120], keyboard[9] = "TECLADO";

    printf("\nDigite uma frase: ");
    fgets(str, 120, stdin);

    str[strlen(str) - 1] = '\0';

    int x = ((int)strlen(str) - 7);

    if (x < 0)
    {
        printf("\nNenhuma ocorrencia encontrada\n");
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
        int b;
        size_t i;

        for (i = 0; i < (strlen(str) - strlen(keyboard)) + 1; i++)
        {
            if (str[i] == 'T')
            {
                b = 0;

                size_t j;

                for (j = i; j < strlen(keyboard) + i; j++)
                {
                    if (str[j] == keyboard[j - i])
                    {
                        if (b++ == 6)
                        {
                            changeString(str, j + 1);
                            i += (strlen(keyboard) + strlen("OU MOUSE")) - 1;
                        }
                    }
                }
            }
        }
        printf("\n%s\n", str);
    }

    return 0;
}