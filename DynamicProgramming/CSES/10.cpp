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
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1639/
*/
void Solve()
{
    string s, t;
    cin >> s >> t;
    int n = sz(s);
    int m = sz(t);
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1 ,0));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1 ; j <= m ; j++) {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i- 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1 , dp[i - 1][j] + 1});
        }
    }
    cout << dp[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        Solve();
    return 0;
}
