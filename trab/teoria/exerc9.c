/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include "math.h"

int main(void)
{
    float x1, x2, y1, y2, distance = 0;

    printf("Digite os valores na seguinte ordem: (X1 | Y1 | X2 | Y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    distance = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));

    printf("\nA distancia entre os pontos (%f, %f) (%f, %f) e` %f\n", x1, y1, x2, y2, distance);

    return 0;
}
