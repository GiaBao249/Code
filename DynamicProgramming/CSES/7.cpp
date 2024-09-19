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
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    f0(i, n) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    // Xác Định nếu tại a[i] = 0 và a[i] = k
    For(i, 1, k + 1)
    {
        if (a[0] == 0 || a[0] == i)
            dp[1][i] = 1;
    }
    For(i, 2, n + 1)
    {
        For(j, 1, k + 1)
        {
            if (a[i - 1] != 0 && a[i - 1] != j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int x = j - 1; x <= j + 1; x++)
            {
                if (x < 1 || x > k)
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][x]) % MOD;
            }
        }
    }
    int res = 0;
    For(i, 1, k + 1)
        res = (res + dp[n][i]) % MOD;
    cout << res << endl;
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
    return 0;
}
