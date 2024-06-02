#include <bits/stdc++.h>
using namespace std;

int Solve(int n, int cnt)
{
    if (n == 0)
        return cnt;
    int tmp = n % 10;
    if (tmp % 2 == 0)
        return Solve(n / 10, cnt + tmp);
    else
        return Solve(n / 10, cnt);
}

int main()
{
    int n;
    cin >> n;
    cout << Solve(n, 0);
}
