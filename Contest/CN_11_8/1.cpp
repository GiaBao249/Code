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
const int maxn = 200005;
/*
 /\_/\
(= >_<)
/ >  \>
*/
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
    ll k;
    cin >> n >> k;
    k++;
    f1(i, n) update(i, 1);

    int pos = 0;
    for (int i = n; i >= 1; i--)
    {
        pos = (pos + k) % i;
        if (pos == 0)
            pos = i;

        int idx = Bs(pos);
        cout << idx << " ";

        update(idx, -1);
        pos--;
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