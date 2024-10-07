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
ll t[N << 2], a[N], lz[N << 2], f[N << 2];
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
void push(ll id, ll l, ll r)
{
    if (lz[id])
    {
        ll k = (r - l + 1);
        t[id] += (lz[id] * k + f[id] * (k * (k - 1)) / 2);
        if (l != r)
        {
            lz[id << 1] += lz[id];
            lz[id << 1 | 1] += lz[id] + (((l + r) >> 1) - l + 1) * f[id];
            f[id << 1] += f[id];
            f[id << 1 | 1] += f[id];
        }
        lz[id] = 0;
        f[id] = 0;
    }
}
void add(ll id, ll l, ll r, ll x)
{
    ll k = (r - l + 1);
    t[id] += (x * k + (k * (k - 1) / 2));
    if (l != r)
    {
        lz[id << 1] += x;
        lz[id << 1 | 1] += x + ((l + r >> 1) - l + 1);
        f[id << 1]++;
        f[id << 1 | 1]++;
    }
}
void update(ll id, ll l, ll r, ll u, ll v, ll x)
{
    push(id, l, r);
    if (u > r || l > v)
        return;
    if (u <= l && r <= v)
    {
        add(id, l, r, x);
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, x);
    update(id << 1 | 1, mid + 1, r, u, v, x + max(0LL, mid - max(l, u) + 1));
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    push(id, l, r);
    if (u > r || v < l)
        return 0;
    if (u <= l && r <= v)
        return t[id];
    ll mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

void Solve()
{
    cin >> n >> q;
    f1(i, n) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll l, r;
            cin >> l >> r;
            update(1, 1, n, l, r, 1);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << el;
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