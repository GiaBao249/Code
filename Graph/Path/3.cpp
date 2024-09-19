///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LLONG_MAX / 3
const int N = 100005;
const int MOD= 1e9 + 7;
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
vector<vector<pii>> a , b;
vector<ll> d1, d2;
ll n, m;
void dijkstra(ll s,vector<ll> &d ,vector<vector<pii>> &x)
{
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while(sz(q)) {
        auto [du, u] = q.top();
        q.pop();
        if(du != d[u])
            continue;
        for(auto &[v, w] : x[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

void Solve()
{
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(n + 1);
    d1.assign(n + 1, inf);
    d2.assign(n + 1, inf);
    f1(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        b[v].pb({u, w});
    }
    dijkstra(1 , d1 , a);
    dijkstra(n , d2 , b);
    ll res = d1[n];
    for(int u = 1 ; u <= n ; u++)
    {
        for(auto &[v , w] : a[u])
        {
            ll x = w / 2;
            res = min(res , d1[u] + x + d2[v]);
        }
    }
    cout << res << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}

