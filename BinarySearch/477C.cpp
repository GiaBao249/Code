#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN 5 * 1e5 + 1
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    f0(i, 0, n) cin >> a[i];
    vector<ll> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];

    if (pre[n - 1] % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    ll x1 = pre[n - 1] / 3;
    ll x2 = 2 * x1;

    vector<ll> id1, id2;

    f0(i, 0, n - 1)
    {
        if (pre[i] == x1)
            id1.push_back(i);
        if (pre[i] == x2)
            id2.push_back(i);
    }
    ll res = 0;
    for (int i = 0; i < id1.size(); i++)
    {
        auto u = lower_bound(ALL(id2), id1[i] + 1);
        res += id2.end() - u;
    }
    cout << res << endl;
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