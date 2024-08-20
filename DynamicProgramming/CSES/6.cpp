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
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1158
*/
struct X
{
    int f, s;
};
void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<X> a(n);
    f0(i, n) cin >> a[i].f;
    f0(i, n) cin >> a[i].s;
    vector<ll> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= a[i].f; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i].f] + a[i].s);
        }
    }
    cout << dp[x];
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
