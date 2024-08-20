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
/ >  \> https://codeforces.com/contest/1669/problem/F
*/

int n;
vector<int> a, pre, suf;

void Solve()
{
    cin >> n;
    a.resize(n), pre.resize(n), suf.resize(n);
    f0(i, n) cin >> a[i];
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];
    int l = 0;
    reverse(all(suf));
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        int x = pre[i];
        if (binary_search(all(suf), x))
        {
            l = (i + 1);
            auto r = lower_bound(all(suf), x) - suf.begin() + 1;
            if (l + r <= n)
                res = max(l + r, res);
        }
    }
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}