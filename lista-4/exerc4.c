#include "stdio.h"
#include "math.h"

int main(void)
{
    float mass = 0.f;
    unsigned int time = 0, counter = 0;

    printf("Digite o valor da massa inicial em gramas: ");
    scanf("%f", &mass);

    for (counter = 0; mass >= 0.5; counter++)
    {
        mass /= 2;
    }

    time = (counter * 50);

    unsigned int hours = floor(time / 3600);
    unsigned int minutes = floor(time - (hours * 3600)) / 60;
    unsigned int seconds = floor(seconds % 60);

    printf("\nTempo decorrido: %d Hr, %d Min, %d Seg", hours, minutes, seconds);
    printf("\nCiclos de meia`s vidas: %d", counter);
    printf("\nMassa final: %.3fg", mass);

    return 0;
}
