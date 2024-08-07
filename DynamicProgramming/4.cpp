#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN 200005

ll n;
ll dp[MAXN];

void Solve()
{
    string s;
    cin >> s;
    ll q;
    cin >> q;
    while (q--)
    {
        ll r;
        cin >> r;
        for (int i = 0; i <= r; i++)
        {
            if ((s[i] - '0') % 2 == 0)
                dp[i] = dp[i - 1] + i + 1;
            else
                dp[i] = dp[i - 1];
        }
        cout << dp[r] << " ";
    }
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
    Solve();
    return 0;
}