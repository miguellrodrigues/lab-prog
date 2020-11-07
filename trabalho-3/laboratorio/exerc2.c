#include <stdio.h>
#include <string.h>

int main(void)
{
  int option = 0;

  printf("\nSelecione uma opcao: \n\n1 (Ler um arquivo)\n2 (Gravar um arquivo)\n\n");
  scanf("%d", &option);

  char fileName[256] = {'\0'};

  printf("\nDigite o nome do arquivo: ");

  setbuf(stdin, NULL);
  fgets(fileName, 256, stdin);

  fileName[strlen(fileName) - 1] = '\0';

  strcat(fileName, ".txt");

  char lines[50][256];

  if (option == 1)
  {
    FILE *readFile = fopen(fileName, "r");

    if (readFile == NULL)
    {
      printf("Erro, arquivo nao encontrado");
      return 1;
    }

    int i = 0;

    while (fgets(lines[i], 256, readFile) != NULL)
    {
      printf("%s", lines[i++]);
    }

    fclose(readFile);
  }
  else if (option == 2)
  {

    FILE *writeFile = fopen(fileName, "w");

    int currentLine = 0;

    printf("\n");

    for (int i = 0; i < 50; i++)
    {
      printf("Digite a %d linha (%d linhas restantes) ", i + 1, (50 - (i + 1)));

      setbuf(stdin, NULL);
      fgets(lines[currentLine], 256, stdin);

      char *line = lines[currentLine++];

      line[strlen(line) - 1] = '\0';

      if (strcmp(line, "FIM") == 0)
        break;

      line[strlen(line)] = '\n';

      fputs(line, writeFile);
    }

    printf("\n");

    fclose(writeFile);
  }
  else
  {
    printf("\nOpcao invalida");
  }

  return 0;
}