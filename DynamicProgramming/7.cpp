#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), dp;
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (auto x : a)
    {
        auto u = lower_bound(ALL(dp), x);
        if (u != dp.end())
            *u = x;
        else
            dp.push_back(x);
    }
    cout << dp.size() << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    Solve();
    return 0;
}