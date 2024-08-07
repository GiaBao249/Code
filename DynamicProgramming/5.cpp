#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN 100005

ll a[3][MAXN], n, dp[3][MAXN];

void Solve()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[2][0] = a[2][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + a[1][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + a[2][i];
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 2]});
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    return 0;
}