#include <bits/stdc++.h>
using namespace std;

string Solve(int n, string s)
{
    if (n == 0)
        return s;
    return Solve(n / 2, s + to_string(n % 2));
}

void SolveINT(int n)
{
    if (n == 0)
        return;
    else
    {
        SolveINT(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    // cout << Solve(n, "");
    SolveINT(n);
}