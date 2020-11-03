#include <stdio.h>

void decode(char *str, int pos, int size)
{
  for(size_t i = 0; i < size && str[i] != '\0'; ++i) {
    char c = str[i];

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
  char toDecode[60] = "D OLJHLUD UDSRVD PDUURP VDOWRX VREUH RFDFKRUUR FDQVDGR";

  decode(toDecode, 3, strlen(toDecode));

  printf("\nTexto decodificado: %s\n", toDecode);

  return 0;
}
