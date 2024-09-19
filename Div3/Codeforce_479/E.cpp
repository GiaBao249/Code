///Ever try ever failed no matter , try again fail again fail better!
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
#define el '\n'
#define inf INT_MAX
const ll N = 200005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

vector<int> par(N), sz(N), edge(N),d(N);

int get(int i)
{
    return (i == par[i] ? i : par[i] = get(par[i]));
}

void unite(int u, int v)
{
    u = get(u);
    v = get(v);
    if(u == v)
        edge[u]++;
    else {
        if(sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        edge[u] += edge[v] + 1;
    }
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    par.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    edge.assign(n + 1, 0);
    d.assign(n + 1, 0);
    f1(i, n) par[i] = i;
    f1(i, m) {
        int u, v ;
        cin >> u >> v;
        unite(u, v);
        d[u]++, d[v]++;
    }
    int cnt = 0;
    unordered_map<int, vector<int>> mp;
    f1(i, n) {
        int x = get(i);
        mp[x].pb(i);
    }
    for(auto [u, v] : mp) {
        int uu = sz[u];
        int vv = edge[u];
        if(uu == vv) {
            bool ok = true;
            for(auto x : v) {
                if(d[x] != 2) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                cnt++;
        }
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}

