#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn 200005
void Solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<char> a(k);
    f0(i, n) cin >> a[i];
    vector<ll> dp(n, 0);
    unordered_set<int> se(all(a));

    if (se.find(s[0]) != se.end())
        dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (se.find(s[i]) != se.end())
        {
            dp[i] = dp[i - 1] + 1;
        }
    }
    for (auto x : dp)
        cout << x << " ";
    cout << accumulate(all(dp), 0LL);
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