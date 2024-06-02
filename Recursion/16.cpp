#include <bits/stdc++.h>
using namespace std;

int Solve(int n, int cnt)
{
    if (n == 0)
        return cnt;
    if (n % 2 == 0 || n % 3 == 0)
        cnt++;
    if (n % 2 == 0)
        Solve(n / 2, cnt);
    else if (n % 3 == 0)
        Solve(n / 3, cnt);
    else
        Solve(n - 1, cnt);
}

int main()
{
    int n;
    cin >> n;
    cout << Solve(n, 0);
}