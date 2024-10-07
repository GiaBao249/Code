#include <bits/stdc++.h>
using namespace std;

#define ll long long
using pii = pair<ll, ll>;
#define el '\n'

const ll N = 1010;
const ll MOD = 1e9 + 7;

int dx[] = {-1, 0, 0, 1};  
int dy[] = {0, -1, 1, 0};  
int a[N][N], vis[N][N], n, m;
int ans = 0;

struct Node {
    int x, y, cao;
};

bool operator<(Node a, Node b) {
    return a.cao > b.cao; 
}

void bfs() {
    queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        vis[i][1] = vis[i][m] = 1;
        q.push({i, 1});
        q.push({i, m});
    }
    for (int i = 1; i <= m; ++i) {
        vis[1][i] = vis[n][i] = 1;
        q.push({1, i});
        q.push({n, i});
    }

    while (!q.empty()) {
        auto i = q.front();
        q.pop();
        int u = i.first, v = i.second;

        for (int k = 0; k < 4; k++) {
            int x = u + dx[k], y = v + dy[k];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (!vis[x][y] && a[x][y] >= a[u][v]) {
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    priority_queue<Node> pq;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j]) {
                pq.push({i, j, a[i][j]});
            }
        }
    }

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int u = it.x, v = it.y, w = it.cao;

        for (int k = 0; k < 4; k++) {
            int x = u + dx[k], y = v + dy[k];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (!vis[x][y]) {
                vis[x][y] = 1;
                ans += max(0, (w - a[x][y])); 
                a[x][y] = max(a[x][y], w); 
                pq.push({x, y, a[x][y]}); 
            }
        }
    }
}

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(vis, 0, sizeof(vis)); 
    bfs(); 
    cout << ans << el; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve(); 
    return 0;
}
