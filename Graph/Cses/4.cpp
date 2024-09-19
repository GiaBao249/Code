#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef std::vector<ll> vl;
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

vector<vl> a(maxn);
vl d(maxn) , pre(maxn);
int n, m;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    d[u] = 1;
    while(sz(q))
    {
        int u = q.front();
        q.pop();
        for(auto v : a[u]){
            if(!d[v]){
                pre[v] = u;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
void Solve()
{
    cin >> n >> m;
    f1(i , m)
    {
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(1);
    vl truy;
    if(d[n] > 0){
        cout << d[n] << el;
        while(n){
            truy.push_back(n);
            n = pre[n];
        }
        reverse(all(truy));
        f0(i , sz(truy)) cout << truy[i] << " ";
    }else{
        cout << "IMPOSSIBLE" << el;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
