#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define el '\n'

void Solve()
{
    int R, n, m;
    cin >> R >> n >> m;
    vector<pair<int, int>> l, r;
    vector<int> a(n), b(n), c(m), d(m);
    f0(i, n) cin >> a[i];
    f0(i, n) cin >> b[i];
    f0(i, m) cin >> c[i];
    f0(i, m) cin >> d[i];

    f0(i, n) l.push_back({a[i], b[i]});
    f0(i, m) r.push_back({c[i], d[i]});

    sort(ALL(l));
    sort(ALL(r));
    ll money = 0;
    vector<ll> preL(n + 1, 0), preR(m + 1, 0);
    f1(i, n) preL[i] = preL[i - 1] + l[i - 1].second;
    f1(i, m) preR[i] = preR[i - 1] + r[i - 1].second;
    for (int c = 1; c <= R; c++)
    {
        auto u = lower_bound(ALL(l), make_pair(c, 0)) - l.begin();
        // int index1 = (u - l.begin());

        auto v = lower_bound(ALL(r), make_pair(R - c, 0)) - r.begin();
        // int index2 = (v - r.begin());

        ll total = preL[n] - preL[u] + preR[m] - preR[v];
        money = max(money, total);
    }
    cout << money << el;
}
int main()
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