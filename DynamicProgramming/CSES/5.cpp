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
/ >  \> https://cses.fi/problemset/task/1637
*/
void Solve()
{
    int n;
    cin >> n;
    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    f1(i, 9) dp[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j /= 10)
        {
            dp[i] = min(dp[i - (j % 10)] + 1, dp[i]);
            // cout << dp[i] << endl;
        }
    }
    cout << dp[n] << endl;
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