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
const ll N = 105;
const ll MOD = 1e9 + 7;
const ll L = 1e5 + 5;
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    ll n ;
    cin >> n;
    vector<ll> a(n + 1);
    ll s = 0;
    f1(i, n) {
        cin >> a[i];
        s += a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(min(L , s),0));
    dp[0][0] = 1;
    f1(i, n) {
        for(ll j = s / 2; j >= 0 ; j--) {
            if(j - a[i] >= 0 && dp[i - 1][j - a[i]])
                dp[i][j] = dp[i - 1][j - a[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    ll res = 0;
    for(ll i = s / 2 ; i >= 0 ; i--) {
        if(dp[n][i]) {
            res = i;
            break;
        }
    }
    //cout << res << el;
    cout << max(s - res, res) << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

