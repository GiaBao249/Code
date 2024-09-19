#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 200005;
const int MOD = 1e9 + 7;

/*
 /\_/\
(= >_<)
/ >  \> http://upcoder.xyz/'index.php/b0e137b6aca029f155de443188816529eccffb6bae3b0ed3dd2ced81cfc639ee/nwuTF''0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'7974'9-ge?aOh9.9_9@hD~Ch7l8e9-?5_h9Lh6/e185607b6d68aa9a1aef9c1a079c527c57796cea5baaed97457a17e094399e33
*/

struct Node {
    ll id, idx;
    bool operator<(const Node &other) const
    {
        return id < other.id;
    }
} t[4 * maxn];

ll a[maxn], s[4 * maxn];
int n, q;

void update(ll id, ll l, ll r, ll p, ll v)
{
    if (p < l || p > r) return;
    if (l == r) {
        t[id] = {v, l};
        s[id] = v;
        a[p] = v;
        return;
    }
    ll mid = (l + r) >> 1;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = min(t[id * 2], t[id * 2 + 1]);
    s[id] = s[id * 2] + s[id * 2 + 1];
}

Node getMin(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r < u) return {inf, -1};
    if (l >= u && r <= v) return t[id];
    ll mid = (l + r) >> 1;
    Node t1 = getMin(id * 2, l, mid, u, v);
    Node t2 = getMin(id * 2 + 1, mid + 1, r, u, v);
    return min(t1, t2);
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return s[id];
    ll mid = (l + r) >> 1;
    ll s1 = get(id * 2, l, mid, u, v);
    ll s2 = get(id * 2 + 1, mid + 1, r, u, v);
    return s1 + s2;
}

ll change(ll p, ll k)
{
    return ((p - 1 + (n - k)) % n) + 1;
}

void Solve()
{
    cin >> n >> q;
    f1(i, n) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    ll pos = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll k;
            cin >> k;
            pos = (pos + k) % n;
        } else if (t == 2) {
            ll l, r, val;
            cin >> l >> r >> val;
            ll u = change(l, pos), v = change(r, pos);
            if (u <= v) {
                Node x = getMin(1, 1, n, u, v);
                update(1, 1, n, x.idx, val);
            } else {
                Node x1 = getMin(1, 1, n, u, n);
                Node x2 = getMin(1, 1, n, 1, v);
                Node x = min(x1, x2);
                update(1, 1, n, x.idx, val);
            }
        } else {
            int l, r;
            cin >> l >> r;
            ll u = change(l, pos), v = change(r, pos);
            if (u <= v) {
                cout << get(1, 1, n, u, v) << el;
            } else {
                cout << (get(1, 1, n, u, n) + get(1, 1, n, 1, v)) << el;
            }
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
