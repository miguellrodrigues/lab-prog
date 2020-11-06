#include <stdio.h>

int main(void) {
    int m[4][6], n[6][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("\nDigite o valor do elemento M(%d, %d): ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("\nDigite o valor do elemento N(%d, %d): ", i + 1, j + 1);
            scanf("%d", &n[i][j]);
        }
    }

    int sums[4] = {0};

    int aux = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            aux += m[i][j] + n[j][i];
        }

        sums[i] = aux;
        aux = 0;
    }

    for (int k = 0; k < 4; k++) {
        printf("\nSoma %d: %d", (k + 1), sums[k]);
    }

    return 0;
}