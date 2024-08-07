#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN

int par[100001];

int findSet(int v)
{
    return par[v] == v ? v : par[v] = findSet(par[v]);
}

void Solve()
{
    int n;
    cin >> n;
    ll a[n], dp[n];
    f0(i, 0, n)
    {
        cin >> a[i];
        par[i] = i;
    }
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {

            if (a[j] < a[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        mx = max(dp[i], mx);
    }
    cout << mx << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    Solve();
    return 0;
}