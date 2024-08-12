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
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/1859/problem/C
*/

int cal(int mid, int n)
{
    ll s = 0, mx = 0;
    vector<int> a(n);
    for (int i = 0; i < mid; ++i)
        a[i] = i + 1;
    int m = n;
    for (int i = mid; i < n; i++)
        a[i] = m--;
    f0(i, n)
    {
        s += a[i] * (i + 1);
        mx = max(mx, 1LL * a[i] * (i + 1));
    }
    return s - mx;
}
void Solve()
{
    int n;
    cin >> n;
    int lo = 0, hi = n - 1;
    ll mx = -inf;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        ll u = cal(mid, n);
        ll v = cal(mid + 1, n);
        mx = max(mx, max(u, v));
        if (u < v)
            lo = mid + 1;
        else
            hi = mid;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}