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
const ll N = 2005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node {
    int l, r;
    bool v;
};

bool cmp(Node &a, Node &b)
{
    return a.l < b.l;
}
void Solve()
{
    int a, m, n;
    cin >> a >> m >> n;
    ll dp[N];
    for (int i = 1; i < 2005; i++) {
        dp[i] = inf;
    }
    pii v[m + 1];
    pii u[n + 1];
    f1(i, m) {
        cin >> v[i].first >> v[i].second;
    }
    f1(i, n) cin >> u[i].first >> u[i].second;
    sort(u + 1, u + n + 1);
    sort(v + 1, v + m + 1);
    if (u[1].first > v[1].first) {
        cout << -1 << el;
        return;
    }
    map<ll, ll> mp, r;
    for (int i = 1; i <= m; i++) {
        for (int j = v[i].first; j < v[i].second; j++) {
            r[j] = 1;
        }
    }
    f1(i, n) {
        if (!mp[u[i].first]) {
            mp[u[i].first] = u[i].second;
        } else {
            mp[u[i].first] = min(mp[u[i].first], u[i].second);
        }
    }
    for (int i = 1; i <= a; i++) {
        if (!r[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            for (int j = i - 1; j >= 0; j--) {
                if (mp[j]) {
                    dp[i] = min(dp[i], dp[j] + (i - j) * mp[j]);
                }
            }
        }
    }
    cout << dp[a] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
