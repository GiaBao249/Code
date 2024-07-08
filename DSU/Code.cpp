#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
// No Pain No Gain!

int parent[MAX], R[MAX];

void makeSet(int v)
{
    parent[v] = v;
    R[v] = 0;
}

int findSet(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (R[a] < R[b])
            swap(a, b);
        parent[b] = a;
        if (R[a] == R[b])
            R[a]++;
    }
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        makeSet(i);
    for (int i = 0; i < m; i++)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (s[0] == 'u')
            unionSet(u, v);
        else
            cout << (findSet(u) == findSet(v) ? "YES" : "NO") << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solve();
    return 0;
}