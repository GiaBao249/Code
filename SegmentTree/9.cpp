#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 200005;
const ll MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node {
    ll sum , pre;
};
ll n, q;
vector<ll> a(N) ;
vector<Node> t(4 * N);
Node operator + (const Node &a, const Node &b)
{
    return {a.sum + b.sum, max(a.pre, a.sum + b.pre)};
}
void update(ll id, ll l, ll r, ll p, ll v)
{
    if(p < l || p > r) {
        return;
    }
    if(l == r) {
        t[id] = {v, v};
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

Node get(ll id, ll l, ll r, ll u, ll v)
{
    if(l > v || r < u)
        return {0 , 0};
    if(u <= l && v >= r)
        return t[id];
    ll mid = (l + r) / 2;
    Node t1 = get(id * 2, l, mid, u, v);
    Node t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return t1 + t2;
}

void Solve()
{
    cin >> n >> q;
    f1(i, n) {
        cin >> a[i];
        update(1 , 1, n , i , a[i]);
    }
    while(q--) {
        ll t ;
        cin >> t;
        if(t == 1) {
            ll p, k;
            cin >> p >> k;
            update(1, 1, n, p, k);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << max(0LL , get(1, 1, n, l, r).pre) << el;
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
