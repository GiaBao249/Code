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
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n , k;
ll dp[N] , a[N] , f[N];
void Solve() {
    cin >> n >> k;
    f1(i , n) cin >> a[i];
    dp[0] = 1;
    f1(i , n){
        deque<pii> dq;
        f0(j , k + 1){
            while(sz(dq) && j - dq.front().first > a[i]){
                f[i] = (f[i] - dq.front().second + MOD) % MOD;
                dq.pop_front();
            }
            f[i] = (f[i] + dp[j]) % MOD;
            dq.pb({j , dp[j]});
            dp[j] = f[i];
            cout << i << ' ' << f[i] << el; 
        }
        for(int x = 0 ; x <= k ; x++)
            cout << x << ' ' << dp[x] << ' ';
        cout << el;
    }
    cout << dp[k] << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}