#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> dp1(n, 0), dp2(n, 0);
    for (int i = 1; i < n; i++)
    {
        dp1[i] = dp1[i - 1];
        if (a[i] > a[i - 1])
            dp1[i] += (a[i] - a[i - 1]);

        dp2[i] = dp2[i - 1];
        if (a[i] < a[i - 1])
            dp2[i] += (a[i - 1] - a[i]);
    }
    while (m--)
    {
        int p, q;
        cin >> p >> q;
        q--, p--;
        if (p < q)
            cout << dp2[q] - dp2[p] << endl;
        else
            cout << dp1[p] - dp1[q] << endl;
    }
}
int main()
{
    Solve();
    return 0;
}