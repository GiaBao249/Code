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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;
    ll cnt = 0;
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > q)
            r = 0;
        else
        {
            r++;
            if (r >= k)
            {
                cnt += r - k + 1;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}