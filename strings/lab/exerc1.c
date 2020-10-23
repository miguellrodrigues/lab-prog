#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];

    printf("\nDigite uma frase: ");
    fgets(str, 256, stdin);

    char r[strlen(str)];
    size_t end = strlen(str) - 1;

    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++)
    {
        r[i] = str[end--];
    }

    printf("\n%s\n", r);
    
    return 0;
}