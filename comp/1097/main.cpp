#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int l = 7, ll = 7;
    for (size_t i = 1; i < 10; i++)
    {
        if (i % 2 != 0)
        {
            for (size_t j = 0; j < 3; j++)
            {
                cout << "I=" << i << " J=" << l-- << endl;
            }
            l = ll + 2;
            ll = l;
        }
    }

    return 0;
}