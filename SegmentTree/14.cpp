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
#define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll t[N << 2], lazy1[N << 2], lazy2[N << 2], a[N];
ll n, q;
void build(ll id, ll l, ll r)
{
    if(l == r) {
        t[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
void push1(ll id ,ll l, ll r)
{
    if(lazy1[id]) {
        t[id] += lazy1[id] * (r - l + 1);
        if(l != r) {
            if(lazy2[id << 1]) {
                lazy2[id << 1] += lazy1[id];
            } else {
                lazy1[id << 1] += lazy1[id];
            }
            if(lazy2[id << 1 | 1]){
                lazy2[id << 1 | 1] += lazy1[id];
            }
            else {
                lazy1[id << 1 | 1] += lazy1[id];
            }
        }
        lazy1[id] = 0;
    }
}

void push2(ll id,ll l, ll r)
{
    if(lazy2[id]) {
        t[id] = lazy2[id] * (r - l + 1);
        if(l != r) {
            lazy2[id << 1] = lazy2[id];
            lazy2[id << 1 | 1] = lazy2[id];
            lazy1[id << 1] = 0;
            lazy1[id << 1 | 1] = 0;
        }
        lazy2[id] = 0;
    }
}

void update1(ll id, ll l, ll r, ll s, ll e, ll v)
{
    push1(id, l, r);
    push2(id , l ,r);
    if(e < l || s > r) return;
    if(s <= l && e >= r) {
        lazy1[id] += v;
        push1(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update1(id << 1, l, mid, s, e, v);
    update1(id << 1 | 1, mid + 1, r, s, e, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

void update2(ll id, ll l, ll r, ll s, ll e, ll v)
{
    push1(id, l,r);
    push2(id, l,r);
    if(e < l || s > r) return;
    if(s <= l && e >= r) {
        lazy2[id] = v;
        lazy1[id] = 0;
        push2(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update2(id << 1, l, mid, s, e, v);
    update2(id << 1 | 1, mid + 1, r, s, e, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    push1(id, l, r);
    push2(id, l, r);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return t[id];
    ll mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r,u,v);
}

void Solve()
{
    cin >> n >> q;
    f1(i, n) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            update1(1, 1, n, l, r, x);
        }
        if(t == 2) {
            ll l, r, v;
            cin >> l >> r >> v;
            update2(1, 1, n, l, r, v);
        }
        if(t == 3) {
            ll l, r;
            cin >> l >> r;
            cout << get(1,1, n, l, r) << el;
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

