#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;

    cin >> n;

    int a[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int l = a[0], p = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < l)
        {
            l = a[i];
            p = i;
        }
    }
    
    cout << "Menor valor: " << l << endl;
    cout << "Posicao: " << p << endl;

    return 0;
}