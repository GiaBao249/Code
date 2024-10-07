/// Ever try ever failed no matter , try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll, ll>;
#define pb push_back
#define CLR(a, b) memset((a), b, sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll) x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 1005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct Node
{
    int x, y;
};
int n, m;
char a[N][N];
int par[N][N];
string dir = "ULRD";
int time1[N][N], time2[N][N];
bool win(int i, int j)
{
    return (i == 1 || j == 1 || i == n || j == m);
}

int s, e;
bool bfs1(int i, int j)
{
    queue<Node> q;
    q.push({i, j});
    time1[i][j] = 0;
    while (q.size())
    {
        auto [u, v] = q.front();
        q.pop();
        if (win(u, v))
        {
            s = u, e = v;
            return true;
        }
        int before = time1[u][v] + 1;
        for (int k = 0; k < 4; k++)
        {
            int uu = u + dx[k], vv = v + dy[k];
            if (a[uu][vv] == '.' && time1[uu][vv] == inf && before < time2[uu][vv])
            {
                time1[uu][vv] = before;
                par[uu][vv] = k;
                q.push({uu, vv});
            }
        }
    }
    return false;
}
void bfs2()
{
    queue<Node> q;
    f1(i, n)
    {
        f1(j, m)
        {
            if (a[i][j] == 'M')
            {
                time2[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (q.size())
    {
        auto [u, v] = q.front();
        q.pop();
        int before = time2[u][v] + 1;
        for (int k = 0; k < 4; k++)
        {
            int uu = u + dx[k], vv = v + dy[k];
            if (a[uu][vv] == '.' && time2[uu][vv] > before)
            {
                time2[uu][vv] = before;
                q.push({uu, vv});
            }
        }
    }
}

void Solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            time1[i][j] = inf;
            time2[i][j] = inf;
            a[i][j] = '#';
        }
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    bfs2();
    if (bfs1(x, y))
    {
        cout << "YES" << el;
        string ans;
        while (s != x || e != y)
        {
            int i = par[s][e];
            ans += dir[i];
            s -= dx[i];
            e -= dy[i];
        }
        reverse(all(ans));
        cout << sz(ans) << el;
        cout << ans << el;
    }
    else
        cout << "NO" << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}