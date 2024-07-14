#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
// Code đi đừng sợ!

void Solve()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int x = m - 1, y = 0, z = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
            x = m;
        else if (s[i] == 'W')
        {
            if (x <= 0)
                y++;
        }
        else
        {
            if (x <= 0)
                z++;
        }
        x--;
    }
    if (y > k)
        z++;
    if (z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}