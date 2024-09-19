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
const int N = 100005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1669
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, m , st , ed;
vector<int> a[N], parent(N), color(N);
bool dfs(int i, int par)
{
    color[i] = 1;
    for(auto u : a[i]) {
        if(u == par)
            continue;
        if(color[u] == 0) {
            parent[u] = i;
            if(dfs(u, parent[u])) {
                return true;
            }
        } else if(color[u] == 1) {
            st = u ;
            ed = i;
        }
    }
    color[i] = 2;
    return false;
}
void Solve()
{
    cin >> n >> m;
    st = -1;
    f1(i, m)
    {
        int u , v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    f1(i ,n)
    {
        color[i] = 0;
        dfs(i , parent[i]);
    }
    if(st == -1){
        cout << "IMPOSSIBLE" << el;
        return;
    }else{
        vector<int> v;
        v.pb(st);
        for(int i = ed ; i != st ; i = parent[i])
            v.pb(i);
        v.pb(st);
        reverse(all(v));
        cout << sz(v) << el;
        for(auto x : v)
            cout << x << " ";
        cout << el;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        Solve();
    return 0;
}
