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
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = 2 * abs(a - b);
    if (a > x || b > x || c > x)
        cout << -1 << endl;
    else
    {
        ll d = c + x / 2;
        while (d > x)
            d -= x;
        cout << d << endl;
    }
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