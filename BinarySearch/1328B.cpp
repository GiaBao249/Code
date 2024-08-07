#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX

void Solve()
{
    ll n, k;
    cin >> n >> k;
    string s = string(n, 'a');

    ll l = 1, r = n - 1, i1 = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if ((mid * (mid + 1)) / 2 >= k)
        {
            i1 = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    ll i2 = k - (i1 * (i1 - 1)) / 2;

    s[n - i1 - 1] = 'b';
    s[n - i2] = 'b';

    cout << s << endl;
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
