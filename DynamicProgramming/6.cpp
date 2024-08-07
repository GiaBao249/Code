#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), dp(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll mx = -1;
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1], (i - k >= 0 ? a[i] + dp[i - k] : a[i]));
        mx = max(dp[i], mx);
    }
    cout << mx << endl;
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