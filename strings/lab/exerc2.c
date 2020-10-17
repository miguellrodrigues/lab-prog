#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[256];

    printf("\nDigite uma palavra: ");
    gets(str);

    size_t len = strlen(str), count = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] != '\0')
            count++;
    }

    char inverse[count];

    for (size_t i = 0; i < count; i++)
    {
        str[i] = tolower(str[i]);
    }

    strcpy(inverse, str);
    strrev(inverse);

    if (strcmp(inverse, str) == 0)
    {
        printf("\nA frase %s e` um palindromo\n");
    }
    else
    {
        printf("\nA frase %s nao e` um palindromo\n");
    }

    return 0;
}