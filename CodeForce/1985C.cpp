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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    ll s = 0;
    ll x = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        x = max(x, 1LL * a[i]);
        if (s == 2 * x)
            cnt++;
    }
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}