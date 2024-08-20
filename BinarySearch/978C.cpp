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
/*
 /\_/\
(= >_<)
/ >  \>
*/
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0), b(m + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
    {
        ll x = b[i];
        auto it = lower_bound(all(pre), x) - pre.begin();
        cout << it << " " << x - pre[it - 1] << endl;
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