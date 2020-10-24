#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[256];

    printf("\nDigite uma palavra: ");
    gets(str);

    size_t len = strlen(str) - 1;

    char inverse[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }

    strcpy(inverse, str);
    strrev(inverse);

    if (strcmp(inverse, str) == 0)
    {
        printf("\nA palavra %s e` um palindromo\n");
    }
    else
    {
        printf("\nA palavra %s nao e` um palindromo\n");
    }

    return 0;
}