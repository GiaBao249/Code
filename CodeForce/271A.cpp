#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    string s = to_string(n);
    unordered_set<char> se;
    for (int i = 0; i < s.size(); i++)
    {
        if (se.count(s[i]) > 0)
            return false;
        se.insert(s[i]);
    }
    return true;
}
int Solve(int n, int s)
{
    if (s > n && check(s))
        return s;
    return Solve(n, s + 1);
}
int main()
{
    int n;
    cin >> n;
    cout << Solve(n, n + 1);
}