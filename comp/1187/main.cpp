#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    double m[12][12];

    char c[2];

    scanf("%s", &c);

    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            scanf("%lf", &m[i][j]);
        }
    }

    double s = 0.f;

    size_t l = 1, h = 11;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = l; j < h; j++)
        {
            s += m[i][j];
        }

        h--;
        l++;
    }

    if (c[0] == 'S')
    {
        printf("%.1lf\n", s);
    }
    else if (c[0] == 'M')
    {
        s /= 30.0;

        printf("%.1lf\n", s);
    }

    return 0;
}