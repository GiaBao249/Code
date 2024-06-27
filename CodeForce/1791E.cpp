#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = -a[0];
    for (int i = 1; i < n - 1; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] - a[i]);
        dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1] + a[i]);
    }
    dp[n - 1][0] = max(dp[n - 2][0] + a[n - 1], dp[n - 2][1] - a[n - 1]);
    cout << dp[n - 1][0] << endl;
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