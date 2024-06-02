#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        double tmp = 1.0 * a[i] / 100;
        s += tmp;
    }
    cout << (s / n) * 100 << endl;
}