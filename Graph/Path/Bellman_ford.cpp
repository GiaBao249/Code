///Ever try ever failed no matter, try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
const ll N = 5005;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct Node{
    ll a , b, w;
};

ll n, m;
vector<ll> d;
vector<Node> edge;
vector<ll> a[N];
vector<bool> vis ;
void dfs(ll u){
    vis[u] = 1;
    for(auto v : a[u]){
        if(!vis[v]){
            dfs(v);
        }
    } 
}

bool bellman_ford() {
    d[1] = 0;
    f1(i , n - 1) {
        for (auto e : edge) {
            if (d[e.a] != -inf && d[e.b] < d[e.a] + e.w) {
                d[e.b] = d[e.a] + e.w;
            }
        }
    }
    for (auto e : edge) {
        if (d[e.a] != -inf && d[e.b] < d[e.a] + e.w && vis[e.b]) {
            return true;
        }
    }
    return false;
}

void Solve() {
    cin >> n >> m;
    d.assign(n + 1, -inf); 
    vis.assign(n + 1 , 0);
    f1(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
        a[v].pb(u);
    }
    dfs(n);
    if (bellman_ford())
        cout << -1 << el;
    else
        cout << d[n] << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
