#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

vector<ll> vec(200005);
struct DSU
{
    vector<ll> parent, sz;
    set<ll> se;
    DSU(int n) : parent(n + 1), sz(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        vec[1] = n;
        se.insert(1);
    }

    int findSet(int v)
    {
        return parent[v] == v ? v : parent[v] = findSet(parent[v]);
    }

    void Union(ll a, ll b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);

        vec[sz[a]]--;
        if (vec[sz[a]] == 0)
            se.erase(sz[a]);
        vec[sz[b]]--;
        if (vec[sz[b]] == 0)
            se.erase(sz[b]);
        sz[a] += sz[b];
        parent[b] = a;
        vec[sz[a]]++;
        se.insert(sz[a]);
    }
};

void Solve()
{
    int n, q;
    cin >> n >> q;
    DSU d(n);
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int u, v;
            cin >> u >> v;
            d.Union(u, v);
        }
        else if (a == 2)
        {
            int u;
            cin >> u;
            cout << d.sz[d.findSet(u)] << endl;
        }
        else if (a == 3)
        {
            // for (auto x : d.se)
            //     cout << x << " ";
            if (d.se.size() < 2)
            {
                cout << -1 << endl;
            }
            else
            {
                auto it = d.se.rbegin();
                it++;
                cout << *it << endl;
            }
        }
    }
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
