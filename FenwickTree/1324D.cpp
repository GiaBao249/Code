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

int n;
struct FwTree
{
    vector<int> bit;
    FwTree(int n) { bit.resize(n + 1, 0); }
    void update(int i, int v)
    {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int get(int i)
    {
        int res = 0;
        for (; i >= 1; i &= i - 1)
            res += bit[i];
        return res;
    }
};

void Solve()
{
    cin >> n;
    vector<int> a(n), b(n), c(n);
    f0(i, n) cin >> a[i];
    f0(i, n) cin >> b[i];

    f0(i, n) c[i] = a[i] - b[i];
    sort(all(c));
    FwTree fw(n);
    ll cnt = 0;
    f0(i, n)
    {
        int it = lower_bound(all(c), -c[i] + 1) - c.begin();
        cnt += fw.get(n) - fw.get(it);
        fw.update(i + 1, 1);
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
    Solve();
    return 0;
}