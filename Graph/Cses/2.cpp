#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vl = vector<ll>;
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 1005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
struct Node {
    int x, y;
};
char a[maxn][maxn];
vector<vl> d(maxn, vl(maxn, 0)), pre(maxn, vl(maxn, 0));
int n, m;
int xa, xb, ya, yb;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
string dir = "ULRD";
void bfs(int i, int j)
{
    queue<Node> q;
    q.push({i, j});
    d[i][j] = 1;
    while(sz(q)) {
        auto [u, v] = q.front();
        q.pop();
        For(k, 0, 3) {
            int nu = u + dx[k];
            int nv = v + dy[k];
            if(nu > 0 && nv > 0 && nu <= n && nv <= m && a[nu][nv] != '#' && !d[nu][nv]) {
                d[nu][nv] = 1;
                pre[nu][nv] = k;
                q.push({nu,nv});
            }
        }
    }
}
void Solve()
{
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                xa = i, ya = j;
            }
            if(a[i][j] == 'B') {
                xb = i, yb = j;
            }
        }
    }
    bfs(xa, ya);
    if(d[xb][yb]) {
        cout << "YES" << el;
        string res ;
        while(xa != xb || ya != yb) {
            int i = pre[xb][yb];
            res += dir[i];
            xb -= dx[i];
            yb -= dy[i];
        }
        reverse(all(res));
        cout << sz(res) << el;
        cout << res << el;
    } else {
        cout << "NO" << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
