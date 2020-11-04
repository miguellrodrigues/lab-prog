#include <stdio.h>
#include <ctype.h>

void encode(char *str, int pos, int size) {
  for(size_t i = 0; i < size && str[i] != '\0'; ++i) {
    char c = toupper(str[i]);

    if (c >= 'A' && c <= 'Z') {
      c += pos;

      if (c > 'Z') {
        c = c - ('Z' + 'A') + 1;
      }

      str[i] = c;
    }
  }
}

void decode(char *str, int pos, int size) {
  for(size_t i = 0; i < size && str[i] != '\0'; ++i) {
    char c = toupper(str[i]);

    if (c >= 'A' && c <= 'Z') {
      c -= pos;

      if (c < 'A') {
        c = c + ('Z' - 'A') + 1;
      }

      str[i] = c;
    }
  }
}

int main(void)
{
  char str[60];
  int option;

  printf("\nDigite uma string: ");
  fgets(str, sizeof(str), stdin);

  do {
    printf("\nSelecione uma opcao: \n1 (Codificar)\n2 (Decodificar)\n\n");
    scanf("%d", &option);
  }while(option < 1 || option > 2);

  if (option == 1) {

    encode(str, 3, strlen(str));

    printf("\nString codificada: %s", str);

  } else if (option == 2) {
    decode(str, 3, strlen(str));

    printf("\nString decodificada: %s", str);
  }

  return 0;
}