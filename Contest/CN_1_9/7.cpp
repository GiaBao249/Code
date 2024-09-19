#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LLONG_MAX
const int N = 200005;
const int MOD = 1e9 + 7;

ll t[4 * N];

void update(int id, int l, int r, int p, ll v)
{
    if (p < l || p > r)
        return;
    if (l == r) {
        t[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = max(t[id * 2], t[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return -inf;
    if (u <= l && r <= v)
        return t[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void Solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> dp(n + 1, 0);
    f1(i, n) {
        ll x;
        cin >> x;
        dp[i] = dp[i - 1] + x;
        update(1 , 1 , n , i , dp[i]);
    }

    ll mx = -inf;
    for (int i = 1; i <= n - a + 1; ++i) {
        int j = min(i + b - 1, n);
        mx = max(mx, get(1, 1, n, i + a - 1, j) - dp[i - 1]);
    }
    cout << mx << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
