#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1746
*/

int n;
struct BIT
{
    vector<ll> bit;
    int n;
    BIT(int n) : n(n)
    {
        bit.assign(n + 1, 0);
    }
    void update(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            bit[i] = (bit[i] + v) % MOD;
    }

    ll get(int i)
    {
        ll res = 0;
        for (; i > 0; i &= (i - 1))
            res = (res + bit[i]) % MOD;
        return res;
    }

    ll RangeSum(int l, int r)
    {
        return (get(r) - get(l - 1) + MOD) % MOD;
    }
};

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    BIT fw(k);
    For(i, 1, k + 1)
    {
        if (a[0] == 0 || a[0] == i)
            fw.update(i, 1);
    }
    For(i, 2, n + 1)
    {
        BIT nfw(k);
        For(j, 1, k + 1)
        {
            if (a[i - 1] != 0 && a[i - 1] != j)
                continue;
            ll cur = fw.RangeSum(max(1, j - 1), min(k, j + 1));
            nfw.update(j, cur);
            for (auto x : fw.bit)
                cout << x << " ";
            cout << endl;
        }
        fw = nfw;
    }
    cout << fw.get(k);
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