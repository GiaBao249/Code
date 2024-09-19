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
const ll N = 200005;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    int n,  k ;
    cin >> n >> k;
    vector<ll> a(n);
    f0(i, n) cin >> a[i];
    vector<ll> dp(n + 1 , 0);
    dp[0] = a[0];
    For(i , 1 , n){
        dp[i] = dp[i - 1] + a[i];
    }
    ll mx = k , mn = 0;
    f0(i , n){
        mx = min(mx , k - dp[i]);
        mn = max(mn , -dp[i]);
        if(mn > mx){
            cout << 0 << el;
            return;
        }
    }
    cout << mx - mn + 1 << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}


