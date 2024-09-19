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
const ll N = 2e5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
vector<ll> t(N << 3, 0);
void update(ll id, ll l, ll r, ll p, ll v)
{
    if(l == r) {
        t[id] = (t[id] + v) % MOD;
        return;
    } else {
        ll mid = (l + r) >> 1;
        if(p <= mid) update(id << 1, l, mid, p, v);
        else update(id << 1 | 1, mid + 1,  r, p, v);
        t[id] = (t[id << 1] + t[id << 1 | 1]) % MOD;
    }
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if(l >= u && r <= v)
        return t[id];
    if(v < l || u > r)
        return 0;
    ll mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}
void Solve()
{
    string s;
    cin >> s;
    ll n = sz(s);
    s = " " + s;
    vector<ll> a(n + 1, 0), pre(n + 1, 0);
    f1(i, n) {
        if(s[i] == '0')
            a[i] = -1;
        else
            a[i] = 1;
        pre[i] = pre[i - 1] + a[i];
    }
    fill(t.begin(), t.end(), 0);
    ll res = 0;
    for(ll i = 0 ; i <= n ; i++) {
        ll s = get(1,1, N << 1, pre[i] + N, pre[i] + N);
        res = (res + (n - i + 1) * s) % MOD;
        update(1, 1, N << 1, pre[i] + N, (i + 1) % MOD);
        //cout << s << ' ' << res << el;
    }
    cout << res << el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t ;
    cin >> t;
    while(t--)
        Solve();
    return 0;
}

