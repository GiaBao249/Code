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
#define pb(x) push_back(x)
const int maxn = 200005;

vector<int> bit(maxn);
int n, k;

void update(int i, int v)
{
    for (; i < maxn; i += i & -i)
        bit[i] += v;
}

int get(int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int Bs(int k)
{
    int lo = 1, hi = maxn - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        if (get(mid) < k)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void Solve()
{
    cin >> n >> k;
    vector<int> a(n), res;
    f0(i, n) cin >> a[i];
    vector<int> cc(all(a));
    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());

    bit.resize(sz(cc) + 1, 0);
    f0(i, k - 1)
    {
        int it = lower_bound(all(cc), a[i]) - cc.begin() + 1;
        update(it, 1);
    }

    for (int i = k - 1; i < n; i++)
    {
        int it = lower_bound(all(cc), a[i]) - cc.begin() + 1;
        update(it, 1);

        int mid = (k + 1) / 2;
        int x = Bs(mid);
        cout << cc[x - 1] << ' ';
        if (i - k + 1 >= 0)
        {
            it = lower_bound(all(cc), a[i - k + 1]) - cc.begin() + 1;
            update(it, -1);
        }
    }
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