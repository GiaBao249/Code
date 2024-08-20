#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
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
/ >  \> https://cses.fi/problemset/task/1635
*/
void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), dp(x + 1, 0);
    f0(i, n) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (auto x : a)
            if (i >= x)
            {
                dp[i] = (dp[i] + dp[i - x]);
                dp[i] %= MOD;
            }
    }

    cout << dp[x] << endl;
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