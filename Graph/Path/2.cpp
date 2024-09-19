#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf LONG_MAX
const ll N = 20005;
const ll MOD = 1e9 + 7;
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
vector<vector<pii>> a;
vector<ll> d;
ll n,m;
void dijsktra(ll s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[s] = 0;
    q.push({d[s], s});
    while(sz(q)) {
        auto [du, u] = q.top();
        q.pop();
        if(du != d[u])
            continue;
        for(auto &x : a[u]) {
            ll v = x.first, w = x.second;
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
    d.assign(n + 1, inf);
    f1(i,m) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v , w});
    }
    dijsktra(1);
    f1(i , n) cout << d[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

