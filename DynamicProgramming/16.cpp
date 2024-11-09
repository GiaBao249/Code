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
ll dp[N][100005][2];
pii a[N];
int n, w, h;
void Solve()
{
    cin >> n >> w >> h;
    ll s = 0;
    f1(i, n) cin >> a[i].ff >> a[i].ss ,s += a[i].ss;
    f0(i, n + 1) {
        f0(j, s + 1) {
            f0(k, 2) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0; //0 la tui , 1 la tay
    f1(i, n) {
        f0(j, s + 1) {
            f0(k, 2) {
                // khong lay gi
                dp[i][j][k] = dp[i - 1][j][k];
                if(j >= a[i].ss) {
                    if(k == 0) {
                        dp[i][j][k] = min(dp[i - 1][j - a[i].ss][k] + a[i].ff, dp[i][j][k]);
                    } else {
                        if(a[i].ff <= h) {
                            dp[i][j][k] = min({dp[i][j][k], dp[i - 1][j - a[i].ss][k] + a[i].ff,
                                               dp[i - 1][j - a[i].ss][!k]});
                        } else {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i].ss][k] + a[i].ff);
                        }
                    }
                }
            }
        }
    }
//    f1(i, n) {
//        f0(j, s + 1) {
//            f0(k, 2) {
//                cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << el;
//            }
//        }
//    }
    ll ans = 0;
    f0(i, s + 1) {
        if(dp[n][i][0] <= w) {
            ans = max(ans, i);
        }
        if(dp[n][i][1] <= w) {
            ans = max(ans, i);
        }
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
