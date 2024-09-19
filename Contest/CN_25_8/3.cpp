#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/

ll dp[2][maxn];

void Solve()
{
    for (int i = 1; i <= maxn; i++)
    {
        if (i == 1)
        {
            dp[0][i] = dp[1][i] = 1;
        }
        else
        {
            dp[0][i] = (dp[0][i - 1] * 2 + dp[1][i - 1]) % MOD;
            dp[1][i] = (dp[0][i - 1] + 4 * dp[1][i - 1]) % MOD;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    Solve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[0][n] + dp[1][n]) % MOD << endl;
    }
    return 0;
}
