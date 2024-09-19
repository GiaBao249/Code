///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LONG_MAX
const int N = 100005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/contest/1914/problem/D
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll a[3][N];
void Solve()
{
    int n;
    cin >> n;
    ll dp[n + 1][2][2][2] = {};
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < n; ++j) cin >> a[i][j];
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            for(int k = 0 ; k < 2 ; k++) {
                for(int l = 0 ; l < 2 ; l++) {
                    dp[i + 1][1][k][l] = max(dp[i + 1][1][k][l], dp[i][j][k][l] + a[0][i] * (j == 0));
                    dp[i + 1][j][1][l] = max(dp[i + 1][j][1][l], dp[i][j][k][l] + a[1][i] * (k == 0));
                    dp[i + 1][j][k][1] = max(dp[i + 1][j][k][1], dp[i][j][k][l] + a[2][i] * (l == 0));
                    dp[i + 1][j][k][l] = max(dp[i + 1][j][k][l], dp[i][j][k][l]);
                }
            }
        }
    }
    cout << dp[n][1][1][1] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
