#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 105;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/problemset/problem/505/B
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node{
    int x , c;
};

int n, m, q;
vector<Node> a[maxn];
int vis[maxn];

void dfs(int u, int c)
{
    vis[u] = 1;
    for(auto [v , color] : a[u]) {
        if(!vis[v] && color == c)
            dfs(v, c);
    }
}

void Solve()
{
    cin >> n >> m;
    f0(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].pb({v , c});
        a[v].pb({u , c});
    }
    int q;
    cin >> q;

    f0(i, q) {
        int u, v;
        cin >> u >> v;
        int cnt = 0;
        f1(i, 100) {
            memset(vis, 0, sizeof(vis));
            dfs(u,i);
            if(vis[v])
                cnt++;
        }
        cout << cnt << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
