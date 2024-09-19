#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int N = 1005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1194
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
char a[N][N];
vector<vector<int>> tmo, tp , par;
int n, m, px, py , s , e;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
string dir = "ULRD";
struct Node {
    int x, y;
};

bool win(int i, int j)
{
    return i == 1 || j == 1 || i == n || j == m;
}

void bfs1()
{
    queue<Node> q;
    f1(i, n) {
        f1(j, m) {
            if(a[i][j] == 'M')
            {
                tmo[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(sz(q)) {
        auto [r, c] = q.front();
        q.pop();
        for(int k = 0 ; k < 4 ; k++) {
            int u = r + dx[k], v = c + dy[k];
            if(u > 0 && v > 0 && u <= n && v <= m && a[u][v] != '#') {
                if(tmo[u][v] > tmo[r][c] + 1) {
                    tmo[u][v] = tmo[r][c] + 1;
                    q.push({u, v});
                }
            }
        }
    }
}

bool bfs2(int i, int j)
{
    queue<Node> q;
    q.push({i, j});
    tp[i][j] = 0;
    while(sz(q)) {
        auto [r, c] = q.front();
        q.pop();
        if(win(r, c)) {
            s = r;
            e = c;
            return true;
        }
        for(int k = 0 ; k < 4 ; k++) {
            int u = r + dx[k], v = c + dy[k];
            if(u > 0 && v > 0 && u <= n && v <= m && a[u][v] != '#') {
                if(tp[u][v] == inf && tp[r][c] + 1 < tmo[u][v]) {
                    tp[u][v] = tp[r][c] + 1;
                    par[u][v] = k;
                    q.push({u, v});
                }
            }
        }
    }
    return false;
}

void Solve()
{
    cin >> n >> m;
    tmo.resize(n + 1, vector<int>(m + 1, inf));
    tp.resize(n + 1, vector<int>(m + 1, inf));
    par.resize(n + 1, vector<int>(m + 1, -1));
    f1(i, n) {
        f1(j, m) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                px = i;
                py = j;
            }
        }
    }
    bfs1();
    if(bfs2(px , py))
    {
        cout << "YES" << el;
        string res;
        while(px != s or py != e)
        {
            int i = par[s][e];
            res += dir[i];
            s -= dx[i];
            e -= dy[i];
        }
        reverse(all(res));
        cout << sz(res) << el;
        cout << res << el;
    }else
        cout << "NO" << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
