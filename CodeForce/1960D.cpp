#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Code đi đừng sợ!

void Solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> pre(n + 1, 0);
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == 'W' ? 1 : 0);
    for (int i = 0; i <= n - k; i++)
        res = min(res, pre[i + k] - pre[i]);
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