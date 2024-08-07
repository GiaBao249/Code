#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/1829/problem/E
*/

struct DSU
{
    vector<int> par, sz;
    DSU(int n)
    {
        par.resize(n);
        sz.assign(n, 1);
        f0(i, n) par[i] = i;
    }
    int get(int v)
    {
        return par[v] == v ? v : par[v] = get(par[v]);
    }

    void unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
    int getSz(int u)
    {
        return sz[get(u)];
    }
};

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    f0(i, n) f0(j, m) cin >> a[i][j];
    vector<pair<int, int>> c = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    DSU d(n * m);
    f0(i, n)
    {
        f0(j, m)
        {
            if (a[i][j] == 0)
                continue;
            for (auto &[x, y] : c)
            {
                int u = i + x, v = j + y;
                if (u >= 0 && u < n && v >= 0 && v < m && a[u][v] != 0)
                {
                    d.unite(i * m + j, u * m + v);
                }
            }
        }
    }

    unordered_map<int, int> mp;
    f0(i, n)
    {
        f0(j, m)
        {
            if (a[i][j] == 0)
                continue;
            mp[d.get(i * m + j)] += a[i][j];
        }
    }

    int mx = 0;
    for (auto x : mp)
    {
        mx = max(mx, x.second);
    }
    cout << mx << endl;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}