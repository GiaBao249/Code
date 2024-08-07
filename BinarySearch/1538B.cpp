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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    sort(all(a));
    ll cnt = 0;
    f0(i, n - 1)
    {
        auto left = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
        auto right = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
        cnt += right - left;
    }
    cout << cnt << endl;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}