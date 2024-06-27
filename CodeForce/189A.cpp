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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] != -1)
        {
            if (i + a <= n)
                dp[i + a] = max(dp[i + a], dp[i] + 1);
            if (i + b <= n)
                dp[i + b] = max(dp[i + b], dp[i] + 1);
            if (i + c <= n)
                dp[i + c] = max(dp[i + c], dp[i] + 1);
        }
    }
    cout << dp[n] << endl;
}
int main()
{
    Solve();
    return 0;
}