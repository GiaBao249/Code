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
const int maxn = 200005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/

ll cnt[maxn][32];
void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    f1(i, n) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            cnt[i][j] = cnt[i - 1][j];
        }
        ll k = 0;
        while (a[i] > 0)
        {
            if (a[i] & 1)
                cnt[i][k]++;
            a[i] >>= 1;
            k++;
        }
    }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        ll t = 1;
        for (int i = 0; i < 32; i++)
        {
            if (cnt[r][i] - cnt[l - 1][i])
                res += t;
            t *= 2;
        }
        cout << res << endl;
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
    return 0;
}