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
    int m = *max_element(a.begin(), a.end());
    vector<ll> dp(m + 1, 0), fre(m + 1, 0);
    for (int x : a)
        fre[x]++;

    dp[1] = fre[1];
    for (int i = 2; i <= m; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + fre[i] * i);
    cout << dp[m] << endl;
}
int main()
{
    Solve();
    return 0;
}