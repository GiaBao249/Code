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
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
struct Node {
    ll open, close, sum ;
} t[4 * maxn];
ll v[maxn];
string s;
int n, q;
Node operator + (Node &a, Node &b)
{
    Node ans;
    int mn = min(a.open, b.close);
    ans.open = (a.open + b.open - mn);
    ans.close = (a.close + b.close - mn);
    ans.sum = (a.sum + b.sum + mn * 2);
    return ans;
}

void build(ll id, ll l, ll r)
{
    if(l == r) {
        t[id] = {0, 0, 0};
        if(s[l] == '(')
            t[id].open = 1;
        else
            t[id].close = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2  + 1, mid + 1, r);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

Node get(ll id, ll l, ll r, ll u, ll v)
{
    if(r < u || v < l)
        return{0 , 0 , 0};
    if(u <= l && r <= v)
        return t[id];
    int mid = (l + r) / 2;
    Node t1 = get(id * 2, l, mid, u, v);
    Node t2 = get(id * 2  + 1, mid + 1, r, u, v);
    return t1 + t2;
}

void Solve()
{
    cin >> s >> q;
    n = sz(s);
    s = ' ' + s;
    build(1 , 1, n);
    while(q--) {
        int l, r ;
        cin >> l >> r;
        Node res = get(1, 1, n, l, r);
        cout << res.sum << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
