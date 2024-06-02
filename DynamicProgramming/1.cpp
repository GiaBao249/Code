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
        int n;
        cin >> n;
        ll dp[n + 2];
        dp[1] = 1;
        dp[2] = 2;
        For(3, n)
            dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[n] << endl;
    }
}
