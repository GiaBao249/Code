#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define el '\n'

int n, m;
vector<int> a, b;

bool check(int mid)
{
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < m && abs(a[i] - b[j]) <= mid)
        {
            j++;
        }
        if (j == m)
        {
            return true;
        }
    }
    return false;
}

void Solve()
{
    cin >> n >> m;
    a.resize(n), b.resize(m);
    f0(i, n) cin >> a[i];
    f0(i, m) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    int l = 0, r = 1e9, res = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solve();
    return 0;
}
