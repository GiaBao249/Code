#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 1e9 + 10;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n, m;
vector<ll> a;
bool check(ll mid)
{
    ll s = 0;
    f0(i, n)
    {
        s += (mid / a[i]);
        if (s >= m)
            return true;
    }
    return s >= m;
}

void Solve()
{
    cin >> n >> m;
    a.resize(n);
    f0(i, n) cin >> a[i];
    if (m == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll l = 0, r = 1e18;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    Solve();
    return 0;
}