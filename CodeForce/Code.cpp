#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

void Solve()
{
    multiset<ll> se;
    int n, m;
    cin >> n >> m;
    f0(i, n)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (se.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }
        auto s = se.upper_bound(x);
        if (s == se.begin())
        {
            cout << -1 << endl;
            continue;
        }
        s--;
        cout << *s << endl;
        se.erase(s);
    }
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