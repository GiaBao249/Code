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
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n, q;
ll a[maxn], t[4 * maxn], lazy[4 * maxn];

void push(int id, int l, int r)
{
    if(lazy[id]) {
        t[id] += lazy[id] * (r - l + 1);
        if(l != r) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}
void update(ll id, ll l, ll r,ll s, ll e, ll v)
{
    push(id, l , r);
    if(e < l || s > r) return;
    if(s <= l && e >= r) {
        lazy[id] += v;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id *2, l, mid, s, e,v);
    update(id * 2 + 1, mid + 1, r, s, e, v);
    t[id] = t[id * 2 ] + t[id *2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    push(id , l , r);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return t[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u,v);
}

void Solve()
{
    cin >> n >> q;
    f1(i,n) {
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        } else {
            int k;
            cin >> k;
            cout << get(1 , 1 , n , k , k) << el;
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
