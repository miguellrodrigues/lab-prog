#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x = 0, y = 0;

    do
    {
        scanf("%d %d", &x, &y);

        if (x == y)
            break;

        if (x < y)
        {
            cout << "Crescente" << endl;
        }
        else
        {
            cout << "Decrescente" << endl;
        }
    } while (x != y);

    return 0;
}