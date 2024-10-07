// Ever try ever failed no matter , try again fail again fail better!
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
const ll N = 0;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll bs(ll u, ll v, ll k)
{
    ll l = 1, r = k, m = 0;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (u - mid * v >= 0)
        {
            m = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return m;
}
void Solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    set<ll, greater<ll>> se;
    unordered_map<ll, ll> mp;
    f0(i, n)
    {
        cin >> a[i];
        mp[a[i]]++;
        se.insert(a[i]);
    }
    while (q--)
    {
        ll u, ans = 0;
        cin >> u;
        for (auto v : se)
        {
            if (v > u)
                continue;
            ll idx = bs(u, v, mp[v]);
            u -= (idx * v);
            ans += idx;
        }
        if (u != 0)
            cout << -1;
        else
            cout << ans;
        cout << el;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}