#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];

    printf("\nDigite uma frase: ");
    gets(str);

    size_t count = 0;

    for(size_t i = 0; i < strlen(str); i++){
        if (str[i] != '\0')
            count++;;
    }

    char r[count];
    size_t end = count - 1;

    for (int i = 0; i < count; i++)
    {
        r[i] = str[end--];
    }

    printf("\n%s\n", r);
    
    return 0;
}