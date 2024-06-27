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
#define Input for (int &x : a)
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<ll> dp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + a[i] >= n)
            dp[i] = a[i];
        else
            dp[i] = dp[a[i] + i] + a[i];
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    cout << res << endl;
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