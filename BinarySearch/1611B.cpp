#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN
void Solve()
{
    ll a, b;
    cin >> a >> b;
    int l = 0, r = min(a, min(b, (a + b) / 4));
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (mid <= a && mid * 4 <= a + b)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}