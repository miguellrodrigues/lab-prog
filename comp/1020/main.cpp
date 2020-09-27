#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;

    cin >> n;

    int years = n / 365;
    int months = (n - (years * 365)) / 30;
    int days = (n - (years * 365)) % 30;

    cout << years << " ano(s)" << endl;
    cout << months << " mes(es)" << endl;
    cout << days << " dia(s)" << endl;

    return 0;
}