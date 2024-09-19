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
#define inf INT_MAX
const ll N = 200005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, k;
ll a[N];
vector<ll> t(4 * N);
void update(int id, int l, int r, int p, ll v)
{
    if (p < l || p > r)
        return;
    if (l == r)
    {
        t[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

ll get(int id, int l, int r, int u, ll v)
{
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
        return t[id];
    int mid = (l + r) / 2;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return t1 + t2;
}

void Solve()
{
    cin >> n >> k;
    f1(i, n)
    {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    ll mx = k, mn = 0;
    f1(i, n)
    {
        ll x = get(1, 1, n, 1, i);
        mx = min(mx, k - x);
        mn = max(mn, -x);
        if (mn > mx)
        {
            cout << 0 << el;
            return;
        }
    }
    cout << mx - mn + 1 << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
