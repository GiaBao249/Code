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
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    vector<ll> dp(n + 1, 0);
    vector<ll> pre(n + 1, 0);
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + ((s[i] - '0') % 2 == 0 ? 1 : 0);
        pre[i] = pre[i - 1] + ((s[i] - '0') % 2 == 0 ? i : 0);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ll res = pre[r + 1] - pre[l] - l * (dp[r + 1] - dp[l]);
        cout << res << " ";
    }
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