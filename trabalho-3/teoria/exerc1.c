#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readContactFile(char *str, char *lst[], char *delimiter, int *x) {
    char *token = strtok(str, delimiter);

    int count = 0;

    while (token != NULL) {
        lst[count++] = token;
        token = strtok(NULL, delimiter);
    }

    *x = count;
}

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

    int remove;
};

int contactExistInArray(struct Contact contact, struct Contact array[], int size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        struct Contact arrayContact = array[i];

        if (arrayContact.name == contact.name && arrayContact.birthMonth == contact.birthMonth &&
            arrayContact.birthday == contact.birthday && arrayContact.telephone == contact.telephone) {
            return 1;
        }
    }

    return 0;
}

void loadAllContacts(struct Contact contacts[], int *size) {
    FILE *contactsFile = fopen("/home/miguellr/CLionProjects/arquivos/contacts.txt", "r");

    int contactsSize = 0;

    char buff[1024];
    char *str = fgets(buff, 1024, contactsFile);

    if (str == NULL)
        return;

    char *contactList[1024];

    readContactFile(str, contactList, "-", &contactsSize);

    int j = 0;

    size_t i;
    for (i = 0; i < contactsSize; ++i) {
        char *contactString[4];
        split(contactList[i], contactString, ":");

        struct Contact contact;

//        contact.name = contactString[0];
//        contact.telephone = contactString[1];
//        contact.birthday = contactString[2];
//        contact.birthMonth = contactString[3];

        contact.remove = 0;

        contacts[j++] = contact;
    }

    *size = j;

    fclose(contactsFile);
}

void saveContacts(struct Contact contacts[], int size) {
    if (size == 0)
        return;

    int storedContactsSize;
    struct Contact storedContacts[1000];

    //loadAllContacts(storedContacts, &storedContactsSize);

    FILE *contactsFile = fopen("/home/miguellr/CLionProjects/arquivos/contacts.txt", "w");

    size_t i;
    for (i = 0; i < size; ++i) {
        struct Contact contact = contacts[i];

        if (contactExistInArray(contact, storedContacts, storedContactsSize) || contact.remove)
            continue;

        char data[128];

        strcat(data, contact.name);
        strcat(data, ":");
        strcat(data, contact.telephone);
        strcat(data, ":");
        strcat(data, contact.birthday);
        strcat(data, ":");
        strcat(data, contact.birthMonth);
        strcat(data, "-");

        fputs(data, contactsFile);
    }

    fclose(contactsFile);
}

int main(void) {
    int size = 0;

    struct Contact *contacts = malloc (1024 * sizeof (struct Contact));;

    //loadAllContacts(contacts, &size);

    int running = 1;

    int option = 0;

    char *month = "novembro";

    char searchName[16];

    char addName[16], addTelephone[16], addDay[2], addMn[12];

    while (running) {
        do {
            printf("\nSelecione uma opcao: ");
            scanf("%d", &option);
        } while (option < 1 || option > 7);

        if (option == 1) {
            printf("\nDigite o nome: ");
            setbuf(stdin, NULL);
            gets(addName);

            printf("\nDigite o telefone: ");
            fflush(stdin);
            fgets(addTelephone,16,stdin);

            printf("\nDigite o dia de nascimento: ");
            fflush(stdin);
            fgets(addDay,5,stdin);

            printf("\nDigite o mes de nascimento: ");
            fflush(stdin);
            fgets(addMn,12,stdin);

            int pos = size == 0 ? 0 : size;

            struct Contact add;

            strcpy(add.name,addName);
            strcpy(add.telephone,addTelephone);
            strcpy(add.birthday,addDay);
            strcpy(add.birthMonth,addMn);
            add.remove = 0;

            strcpy(contacts[pos].name,add.name);
            strcpy(contacts[pos].telephone, add.telephone);
            strcpy(contacts[pos].birthday, add.birthday);
            strcpy(contacts[pos].birthMonth, add.birthMonth);
            contacts[pos].remove = add.remove;

            size += 1;

        } else if (option == 2) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("\nDigite o nome que voce procura: ");
            scanf("%s", searchName);

            int found = 0;

            int i;
            for (i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove == 1)
                    continue;

                if (strcmp(contact.name, searchName) == 0)
                {
                    contact.remove = 1;

                    printf("\nO Contato %s foi exluido", contact.name);

                    contacts[i] = contact;

                    size--;

                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                printf("\nNenhum contato encontrado com o nome %s", searchName);
            }

        } else if (option == 3) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("Digite o nome que voce procura: ");

            printf("\nDigite o nome que voce procura: ");
            scanf("%s", searchName);

            int found = 0;

            size_t i;
            for (i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (strcmp(contact.name, searchName) == 0)
                {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                printf("\nNenhum contato encontrado com o nome %s", searchName);
            }

        } else if (option == 4) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            int k;
            for (k = 0; k < size; k++) {
                struct Contact contact = contacts[k];

                if (contact.remove == 1)
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

            size_t i;
            for (i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (contact.name[0] == start)
                {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s/%s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                }
            }

            if(found == 0) {
                printf("\nNenhum contato encontrado com a incial %c", start);
            }

        } else if (option == 6) {
            if (size == 0) {
                printf("\nNenhum contato cadastrado");
                continue;
            }

            printf("\nAniversariantes do mes: \n");

            int found = 0;

            size_t i;
            for (i = 0; i < size; ++i) {
                struct Contact contact = contacts[i];

                if (contact.remove)
                    continue;

                if (strcmp(contact.birthMonth, month) == 0)
                {
                    printf("\nNome: %s", contact.name);
                    printf("\nNascimento: %s de %s", contact.birthday, contact.birthMonth);
                    printf("\nTelefone: %s\n", contact.telephone);

                    found = 1;
                }
            }

            if(found == 0) {
                printf("\nNao foram encontrados aniversariantes do mes");
            }
        } else {
            running = 0;
        }
    }

    saveContacts(contacts, size);

    return 0;
}
