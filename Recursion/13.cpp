#include <bits/stdc++.h>
using namespace std;

int Try(int n, int s)
{
    if (n == 0)
        return s;
    s = (s * 10 + n % 10);
    return Try(n / 10, s);
}

bool Solve(int n)
{
    int x = Try(n, 0);
    if (x == n)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << Try(n, 0);
    cout << boolalpha << Solve(n);
}