#include <bits/stdc++.h>
using namespace std;
using pii = pair<int ,int>;
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
#define inf LONG_MAX
const int N = 5005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, m ;
vector<vector<pii>> a;
vector<ll> d,cnt;

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[s] = 0;
    cnt[s] = 1;
    q.push({0, s});
    while(!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if(du > d[u]) continue;
        for(auto &[v, w] : a[u]) {
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                q.push({d[v], v});
            } else if(d[u] + w == d[v]) {
                cnt[v] = cnt[v] + cnt[u];
            }
        }
    }
}

void Solve()
{
    cin >> n >> m;
    a.resize(n + 1);
    d.resize(n + 1, inf);
    cnt.assign(n + 1, 0);
    f1(i, m) {
        int t , u, v, w;
        cin >> t >> u >> v >> w;
        a[u].pb({v, w});
        if(t == 2) {
            a[v].pb({u, w});
        }
    }
    dijkstra(1);
    cout << d[n] << " " << cnt[n] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
