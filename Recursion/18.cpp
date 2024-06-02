#include <bits/stdc++.h>
using namespace std;
int Solve(int n, int s)
{
    if (n == 0)
        return s;
    return Solve(n / 10, s + 1);
}

int main()
{
    int n;
    cin >> n;
    cout << Solve(n, 0);
}
