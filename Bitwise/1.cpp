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
(= ._.)
/ >  \>
*/
void Solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    ll res = 0;
    f0(i, l)
    {
        int cnt[2] = {0, 0};
        f0(j, n)
        {
            // Dịch bit về cuối kiểm tra xem ở bit tại thời điểm đó bit là 0 hay 1
            cnt[(a[j] >> i) & 1]++;
        }
        if (cnt[1] > cnt[0])
            res += 1 << i;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}