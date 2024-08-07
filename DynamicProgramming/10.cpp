#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN

struct X
{
    ll a, b, c;
};
void Solve()
{
    int n;
    cin >> n;
    vector<X> dp(n);
    vector<ll> v(n);
    f0(i, 0, n) cin >> v[i];
    dp[0].b = v[0];
    dp[1].a = v[0] + v[1];
    dp[1].b = v[1];
    dp[1].c = v[0];
    dp[2].a = v[1] + v[2];
    dp[2].b = v[0] + v[2];
    dp[2].c = v[1] + v[0];

    f0(i, 3, n)
    {
        dp[i].a = dp[i - 1].b + v[i];
        dp[i].b = max(dp[i - 1].c, dp[i - 2].b) + v[i];
        dp[i].c = dp[i - 1].a;
    }
    // for (ll i = 0; i < n; i++)
    //     cout << dp[i].a << ' ' << dp[i].b << ' ' << dp[i].c << '\n';
    ll mx = -1;
    for (int i = 0; i < n; i++)
        mx = max({dp[i].a, dp[i].b, dp[i].c});
    cout << mx;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    return 0;
}