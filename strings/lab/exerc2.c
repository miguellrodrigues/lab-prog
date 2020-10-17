#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
    char str[256];

    printf("\nDigite uma frase: ");
    gets(str);

    fflush(stdin);

    for (size_t i = 0; i < strlen(str); i++)
    {
        char *t = malloc(7 * sizeof(char));

        for (size_t j = i, k = 0; j <= i + 6 && i + 6 < strlen(str); j++)
        {
            t[k++] = str[j];

            printf("\nA = %c", str[j]);
        }

        printf("\n T = %s", t);

        free(t);
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