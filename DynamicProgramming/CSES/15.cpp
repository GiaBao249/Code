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
#define MAX INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll dp[N];
int n;
struct Node{
    ll u , v , w;
};
bool cmp (Node &a , Node &b){
    return a.v < b.v; 
}
vector<Node> a;
vector<pii> b;
void Solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    f0(i , n){
        ll u , v , w;
        cin >> u >> v >> w;
        a[i] = {u , v, w};
    }
    sort(all(a), cmp);
    dp[0] = a[0].w;
    f0(i ,n) b[i] = {a[i].v , a[i].w};
    f1(i , n - 1){
        auto u = upper_bound(all(b) , pii(a[i].u , 0));
        if(u != b.begin()){
            --u;
            ll idx = u - b.begin();
            dp[i] = max(dp[i - 1] , dp[idx] + a[i].w);
        }else dp[i] = max(dp[i - 1] , a[i].w);
    }
    cout << dp[n - 1] << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
