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
    int m;
    cin >> m;
    vector<int> b(m);
    for (int &x : b)
        cin >> x;

    ll res = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INT_MIN));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i < n)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
            if (j < m)
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j]);
            res = max(res, 1LL * dp[i][j]);
        }
    }
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}