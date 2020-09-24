/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) { return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0)); }

int main(void)
{
    float x1, y1, x2, y2;

    unsigned int counter = 0;

    do {
        printf("\nDigite as coordenadas da seguinte forma: (X1,Y1,X2,Y2): ");
        scanf("%f,%f,%f,%f", &x1, &y1, &x2, &y2);

        printf("\nA distancia entre os pontos (%f, %f) (%f, %f) e` %f\n", x1, y1, x2, y2, distance(x1, y1, x2, y2));
    } while (x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0);

    return 0;
}
