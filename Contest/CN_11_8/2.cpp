#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 0;
/*
 /\_/\
(= >_<)
/ >  \>
*/
struct X
{
    int s, e;
};
bool cmp(const X &a, const X &b)
{
    if (a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

void Solve()
{
    int n;
    cin >> n;
    X a[n];
    f0(i, n)
    {
        int x, y;
        cin >> x >> y;
        a[i].s = x, a[i].e = y + 1;
    }
    multiset<int> se;
    sort(a, a + n, cmp);
    ll mx = 0;
    f0(i, n)
    {
        auto it = se.upper_bound(a[i].s);
        se.erase(se.begin(), it);
        se.insert(a[i].e);
        mx = max(mx, 1LL * sz(se));
    }
    cout << mx;
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