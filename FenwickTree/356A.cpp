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
const int maxn = 300005;

/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/contest/356/problem/A
*/

int n, k;
vector<int> bit, res(maxn);

struct BIT
{
    BIT(int size)
    {
        bit.assign(size + 1, 0);
    }

    void update(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int get(int idx)
    {
        int sum = 0;
        for (; idx >= 1; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

void Solve()
{
    cin >> n >> k;
    BIT fw(n);
    f1(i, n) fw.update(i, 1);
    f1(i, n) res[i] = 0;

    while (k--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int a = fw.get(l - 1);
        int b = fw.get(r);

        while (a < b)
        {
            int lo = l, hi = r;
            while (lo < hi)
            {
                int mid = (lo + hi) >> 1;
                if (fw.get(mid) == a)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            res[lo] = x;
            fw.update(lo, -1);
            b--;
        }

        res[x] = 0;
        fw.update(x, 1);
    }

    f1(i, n - 1) cout << res[i] << " ";
    cout << res[n] << endl;
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
