#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *str, char *dest[], char *delimiter) {
    char *token = strtok(str, delimiter);

    int count = 0;

    while (token != NULL) {
        dest[count++] = token;
        token = strtok(NULL, delimiter);
    }
}

struct Contact {
    char name[16];

    char telephone[16];
    char birthday[5];
    char birthMonth[16];

    size_t remove;
};

void loadAllContacts(struct Contact contacts[], int *size) {
    FILE *contactsFile = fopen("contacts.txt", "r");

    if (contactsFile == NULL) {
        printf("\nPor favor, crie o arquivo contacts.txt na raiz do projeto");
        exit(1);
    }

    char currentLine[1024] = {'\0'};

    int j = 0;

    while (fgets(currentLine, 1024, contactsFile) != NULL) {
        currentLine[strlen(currentLine) - 1] = '\0';

        char *contactString[4];

        split(currentLine, contactString, ":");

        struct Contact contact;

        strcpy(contact.name, contactString[0]);
        strcpy(contact.telephone, contactString[1]);
        strcpy(contact.birthday, contactString[2]);
        strcpy(contact.birthMonth, contactString[3]);

        contact.remove = 0;

        contacts[j++] = contact;
    }

    *size = j;

    fclose(contactsFile);
}

void saveContacts(struct Contact contacts[], int size) {
    if (size == 0)
        return;

    FILE *contactsFile = fopen("contacts.txt", "w+");

    for (size_t i = 0; i < size; ++i) {
        struct Contact contact = contacts[i];

        if (contact.remove)
            continue;

        char data[256] = {'\0'};

        strcat(data, contact.name);
        strcat(data, ":");
        strcat(data, contact.telephone);
        strcat(data, ":");
        strcat(data, contact.birthday);
        strcat(data, ":");
        strcat(data, contact.birthMonth);
        strcat(data, "\n");

        fputs(data, contactsFile);
    }

    fclose(contactsFile);
}

int main(void) {
    int size = 0;

    struct Contact *contacts = calloc(1024, sizeof(struct Contact));;

    loadAllContacts(contacts, &size);

    int running = 1;

    int option = 0;

    char *month = "novembro";

    char searchName[16] = {'\0'};

    char addName[16] = {'\0'}, addTelephone[16] = {'\0'}, addDay[5] = {'\0'}, addMn[12] = {'\0'};

    while (running) {
        do {
            printf("\nSelecione uma opcao: ");
            scanf("%d", &option);
        } while (option < 1 || option > 7);

        if (option == 1) {

            printf("\nDigite o nome: ");
            setbuf(stdin, NULL);
            fgets(addName, 16, stdin);

            printf("\nDigite o telefone: ");
            setbuf(stdin, NULL);
            fgets(addTelephone, 16, stdin);

            printf("\nDigite o dia de nascimento: ");
            setbuf(stdin, NULL);
            fgets(addDay, 5, stdin);

            printf("\nDigite o mes de nascimento: ");
            setbuf(stdin, NULL);
            fgets(addMn, 12, stdin);

            int pos = size == 0 ? 0 : size;

            struct Contact add;

            addName[strlen(addName) - 1] = '\0';
            addTelephone[strlen(addTelephone) - 1] = '\0';
            addDay[strlen(addDay) - 1] = '\0';
            addMn[strlen(addMn) - 1] = '\0';

            strcpy(add.name, addName);
            strcpy(add.telephone, addTelephone);
            strcpy(add.birthday, addDay);
            strcpy(add.birthMonth, addMn);

            add.remove = 0;

            contacts[pos] = add;

            size++;

        } else if (option == 2) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("\nDigite o nome que voce procura: ");
            setbuf(stdin, NULL);
            fgets(searchName, 16, stdin);

            searchName[strlen(searchName) - 1] = '\0';

            int found = 0;

            for (int i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (strcmp(contact.name, searchName) == 0) {

                    printf("\nO Contato %s foi exluido", contact.name);

                    contact.remove = 1;

                    contacts[i] = contact;

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("\nNenhum contato encontrado com o nome %s", searchName);
            }

        } else if (option == 3) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("\nDigite o nome que voce procura: ");
            setbuf(stdin, NULL);
            fgets(searchName, 16, stdin);

            int found = 0;

            for (size_t i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (strcmp(contact.name, searchName) == 0) {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("\nNenhum contato encontrado com o nome %s", searchName);
            }

        } else if (option == 4) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            for (size_t k = 0; k < size; k++) {
                struct Contact contact = contacts[k];

                if (contact.remove)
                    continue;

                printf("\nNome: %s", contact.name);
                printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                printf("\nTelefone: %s\n", contact.telephone);
            }

        } else if (option == 5) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            char start;

            printf("\nDigite a letra que o nome deve iniciar: ");
            scanf(" %c", &start);

            printf("\nContatos que iniciam o nome com a letra %c: \n", start);

            int found = 0;

            for (size_t i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (contact.name[0] == start) {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                }
            }

            if (found == 0) {
                printf("\nNenhum contato encontrado com a incial %c", start);
            }

        } else if (option == 6) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("\nAniversariantes do mes: \n");

            int found = 0;

            for (size_t i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (strcmp(contact.birthMonth, month) == 0) {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                }
            }

            if (found == 0) {
                printf("\nNao foram encontrados aniversariantes do mes");
            }
        } else {
            running = 0;
        }
    }

    saveContacts(contacts, size);

    return 0;
}