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
const int maxn = 100005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/

vector<vector<int>> a(maxn);
vector<int> vis(maxn,  0);
int n, m;
void dfs(int u)
{
    for(auto i : a[u]) {
        if(vis[i]) {
            if(vis[i] == vis[u]) {
                cout << "IMPOSSIBLE" << el;
                exit(0);
            }
        } else {
            vis[i] = 3 - vis[u];
            dfs(i);
        }
    }
}
void Solve()
{
    cin >> n >> m;
    f1(i, m) {
        int u, v ;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    f1(i, n) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    f1(i, n)
    cout << vis[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
