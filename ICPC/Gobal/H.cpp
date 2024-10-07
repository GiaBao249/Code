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
ll n, q;
struct ST
{
    vector<ll> t, a;
    void build(ll id, ll l, ll r)
    {
        if (l == r)
        {
            t[id] = a[l] * a[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    void init(vector<ll> &_a)
    {
        a = _a;
        t.resize(sz(a) << 2);
        build(1, 0, sz(a) - 1);
    }

    void update(ll id, ll l, ll r, ll p, ll v)
    {
        if (p < l || p > r)
            return;
        if (l == r)
        {
            a[p] += v;
            t[id] = a[p] * a[p];
            return;
        }
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, p, v);
        update(id << 1 | 1, mid + 1, r, p, v);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
        {
            return t[id];
        }
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
};
ST seg[N];
ll a[N];
vector<ll> v[N];
void Solve()
{
    cin >> n >> q;
    f1(i, n)
    {
        cin >> a[i];
        v[a[i]].pb(i);
    }
    f1(i, n)
    {
        if (v[i].size())
        {
            seg[i].init(v[i]);
            // cout << i << ' '<<seg[i].t[1] << el;
        }
    }
    ll last = 0;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p;
            cin >> p;
            p = (p + last - 1) % (n - 1) + 1;
            auto u = lower_bound(seg[a[p]].a.begin(), seg[a[p]].a.end(), p) - seg[a[p]].a.begin();
            seg[a[p]].update(1, 0, seg[a[p]].a.size() - 1, u, 1);
            auto v = lower_bound(seg[a[p + 1]].a.begin(), seg[a[p + 1]].a.end(), p + 1) - seg[a[p + 1]].a.begin();
            seg[a[p + 1]].update(1, 0, seg[a[p + 1]].a.size() - 1, v, -1);
            swap(a[p], a[p + 1]);
        }
        if (t == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l = (l + last - 1) % n + 1;
            r = (r + last - 1) % n + 1;
            x = (x + last - 1) % n + 1;
            // cout << l << ' ' << r << ' ' << x << el;
            if (l > r)
                swap(l, r);
            if (v[x].size())
            {
                auto u = lower_bound(seg[x].a.begin(), seg[x].a.end(), l) - seg[x].a.begin();
                auto v = upper_bound(seg[x].a.begin(), seg[x].a.end(), r) - seg[x].a.begin();
                --v;
                last = seg[x].get(1, 0, seg[x].a.size() - 1, u, v);
                cout << last << el;
            }
            else
            {
                last = 0;
                cout << 0 << el;
            }
        }
        if (t == 3)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            // cout << last << el;
            l = (l + last - 1) % n + 1;
            r = (r + last - 1) % n + 1;
            x = (x + last - 1) % n + 1;
            if (l > r)
                swap(l, r);
            // cout << l << ' ' << r << ' ' << x << el;
            if (v[x].size())
            {
                last = seg[x].get(1, 0, seg[x].a.size() - 1, l - 1, r - 1);
                cout << last << el;
            }
            else
            {
                last = 0;
                cout << 0 << el;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
