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
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll dp[N][100005];
pii a[N];
int n , w;
void Solve()
{
    cin >> n >> w;
    ll s = 0;
    f1(i , n) cin >> a[i].ff >> a[i].ss , s += a[i].ss;
    f0(i , n + 1){
        f0(j , s + 1){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    f1(i , n){
        f0(j , s + 1){
            dp[i][j] = dp[i - 1][j];
            if(a[i].ss <= j)
                dp[i][j] = min(dp[i - 1][j - a[i].ss] + a[i].ff, dp[i][j]);
        }
    }
    ll ans = 0;
    f0(i , s + 1){
        if(dp[n][i] <= w) ans = max(ans , i);
    }
    cout << ans << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}
