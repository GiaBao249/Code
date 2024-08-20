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
const int mod = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1634
*/
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1, 0);
    f0(i, n) cin >> a[i];
    f1(i, k) dp[i] = k + 1;
    int mn = inf;
    if (*min_element(all(a)) > k)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    if (dp[k] == k + 1)
        cout << -1 << endl;
    else
        cout << dp[k] << endl;
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