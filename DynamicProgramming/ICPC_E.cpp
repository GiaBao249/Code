//Ever try ever failed no matter , try again fail again fail better!
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
#define MAX INT_MAX
#define ff first
#define ss second
const ll N = 105;
const ll S = 16;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node {
    int x,y;
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
ll dist[S][N][N], dp[N][1 << S];
char a[N][N];
int sx[S], sy[S];
int n, m, s;
void bfs(int id)
{
    queue<Node> q;
    q.push({sx[id], sy[id]});
    while(sz(q)) {
        auto [r, c] = q.front();
        q.pop();
        f0(k, 4) {
            int u = r + dx[k];
            int v = c + dy[k];
            if(u < 0 || u >= n || v < 0 || v >= m) continue;
            if(a[u][v] == '#') continue;
            if(dist[id][u][v] >= inf) {
                dist[id][u][v] = dist[id][r][c] + 1;
                q.push({u, v});
            }
        }
    }
}

void Solve()
{
    cin >> n >> m >> s;
    int id = 1;
    sx[0] = 0, sy[0] = 0;
    f0(i, n) {
        f0(j, m) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                sx[id] = i;
                sy[id] = j;
                id++;
            }
        }
    }
    f0(i , id){
        f0(j, n) {
            f0(k, m) {
                dist[i][j][k] = inf;
            }
        }
        dist[i][sx[i]][sy[i]] = 0;
        bfs(i);
    } 
    f0(mask , 1 << s){
        f0(i , s){
            dp[i][mask] = inf;
        }
    }
    f0(i , s){
        dp[i][1 << i] = dist[0][sx[i + 1]][sy[i + 1]];
    }
    f0(mask , 1 << s){
        f0(i , s){
            if(dp[i][mask] >= inf) continue;
            f0(j , s){
                if((1 << j) & mask) continue;
                dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], 
                    dp[i][mask] + dist[i + 1][sx[j + 1]][sy[j + 1]]);
                //cout << dp[j][mask | (1 << j)] << el;
            }
        }
    }
    ll ans = inf;
    f0(i , s) ans = min(ans , dp[i][(1 << s) - 1]);
    if(ans >= inf) cout << -1 << el;
    else cout << ans << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
