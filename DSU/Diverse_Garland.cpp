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

struct DSU
{
    vector<int> par, sz;
    DSU(int n)
    {
        par.resize(n);
        sz.assign(n, 1);
        iota(all(par), 0);
    }
    int get(int v)
    {
        return par[v] == v ? v : par[v] = get(par[v]);
    }

    bool unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a != b)
        {
            par[b] = a;
            sz[a] += sz[b];
        }
        return a != b;
    }
    int getSz(int u)
    {
        return sz[get(u)];
    }
};

void Solve()
{
    int n;
    string s;
    cin >> n >> s;
    DSU dsu(n);
    vector<char> group(n + 1);
    f0(i, n)
    {
        if (s[i] == s[i + 1] && i + 1 < n)
        {
            dsu.unite(i, i + 1);
        }
        group[dsu.get(i)] = s[i];
    }

    int cur = -1, next = 0, cnt = 0;
    f0(i, n)
    {
        if (cur != dsu.get(i))
        {
            cnt += dsu.getSz(i) / 2;
            cur = dsu.get(i);
            for (int j = i + 1; j < n; j++)
            {
                if (dsu.get(j) != cur)
                {
                    next = dsu.get(j);
                    break;
                }
            }
        }
        if ((i - cur) % 2 == 1)
        {
            for (char j : {'R', 'G', 'B'})
            {
                if (j != group[cur] && j != group[next])
                {
                    s[i] = j;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    cout << s << endl;
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