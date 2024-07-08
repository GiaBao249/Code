#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    int h = 1;
    vector<int> a;
    int res = 0;
    while (true)
    {
        ll f = (3 * h * (h + 1) / 2) - h;
        if (f > n)
            break;
        a.push_back(f);
        h++;
    }
    while (n > 1)
    {
        auto it = upper_bound(a.begin(), a.end(), n) - a.begin();
        it--;
        n -= a[it];
        res++;
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}