#include <stdio.h>
#include "string.h"

int main(void)
{
    char str[256];

    printf("\nDigite uma frase: ");
    gets(str);

    if (strstr(str, "TECLADO") != NULL)
    {
        int pos = strpos(str, "TECLADO", 0);

        printf("\n%d", pos);
        printf("\n%d", pos + 6);
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