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
#define inf INT_MAX >> 1
const ll N = 505;
const ll MOD = 1e9 + 7;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct Node{
    int x , y , w;
};
struct cmp1{
    bool operator() (Node &a , Node &b) const{
        return a.w > b.w;
    }
};
struct cmp2{
    bool operator() (Node &a , Node &b) const{
        return a.w < b.w;
    }
};
int dx[] = {-1 , 0 , 0 , 1};
int dy[] = {0 , -1 , 1 , 0};
int dp[N][N] , a[N][N] ,n , g , Mn;
bool vis[N][N];
int bfs1(int i , int j){
    priority_queue<Node , vector<Node> , cmp1> q;
    dp[i][j] = a[i][j];
    q.push({i , j , dp[i][j]});
    while(sz(q)){
        auto [r , c , w] = q.top();
        q.pop();
        if(w != dp[r][c]) continue;
        f0(k , 4){
            int u = r + dx[k] , v = c + dy[k];
            if(dp[u][v] > dp[r][c] + a[u][v]){
                dp[u][v] = dp[r][c] + a[u][v];
                q.push({u , v , dp[u][v]});
            }
        }
    }
    return dp[n][n];
}

void bfs2(int i , int j){
    priority_queue<Node , vector<Node> , cmp2> q;
    Mn = a[i][j]; 
    vis[i][j] = 1;
    q.push({i , j , a[i][j]});
    while(sz(q)){
        auto [r , c , w] = q.top();
        q.pop();
        Mn = min(Mn , w);
        f0(k , 4){
            int u = r + dx[k] , v = c + dy[k];
            if(u == n && v == n){
                Mn = min(Mn , a[u][v]);
                return;
            }
            if(!vis[u][v]){
                q.push({u , v , a[u][v]});
                vis[u][v] = 1;
            }
        }
    }
}

void Solve() {
    int t ; cin >> t;
    if(t == 1){
        cin >> n >> g;
        f0(i , n + 2) f0(j , n + 2){
            a[i][j] = inf;
            dp[i][j] = inf;
        }
        f1(i , n) f1(j , n){
            int x ; cin >> x;
            if(x >= g){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
        cout << bfs1(1 , 1) << el;
    }else{
        cin >> n;
        f1(i , n) f1(j , n){
            cin >> a[i][j];
        }
        bfs2(1 , 1);
        cout << Mn << el;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}