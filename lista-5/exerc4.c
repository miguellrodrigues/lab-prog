#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    unsigned int serial;
    unsigned int height;
} Ox;

int main()
{
    srand(time(NULL));

    Ox bois[10];

    for (size_t i = 0; i < 10; i++) {
        bois[i].serial = (rand() % 1000) + 1;
        bois[i].height = (rand() % 300) + 150;
    }
    
    Ox max = bois[0], min = bois[0];

    for (size_t i = 0; i < 10; i++) {
        if (bois[i].height > max.height) {
            max = bois[i];
        }

        if (bois[i].height < min.height) {
            min = bois[i];
        }
    }

    printf("\nBoi mais gordo: Id - %d, Peso - %d", max.serial, max.height);
    printf("\nBoi mais magro: Id - %d, Peso - %d", min.serial, min.height);

    return 0;
}