#include <stdio.h>

int partition(int *list, int lowerBound, int upperBound) {
    int pivot = list[lowerBound];

    int start = lowerBound;
    int end = upperBound;
    
    int aux;

    while (start < end) {
        while (list[start] <= pivot) {
            start++;
        }

        while (list[end] > pivot) {
            end--;
        }

        if (start < end) {
            aux = list[start];

            list[start] = list[end];
            list[end] = aux;
        }
    }

    aux = list[lowerBound];

    list[lowerBound] = list[end];
    list[end] = aux;

    return end;
}

void quickSort(int* list, int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {
        int loc = partition(list, lowerBound, upperBound);

        quickSort(list, lowerBound, loc - 1);
        quickSort(list, loc + 1, upperBound);
    }
}

int main() {
    int numbers[9] = {744, 6747, 141, -557, 94, -2, 1, 0, 7};

    quickSort(numbers, 0, 9);

    for (size_t i = 0; i < 9; ++i) {
        printf("\n%d", numbers[i]);
    }

    return 0;
}
