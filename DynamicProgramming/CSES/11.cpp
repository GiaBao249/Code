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
const int maxn = 505;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/

ll dp[maxn][maxn];
void Solve()
{
    int a, b;
    cin >> a >> b;
    for(int i = 1 ; i <= maxn ; i++)
    {
        for(int j = 1 ; j <= maxn ; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = inf;
                for(int k = 1 ; k < i ; k++)
                {
                    dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i - k][j] + 1);
                }
                for(int k = 1 ; k < j ; k++)
                {
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
