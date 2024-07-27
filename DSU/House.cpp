#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define el '\n'

vector<int> a, b, total, parent, sz;
vector<bool> visited;
map<int, int> se;

void makeSet(int n)
{
    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    total.resize(n + 1);
    visited.resize(n + 1, false);
    f1(i, n)
    {
        parent[i] = i;
        total[i] = a[i];
        se[i] = i;
    }
}

int findSet(int v)
{
    return v == parent[v] ? v : parent[v] = findSet(parent[v]);
}

void Union(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        total[a] += total[b];
    }
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    f1(i, n) cin >> a[i];
    f1(i, m) cin >> b[i];
    makeSet(n);
    vector<int> res;

    f1(i, m)
    {
        int house = b[i];
        if (visited[house])
        {
            auto it_l = se.lower_bound(house);
            auto it_r = se.upper_bound(house);
            int l = -1, r = -1;
            if (it_l != se.begin())
            {
                --it_l;
                l = it_l->second;
            }
            if (it_r != se.end())
            {
                r = it_r->second;
            }
            // cout << l << " " << r << endl;

            if (l != -1 && r != -1)
            {
                if (a[l] > a[r])
                    house = l;
                else
                    house = r;
            }
            else if (l != -1)
                house = l;
            else if (r != -1)
                house = r;
        }

        visited[house] = true;
        se.erase(house);

        if (house > 1 && visited[house - 1])
            Union(house, house - 1);
        if (house < n && visited[house + 1])
            Union(house, house + 1);

        res.push_back(total[findSet(house)]);
    }

    for (auto x : res)
        cout << x << '\n';
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
