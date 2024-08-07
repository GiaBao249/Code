#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(3);
    f0(i, n) cin >> a[i];
    vector<int> Min = a;
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = -inf;
    for (int i = n - 2; i >= 0; i--)
        Min[i] = min(Min[i], Min[i + 1]);
    ll mx = -inf;
    sort(all(dp));
    for (int i = 2; i < n; i++)
    {
        dp[0] = a[i];
        sort(all(dp));
        mx = max(mx, 1LL * (dp[1] + dp[2] - Min[i + 1]));
    }
    cout << mx << endl;
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
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}