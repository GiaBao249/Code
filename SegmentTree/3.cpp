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
/ >  \> https://codeforces.com/gym/458672/problem/D
*/
struct Node {
    ll pre, suf, mx, sum;
} t[4 * maxn];
int n, q;
int v[maxn];

Node operator + (Node &a, Node &b)
{
    Node ans;
    ans.sum = a.sum + b.sum;
    ans.pre = max(a.pre, b.pre + a.sum);
    ans.suf = max(a.suf + b.sum, b.suf);
    ans.mx = max({a.mx, b.mx, a.suf + b.pre});
    return ans;
}

void update(ll id, ll l, ll r, ll p, ll v)
{
    if(p < l || p > r)
        return;
    if(l == r) {
        t[id] = {max(0LL, v), max(0LL,v), max(0LL, v) , v};
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

void Solve()
{
    cin >> n >> q;
    f1(i,n) {
        cin >> v[i];
        update(1, 1, n, i, v[i]);
    }
    while(q--) {
        ll u, v;
        cin >> u >> v;
        update(1, 1, n, u,v);
        cout << t[1].mx << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
