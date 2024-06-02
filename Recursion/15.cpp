#include <bits/stdc++.h>
using namespace std;

int Solve(int a[], int n)
{
    if (a[n - 1] % 2 == 1)
        return false;
    if (n == 0)
        return true;
    return Solve(a, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << Solve(a, n);
}