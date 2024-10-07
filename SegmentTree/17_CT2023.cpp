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
ll n, q;
bool check(ll x, ll k)
{
    if (x % k == 0)
        return true;
    while (x > 0)
    {
        ll u = x % 10;
        if (u == k)
            return true;
        x /= 10;
    }
    return false;
}
struct ST
{
    vector<ll> a, t;
    void build(ll id, ll l, ll r, ll k)
    {
        if (l == r)
        {
            if (check(l, k))
                t[id] = 2 * a[l];
            else
                t[id] = a[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid, k);
        build(id << 1 | 1, mid + 1, r, k);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    void init(vector<ll> &_a, ll k)
    {
        a = _a;
        t.resize(sz(a) << 2);
        build(1, 1, sz(a) - 1, k);
    }
    void update(ll id, ll l, ll r, ll p, ll v, ll k)
    {
        if (p < l || p > r)
            return;
        if (l == r)
        {
            a[p] = v;
            // cout << "a[p]" << ' ' << a[p] << el;
            if (check(p, k))
            {
                t[id] = (2 * a[p]);
                // cout << k << ' ' << t[id] << el;
            }
            else
                t[id] = a[p];
            return;
        }
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, p, v, k);
        update(id << 1 | 1, mid + 1, r, p, v, k);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return t[id];
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
};
ST seg[10];
vector<ll> a;
void Solve()
{
    cin >> n >> q;
    a.resize(n + 1, 0);
    f1(i, n) cin >> a[i];
    f1(i, 9) seg[i].init(a, i);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p, v;
            cin >> p >> v;
            f1(i, 9)
            {
                seg[i].update(1, 1, n, p, v, i);
                // cout << i << ' ' << seg[i].a[p] << el;
            }
        }
        else
        {
            ll l, r, k;
            cin >> l >> r >> k;
            cout << seg[k].get(1, 1, n, l, r) << el;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}