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
const ll N = 2510;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct Edge{
    ll u , v , w;
};
ll n,  m;
ll d[N] , par[N] ;
vector<ll> path;
vector<Edge> a;

void Bellman_ford(ll u){
    d[u] = 0 ;
    ll x;
    f0(i , n){
        x = -1;
        f0(j , m){
            if(d[a[j].u] < inf){
                if(d[a[j].v] > d[a[j].u] + a[j].w){
                    d[a[j].v] = max(-inf , 1LL * d[a[j].u] + a[j].w);
                    par[a[j].v] = a[j].u;
                    x = a[j].v;
                }
            }
        }
    }
    if(x == -1){
            cout << "NO" << el;
            return;
    }
    ll y = x;
    f0(i , n) {
        y = par[y];
    }
    for(ll cur = y ; ; cur = par[cur]){
        path.pb(cur);
        if(cur == y && sz(path) > 1){
            break;
        }
    }
    reverse(all(path));
    cout << "YES" << el;
    for(auto x : path){
        cout << x << ' ';
    }
}   
void Solve() {
    cin >> n >> m;
    f1(i , m){
        ll u , v , w;
        cin >> u >> v >> w;
        a.pb({u , v, w});
    }
    Bellman_ford(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}