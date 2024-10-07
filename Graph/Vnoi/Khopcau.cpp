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
const ll N = 5e4 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

vector<int> a[N];
int bridge = 0, low[N], num[N], t = 0;
int cnt[N];
int n, m;
void dfs(int u, int pre)
{
    int ch = 0;
    num[u] = low[u] = ++t;
    for (auto v : a[u])
    {
        if (v == pre)
            continue;
        if (!num[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                bridge++;
            ch++;
            if (u == pre)
            {
                if (ch > 1)
                    cnt[u] = 1;
            }
            else if (low[v] >= num[u])
                cnt[u] = 1;
        }
        else
            low[u] = min(low[u], num[v]);
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
        a[v].pb(u);
    }
    f1(i, n)
    {
        dfs(i, i);
    }
    int j = 0;
    f1(i, n)
        j += cnt[i];
    cout << j << ' ' << bridge << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}