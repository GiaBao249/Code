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
    int l = 1, r = n;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (mid * k >= n)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    ll x = Bs(n, k);
    ll s = x * k;
    cout << (s + n - 1) / n << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}