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
// #define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
vector<ll> par, sz, a;
ll get(ll v)
{
    return v == par[v] ? v : par[v] = get(par[v]);
}

void unite(ll a, ll b)
{
    a = get(a);
    b = get(b);
    if (a != b)
    {
        par[b] = a;
        sz[a] += sz[b];
    }
}
void Solve()
{
    ll n;
    cin >> n;
    a.resize(n, 0);
    par.resize(n, 0);
    sz.assign(n, 1);
    f0(i, n)
    {
        cin >> a[i];
        par[i] = i;
    }
    unordered_map<ll, vector<ll>> mp;
    f0(i, n) mp[a[i]].pb(i);
    for(auto &it : mp){
        reverse(all(it.second));
    }
    f0(i, n)
    {
        int x = a[i];
        mp[x].pop_back();
        if (mp[x].size() == 0)
            mp.erase(mp.find(x));
        if (mp.count(x + 1))
        {
            ll u = mp[x + 1].back();
            unite(u, i);
        }
    }
    ll mx = -1;
    f0(i, n)
    {
        ll u = get(i);
        mx = max(mx, a[u] - a[i] + 1);
    }
    vector<int> p;
    f0(i, n)
    {
        ll u = get(i);
        if (a[u] - a[i] + 1 == mx)
        {
            ll v = a[i] + 1;
            p.pb(i);
            for (int j = i + 1; j < n; j++)
            {
                if (v == a[j])
                {
                    v++;
                    p.pb(j);
                }
            }
            break;
        }
    }
    cout << mx << el;
    for (auto x : p)
        cout << x + 1 << ' ';
    cout << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
