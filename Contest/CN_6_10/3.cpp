///Ever try ever failed no matter, try again fail again fail better!
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
const ll N = 1e3 + 5;
const ll MOD = 1e9 + 7;

int dx[] = {-1 , 0 , 0 , 1};
int dy[] = {0 , -1 , 1 , 0};

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct Node{
    int c , x , y;
    bool operator>(const Node& other) const {
        return c > other.c;
    }
};

int n; 
int a[N][N] , vis[N][N];
int dijkstra(int mid){
    int w[n][n];
    f0(i , n){
        f0(j , n){
            if(a[i][j] >= mid){
                w[i][j] = 0;
            }else{
                w[i][j] = 1;
            }
            vis[i][j] = 0;
        }
    }
    int d[n][n];
    priority_queue<Node , vector<Node> , greater<Node>> pq;
    f0(i ,n){
        f0(j , n)
            d[i][j] = inf;
    }
    d[0][0] = 0;
    vis[0][0] = 1;
    pq.push({0 , 0 , 0});
    while(pq.size()){
        auto i = pq.top();
        pq.pop();
        int c = i.c , u = i.x , v = i.y;
        if(c != d[u][v]){
            continue;
        }
        f0(k , 4){
            int x = u + dx[k] , y = v + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && d[x][y] > d[u][v] + w[x][y]){
                d[x][y] = d[u][v] + w[x][y];
                pq.push({d[x][y] , x , y});
                vis[x][y] = 1;
            }
        }
    }
    return d[n - 1][n - 1];
}

void Solve() {
    cin >> n;
    f0(i , n){
        f0(j , n){
            cin >> a[i][j];
        }
    }
    int l = 0 , r = 1e6;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(dijkstra(mid) == 0){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    int t=1;
    while(t--)
    Solve();
    return 0;
}
