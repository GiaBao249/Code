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
#define inf 2000000000000000000;
const ll N = 505;
const ll MOD = 1e9 + 7;
 
void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
const ll oo = 2000000000000000000;
ll n, m ,q;
ll a[N][N];
void Solve() {
    cin >> n >> m >> q;
    f1(i , n){
        f1(j , n){
            a[i][j] = oo;
        }
    }
 
    f1 (i , n){
        a[i][i] = 0;
    }
    
    f1(i , m){
        ll u , v , w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = min(w , a[u][v]);
    }
    f1(k , n){
        f1(u , n){
            f1(v, n){
                a[u][v] = min(a[u][v] , a[u][k] + a[k][v]);
            }
        }
    }
    f1(i , q){
        ll x , y;
        cin >> x >> y;
        if(a[x][y] == oo){
            cout << -1 << el;
        }
        else{
            cout << a[x][y] << el;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}
