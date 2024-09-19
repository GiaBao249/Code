///Ever try ever failed no matter , try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
using vi = vector<ll>;
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
const ll N = 5005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

vector<vi> a(N);
int vd[N], vb[N];
int n, m, s;
priority_queue<pii> p;
void dfs(int u)
{
    vd[u] = 1;
    for(int v : a[u]) {
        if(!vd[v])
            dfs(v);
    }
}

void bfs(int u)
{
    int c = 0;
    queue<int> q;
    q.push(u);
    vb[u] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x : a[v]) {
            if(vd[x])
                continue;
            if(!vb[x]) {
                c++;
                vb[x] = 1;
                q.push(x);
            }
        }
    }
    p.push({c, u});
}

void Solve()
{
    cin >> n >> m >> s;
    CLR(vb, 0);
    CLR(vd, 0);
    f1(i, m) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
    dfs(s);
    f1(i, n) {
        if(!vd[i]) {
            CLR(vb , 0);
            bfs(i);
        }
    }
    int cnt = 0;
    while(!p.empty()) {
        auto u = p.top();
        p.pop();
        int se = u.second;
        if(!vd[se]) {
            dfs(se);
            cnt++;
        }
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

