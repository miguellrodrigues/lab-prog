#include <stdio.h>

int main(void)
{
  int option = 0;

  printf("\nSelecione uma opcao: \n1 (Gravar)\n2 (Ler)\n\n");
  scanf("%d", &option);

  if (option == 1)
  {
    FILE *numbers = fopen("numbers.bin", "wb");

    if (!numbers)
    {
      printf("\nOcorreu um erro ao abrir o arquivo");
      return 1;
    }

    int a[20];

    for (int i = 0; i < 20; i++)
    {
      printf("\nDigite o valor do %d elemento: ", i + 1);
      scanf("%d", &a[i]);
    }

    fwrite(a, sizeof(int), 20, numbers);

    fclose(numbers);
  }
  else if (option == 2)
  {
    FILE *readNumbers = fopen("numbers.bin", "rb");

    if (readNumbers == NULL)
    {
      printf("\nOcorreu um erro ao abrir o arquivo");
      return 1;
    }

    int b[20] = {0};

    fread(b, sizeof(int), 20, readNumbers);

    printf("\n");

    for (int i = 0; i < 20; ++i)
    {
      printf("\nI = %d | Value = %d", i + 1, b[i]);
    }

    printf("\n");

    fclose(readNumbers);
  }
  else
  {
    printf("\nOpcao invalida");
  }

  return 0;
}