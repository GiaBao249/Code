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
ll t[N << 2], lz[N << 2][2];
bool f[N << 2];
void build(ll id, ll l, ll r)
{
    f[id] = 0;
    lz[id][0] = 0;
    lz[id][1] = 0;
    if (l == r)
    {
        t[id] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = (t[id << 1] + t[id << 1 | 1]);
}

ll cal(ll x)
{
    return (x * (x - 1) / 2);
}

void push(ll id, ll l, ll r)
{
    if (f[id])
    {
        ll k = r - l + 1;
        t[id] = (t[id] + lz[id][1] * k + cal(k) * lz[id][0]) % MOD;
        if (l != r)
        {
            ll mid = (l + r) >> 1;
            lz[id << 1][0] = (lz[id << 1][0] + lz[id][0]) % MOD;
            lz[id << 1 | 1][0] = (lz[id << 1 | 1][0] + lz[id][0]) % MOD;
            lz[id << 1][1] = (lz[id << 1][1] + lz[id][1]) % MOD;
            lz[id << 1 | 1][1] = (lz[id << 1 | 1][1] + lz[id][1] + lz[id][0] * (mid - l + 1) % MOD) % MOD;
            f[id << 1] = f[id << 1 | 1] = 1;
        }
        lz[id][0] = 0;
        lz[id][1] = 0;
        f[id] = false;
    }
}

void update(ll id, ll l, ll r, ll u, ll v, ll x, ll y)
{
    push(id, l, r);
    if (u > r || v < l)
        return;
    if (l >= u && r <= v)
    {
        lz[id][0] = (lz[id][0] + x) % MOD;
        lz[id][1] = (lz[id][1] + (y + ((l - u) * x) % MOD) % MOD) % MOD;
        f[id] = true;
        push(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, x, y);
    update(id << 1 | 1, mid + 1, r, u, v, x, y);
    t[id] = (t[id << 1] + t[id << 1 | 1]) % MOD;
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    push(id, l, r);
    if (u > r || l > v)
        return 0;
    if (l >= u && r <= v)
        return t[id];
    ll mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

void Solve()
{
    cin >> n >> q;
    build(1, 1, n);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            update(1, 1, n, l, r, a, b);
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