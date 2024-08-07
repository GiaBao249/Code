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
/ >  \> http://upcoder.xyz/'index.php/47408bc87c85c602d58b4fd376c30e64804e3b21af47c8fde65ba9380ef701fa/ixvr:''vTeTdPu_306'BpeNz$pnS'TtTbqMnw'xukojx'86!5'-Lkd-5d9bM3~C2:hh7FhA.7k9Nf5LC@98/1a962a2b0e35055cdd3e114b7b30098e1feff0ce2720401bc80e8ae8b6dfb452
*/

int n, k;

struct BIT
{
    vector<int> bit;
    int n;

    BIT(int size) : n(size + 1)
    {
        bit.assign(n, 0);
    }

    void update(int idx, int val)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx)
    {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

void Solve()
{
    cin >> n >> k;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    vector<int> cc = a;
    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());
    for (int &x : a)
        x = lower_bound(all(cc), x) - cc.begin();
    BIT fw(cc.size());
    vector<int> v(cc.size(), -1);
    ll cnt = 0, j = 0, res = 0;
    f0(i, n)
    {
        if (v[a[i]] == -1)
            cnt++;
        fw.update(a[i], 1);
        while (cnt > k)
        {
            fw.update(a[j], -1);
            if (fw.query(a[j]) - fw.query(a[j] - 1) == 0)
            {
                cnt--;
                v[a[j]] = -1;
            }
            j++;
        }
        v[a[i]] = i;
        res += (i - j + 1);
    }
    cout << res << endl;
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
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}