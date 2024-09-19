#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 1005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
vector<int> a[maxn];
int vis[maxn];
int n, m;
void dfs(int i)
{
    vis[i] = 1;
    for(auto x : a[i]) {
        if(!vis[x])
            dfs(x);
    }
}

void Solve()
{
    cin >> n >> m;
    f1(i, m) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> v;
    f1(i, n) {
        if(!vis[i]) {
            dfs(i);
            v.push_back(i);
        }
    }
    cout << sz(v) - 1 << el;
    f0(i, sz(v) - 1) {
        cout << v[i] << " " << v[i + 1] << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
