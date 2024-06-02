#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(a, n) for (int i = a; i <= n; i++)
int dp[10000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll dp[n + 2];
        dp[1] = 1;
        dp[0] = 1;
        For(2, n)
        {
            dp[i] = 0;
            for (int j = 1; j <= min(i, k); j++)
                dp[i] += dp[i - j];
        }
        cout << dp[n];
    }
}
