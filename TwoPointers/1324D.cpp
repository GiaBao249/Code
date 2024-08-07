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
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    f0(i, n) cin >> a[i];
    f0(i, n) cin >> b[i];

    f0(i, n) c[i] = a[i] - b[i];

    sort(all(c));
    int l = 0, r = n - 1;
    ll res = 0;
    while (l < r)
    {
        if (c[l] + c[r] > 0)
        {
            res += (r - l);
            r--;
        }
        else
            l++;
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
    return 0;
}