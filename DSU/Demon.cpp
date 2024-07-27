#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
// Code đi đừng sợ!

int q;
vector<int> par, Q, sz;
unordered_map<int, int> mp;

void makeSet()
{
    par.resize(q + 1);
    Q.resize(q + 1);
    sz.resize(q + 1, 1);
    for (int i = 1; i <= q; ++i)
    {
        par[i] = i;
    }
}

int findSet(int v)
{
    return (par[v] == v) ? v : par[v] = findSet(par[v]);
}

int Union(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a == b)
        return a;
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return a;
}

void update(int u, int v)
{
    if (mp.count(u))
    {
        int tmp1 = mp[u];
        mp.erase(u);
        if (mp.count(u + v))
        {
            int tmp2 = mp[u + v];
            mp.erase(u + v);
            int root = Union(tmp1, tmp2);
            Q[root] = u + v;
            mp[u + v] = root;
        }
        else
        {
            mp[u + v] = tmp1;
            Q[tmp1] = u + v;
        }
    }
}

void Solve()
{
    cin >> q;
    int i = 1;
    makeSet();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u;
            cin >> u;
            Q[i] = u;
            if (mp.count(u))
                par[i] = mp[u];
            else
                mp[u] = i;
            i++;
            for (auto x : Q)
                cout << x << " ";
            cout << endl;
        }
        else if (t == 2)
        {
            int u, v;
            cin >> u >> v;
            cout << "Old Map" << endl;
            for (auto x : mp)
                cout << x.first << " " << x.second << endl;
            cout << "UP Map" << endl;
            update(u, v);
            for (int x : Q)
                cout << x << " ";
            cout << endl;
            for (auto x : mp)
                cout << x.first << " " << x.second << endl;
        }
        else if (t == 3)
        {
            int u;
            cin >> u;
            cout << "Q : " << Q[findSet(u)] << '\n';
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
