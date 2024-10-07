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
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
// https://oj.vnoi.info/problem/segtree_itmix
void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll t[N << 2], a[N], lazy1[N << 2], lazy2[N << 2], lazy3[N << 2];
ll n, q;
void build(ll id, ll l, ll r)
{
    lazy2[id] = 1;
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = (t[id << 1] + t[id << 1 | 1]) % MOD;
}

void push1(ll id, ll l, ll r)
{
    if (lazy1[id])
    {
        t[id] = (t[id] + ((lazy1[id] % MOD) * (r - l + 1)) % MOD) % MOD;
        if (l != r)
        {
            if (lazy3[id << 1])
            {
                lazy3[id << 1] += lazy1[id];
            }
            else
            {
                lazy1[id << 1] += lazy1[id];
            }
            if (lazy3[id << 1 | 1])
            {
                lazy3[id << 1 | 1] += lazy1[id];
            }
            else
            {
                lazy1[id << 1 | 1] += lazy1[id];
            }
        }
        lazy1[id] = 0;
    }
}

void push2(ll id, ll l, ll r)
{
    if (lazy2[id] != 1)
    {
        t[id] = (t[id] * lazy2[id]) % MOD;
        if (l != r)
        {
            if (lazy3[id << 1])
            {
                lazy3[id << 1] = (lazy2[id] * lazy3[id << 1]) % MOD;
            }
            else
            {

                if (lazy1[id << 1])
                {
                    if (lazy2[id << 1] != 1)
                    {
                        push2(id << 1, l, ((l + r) >> 1));
                        push1(id << 1, l, (l + r) >> 1);
                        lazy2[id << 1] = lazy2[id];
                    }
                    else
                    {
                        push1(id << 1, l, (l + r) >> 1);
                        lazy2[id << 1] = lazy2[id];
                    }
                }
                else
                {
                    lazy2[id << 1] = (lazy2[id << 1] * lazy2[id]) % MOD;
                }
            }

            if (lazy3[id << 1 | 1])
            {
                lazy3[id << 1 | 1] = (lazy2[id] * lazy3[id << 1 | 1]) % MOD;
            }
            else
            {
                if (lazy1[id << 1 | 1])
                {
                    if (lazy2[id << 1 | 1] != 1)
                    {
                        push2(id << 1 | 1, ((l + r) >> 1) + 1, r);
                        push1(id << 1 | 1, ((l + r) >> 1) + 1, r);
                        lazy2[id << 1 | 1] = lazy2[id];
                    }
                    else
                    {
                        push1(id << 1 | 1, ((l + r) >> 1) + 1, r);
                        lazy2[id << 1 | 1] = lazy2[id];
                    }
                }
                else
                {
                    lazy2[id << 1 | 1] = (lazy2[id << 1 | 1] * lazy2[id]) % MOD;
                }
            }
        }
        lazy2[id] = 1;
    }
}

void push3(ll id, ll l, ll r)
{
    if (lazy3[id])
    {
        t[id] = (lazy3[id] * (r - l + 1)) % MOD;
        if (l != r)
        {
            lazy3[id << 1] = lazy3[id];
            lazy3[id << 1 | 1] = lazy3[id];
            lazy2[id << 1] = 1;
            lazy2[id << 1 | 1] = 1;
            lazy1[id << 1] = 0;
            lazy1[id << 1 | 1] = 0;
        }
        lazy3[id] = 0;
    }
}

void update(ll id, ll l, ll r, ll s, ll e, ll v, ll th)
{
    push3(id, l, r);
    push2(id, l, r);
    push1(id, l, r);
    if (e < l || s > r)
        return;
    if (s <= l && r <= e)
    {
        if (th == 1)
        {
            lazy1[id] = v;
            push1(id, l, r);
        }
        else if (th == 2)
        {
            lazy2[id] = v;
            push2(id, l, r);
        }
        else
        {
            lazy3[id] = v;
            push3(id, l, r);
        }
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1, l, mid, s, e, v, th);
    update(id << 1 | 1, mid + 1, r, s, e, v, th);
    t[id] = (t[id << 1] + t[id << 1 | 1]) % MOD;
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    push3(id, l, r);
    push2(id, l, r);
    push1(id, l, r);
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
        return t[id];
    ll mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

void Solve()
{
    cin >> n >> q;
    f1(i, n) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        ll t, l, r, v;
        cin >> t;
        if (t == 1)
        {
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v, t);
        }
        if (t == 2)
        {
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v, t);
        }
        if (t == 3)
        {
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v, t);
        }
        if (t == 4)
        {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << el;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // file();
    Solve();
    return 0;
}
