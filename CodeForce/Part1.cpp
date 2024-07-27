#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define el '\n'

void Solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> se;
    f0(i, n)
    {
        int x;
        cin >> x;
        se.insert(x);
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        ll sum = 0;
        ll l = x - y, r = x + y;

        auto it = se.begin();
        while (it != se.end() && *it < l)
        {
            sum += *it;
            it = se.erase(it);
        }

        it = se.upper_bound(r);
        while (it != se.end())
        {
            sum += *it;
            it = se.erase(it);
        }

        cout << sum << el;
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