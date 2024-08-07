#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), dp(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 0;
    dp[1] = a[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 1]);
    }

    cout << min(dp[n], dp[n - 1]) << endl;
}

int main()
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
