#include <bits/stdc++.h>
using namespace std;

bool Solve(int a[], int l, int r)
{
    if (a[l] != a[r])
        return false;
    else if (l >= r)
        return true;
    return Solve(a, l + 1, r - 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << boolalpha << Solve(a, 0, n - 1);
}