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
const int maxn = 5e4 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1097/
*/
void Solve()
{
    int n ;
    cin >> n;
    vector<ll> a(n + 1 , 0);
    vector<vector<ll>> dp(n + 1 , vector<ll>(n + 1 ,0));
    ll sum = 0;
    For(i, 1, n + 1){
         cin >> a[i];
         sum += a[i];
         if(i >= 3)
            dp[i][i] = a[i];
    }
    dp[1][1] = a[1];
    if(n == 1){
        cout << dp[1][1] << el;
        return;
    }
    dp[2][2] = max(a[1] , a[2]);
    for(int i = n  ; i >= 1; i--)
    {
        for(int j = i + 1; j <= n ; j++)
        {
            dp[i][j] = max(a[j] - dp[i][j - 1] , a[i] - dp[i + 1][j]);
        }
    }
    cout << ((dp[1][n] + sum) / 2) << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
