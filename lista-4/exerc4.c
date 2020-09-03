#include "stdio.h"

int main(void)
{
    float mass = 0.f, time = 0.f;

    printf("Digite o valor da massa inicial em gramas: ");
    scanf("%f", &mass);

    unsigned int counter = 0;
    while (mass >= 0.5) {
        counter++;
        mass /= 2;
    }

    time = (counter * 50);

    printf("\nTempo decorrido: %.3f Hr, %.3f Min, %.3f Seg", (time / 3600.0), (time / 60.0), time);
    printf("\nCiclos de meia`s vidas: %d", counter);
    printf("\nMassa final: %.3fg", mass);

    return 0;
}