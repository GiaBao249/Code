#include <bits/stdc++.h>
using namespace std;

string s;
int n, x[100], res = 0;
bool check(int n)
{
    int can = cbrt(n) + 0.5;
    return can * can * can == n;
}

void solve(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n - 1)
        {
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i])
                {
                    tmp = tmp * 10 + (s[i] - '0');
                }
            }
            if (check(tmp) && tmp > res)
            {
                res = tmp;
                // cout << res << endl;
            }
        }
        else
            solve(i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.size();
        res = 0;
        solve(0);
        if (res == 0)
            cout << "-1";
        else
            cout << res << endl;
    }
    return 0;
}