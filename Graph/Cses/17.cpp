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
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int n, m;
vector<int> a[N];
int vis[N], dp[N];
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : a[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        dp[u] = (dp[u] + dp[v]) % MOD;
    }
}
void Solve()
{
    cin >> n >> m;
    f1(i, m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
    CLR(vis, 0);
    dp[n] = 1;
    dfs(1);
    cout << dp[1] << el;
    // f1(i, n) cout << dp[i] << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}