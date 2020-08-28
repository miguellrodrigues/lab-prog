#include "stdio.h"

int main(void) 
{
    int i;
    float real[3], a, higher = 0;

    printf("Digite um valor inteiro: ");
    scanf("%d", &i);

    printf("Digite o valor de a, b e c: ");
    scanf("%f %f %f", &real[0], &real[1], &real[2]);

    if (i == 1) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (real[i] > real[j]) {
                    a =  real[i];

                    real[i] = real[j];
                    real[j] = a;
                }
            }
        }

        printf("%f, %f, %f", real[0], real[1], real[2]);
    } else if (i == 2) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (real[i] < real[j]) {
                    a =  real[i];

                    real[i] = real[j];
                    real[j] = a;
                }
            }
        }

        printf("%f, %f, %f", real[0], real[1], real[2]);
    } else if (i == 3) {
        for (int i = 0; i < 4; ++i) {
            if (real[i] > higher)
                higher = real[i];
        }

        printf("O maior valor e`: %f", higher);
    }

    return 0;
}