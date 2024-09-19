#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 1e9 + 7;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1093/
*/

ll in_mod(ll a, ll m)
{
    ll res = 1;
    ll p = m - 2;
    while(p)
    {
        if(p & 1)
            res = res * a % m;
        a = a * a % m;
        p >>= 1;
    }
    return res;
}

void Solve()
{
    int n ;
    cin >> n;
    ll s = (n * (n + 1)) / 2;
    if(s & 1) {
        cout << 0;
        return;
    }
    ll target = s / 2;
    vector<vector<ll>>dp(n + 1, vector<ll>(target + 1, 0));
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(ll j = target; j >= 0 ; j--) {
            if(j >= i)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % MOD;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << (dp[n][target] * in_mod(2 , MOD) % MOD);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
