#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n = 0;

    cin >> n;
    int a[n];

    int64_t fib[61];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 61; i++)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << "Fib(" << a[i] << ") = " << fib[a[i]] << endl;
    }

    return 0;
}