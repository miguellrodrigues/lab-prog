#include <bits/stdc++.h>

using namespace std;

float m[12][12];

int main(void)
{
    char c;

    scanf("\n%c", &c);

    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }

    float s = 0;
    unsigned int p = 0;
    
    for (size_t i = 1; i < 12; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            if (j < i)
            {
                s += m[i][j];
            }
        }
    }

    if (c == 'S')
    {
        printf("%.1f\n", s);
    }
    else if (c == 'M')
    {
        s /= 66.0;

        printf("%.1f\n", s);
    }

    return 0;
}