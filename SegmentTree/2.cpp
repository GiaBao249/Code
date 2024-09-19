#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf 1e18
const ll maxn = 200005;
const ll MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> Tìm 2 số lớn nhất trong đoạn l , r và tích
*/
struct Node {
    ll x, y;
};
ll a[maxn];
Node t[4 * maxn] ;
ll n, q;
vector<ll> v;

Node findNode(Node &a, Node &b)
{
    vector<ll> v;
    v.push_back(a.x);
    v.push_back(a.y);
    v.push_back(b.x);
    v.push_back(b.y);
    Node res;
    sort(all(v), greater<ll>());
    res.x = v[0];
    res.y = v[1];
    return res;
}

ll Mul(ll a, ll b, ll mod)
{
    a = a % mod;
    ll res = 0;
    while(b > 0) {
        if(b & 1) {
            res = (res + a) % mod;
        }
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

void build(ll id, ll l, ll r)
{
    if(l == r) {
        t[id].x = a[l];
        t[id].y = 1;
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2  + 1, mid + 1, r);
    t[id] = findNode(t[id * 2], t[id * 2 + 1]);
}

Node get(ll id, ll l, ll r, ll u, ll v)
{
    if(r < u || v < l)
        return {(ll)-inf,1};
    if(u <= l && r <= v)
        return t[id];
    ll mid = (l + r) / 2;
    Node t1 = get(id * 2, l, mid, u, v);
    Node t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return findNode(t1, t2);
}

void update(ll id, ll l, ll r,ll pos, ll val)
{
    if(pos < l || pos > r)
        return;
    if(l == r) {
        t[id].x = val;
        t[id].y = 1;
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2  + 1, mid + 1, r, pos, val);
    t[id] = findNode(t[id * 2], t[id * 2 + 1]);
}

void Solve()
{
    cin >> n ;
    f1(i,n) cin >> a[i];
    a[0] = 1;
    build(1, 1, n);
    cin >> q;
    while(q--) {
        ll t ;
        cin >> t;
        if(t == 0) {
            ll u, v ;
            cin >> u >> v;
            update(1, 1, n, u, v);
        } else {
            ll l, r, mod ;
            cin >> l >> r >> mod;
            Node res = get(1, 1, n, l, r);
            //cout << res.x << " " << res.y << el;
            cout << Mul(res.x, res.y, mod) << el;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
