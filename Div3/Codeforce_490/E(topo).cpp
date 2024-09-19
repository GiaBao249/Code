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
vector<vector<int>> a;
vector<int>vis(N);
stack<int> st;
void dfs(int k)
{
    vis[k] = 1;
    for(auto x : a[k]) {
        if(!vis[x])
            dfs(x);
    }
}
void topo(int k)
{
    vis[k] = 1;
    for(auto x : a[k]) {
        if(!vis[x])
            topo(x);
    }
    st.push(k);
}
void Solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    a.resize(n + 1);
    vis.resize(n + 1, 0);
    f1(i, m) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
    }
    f1(i, n) {
        if(!vis[i])
            topo(i);
    }
    vis.assign(n + 1, 0);
    dfs(s);
    int cnt = 0;
    while(!st.empty()) {
        int t = st.top();
        st.pop();
        if(!vis[t]) {
            dfs(t);
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

