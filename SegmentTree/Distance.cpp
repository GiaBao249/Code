#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define el '\n'

vector<ll> st, a;
vector<ll> b;

void build(ll id, ll l, ll r)
{
    if (l == r)
        return st[id] = a[l], void();
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (v < l || u > r)
        return LONG_MAX;
    if (u <= l && v >= r)
        return st[id];
    ll mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void makeTree()
{
    f1(i, a.size() - 1)
    {
        auto x = lower_bound(b.begin(), b.end(), a[i]);
        long long minDis = LLONG_MAX;

        if (x != b.end())
        {
            minDis = min(minDis, abs(a[i] - *x));
        }

        if (x != b.begin())
        {
            --x;
            minDis = min(minDis, abs(a[i] - *x));
        }

        a[i] = minDis;
    }
}

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    b.resize(m);
    a.resize(n + 1);
    st.resize(4 * (n + 1));

    f1(i, n) cin >> a[i];
    f0(i, m) cin >> b[i];
    sort(b.begin(), b.end());

    makeTree();
    build(1, 1, n);
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, a.size() - 1, l, r) << el;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    return 0;
}
