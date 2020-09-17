/*

*  **
*  * Created by Miguel on 10/09/2020.
*  **

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

int main(void)
{
    float x1, y1, x2, y2;

    char line[100];
    char split[] = ",";

    size_t counter = 0;

    while (1)
    {
        printf("\nDigite as coordenadas da seguinte forma: (X1,Y1,X2,Y2): ");
        scanf("%s", line);

        char *ptr = strtok(line, split);

        while (ptr != NULL)
        {
            if (counter == 0)
            {
                x1 = atof(ptr);
            }

            if (counter == 1)
            {
                y1 = atof(ptr);
            }

            if (counter == 2)
            {
                x2 = atof(ptr);
            }

            if (counter == 3)
            {
                y2 = atof(ptr);
            }

            ptr = strtok(NULL, split);

            counter++;
        }

        counter = 0;

        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            break;

        printf("\nA distancia entre os pontos (%f, %f) (%f, %f) e` %f\n", x1, y1, x2, y2, distance(x1, y1, x2, y2));
    }

    return 0;
}
