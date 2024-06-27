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
    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
    if (a[0] == 0)
        dp[1][0] = 1;
    else if (a[0] == 1)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else if (a[0] == 2)
    {
        dp[1][0] = 1;
        dp[1][2] = 0;
    }
    else if (a[0] == 3)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (a[i - 1] == 1 || a[i - 1] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);

        if (a[i - 1] == 2 || a[i - 1] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
}
int main()
{
    Solve();
    return 0;
}