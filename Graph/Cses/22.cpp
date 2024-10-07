/// Ever try ever failed no matter , try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll, ll>;
#define pb push_back
#define CLR(a, b) memset((a), b, sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll) x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll n, m;
ll par[N], siz[N];

struct Edge
{
    ll u, v, w;
};
vector<Edge> a;
ll get(ll v)
{
    return v == par[v] ? v : par[v] = get(par[v]);
}

void unite(ll a, ll b)
{
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (siz[a] < siz[b])
        swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
}

bool Cycle(ll u, ll v)
{
    return get(u) == get(v);
}
bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}
void Solve()
{
    cin >> n >> m;
    ll cnt = 0;
    f1(i, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        a.pb({u, v, w});
    }
    f1(i, n)
    {
        par[i] = i;
        siz[i] = 1;
    }
    sort(all(a), cmp);
    int t = 0;
    for (auto e : a)
    {
        if (!Cycle(e.u, e.v))
        {
            unite(e.u, e.v);
            cnt += e.w;
            t++;
        }
    }
    if (t == n - 1)
        cout << cnt << el;
    else
        cout << "IMPOSSIBLE";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}