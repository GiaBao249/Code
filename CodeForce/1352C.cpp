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

ll Bs(ll n, ll k)
{
    ll l = 1, r = k * n;
    ll res = 0;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        ll s = mid - (mid / n);
        if (s >= k)
        {
            if (mid % n != 0)
                res = mid;
            r = mid;
        }
        else
            l = mid + 1;
    }
    return res;
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << Bs(n, k) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}