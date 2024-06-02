#include <bits/stdc++.h>
using namespace std;

string Try(int n, string s)
{
    if (n == 0)
        return s;
    return Try(n - 1, s + to_string(n % 10));
}

string Solve(int n, string s)
{
    if ((s[n - 1] - '0') % 2 == 0)
        return "No";
    if (n == 0)
        return "YES";
    return Solve(n - 1, s);
}

int main()
{
    int n;
    cin >> n;
    string s = Try(n, "");
    cout << Solve(s.size(), s);
}