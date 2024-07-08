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
    // for (ll i = 0; i < b; i++)
    //     a += "0";
    // for (ll i = 0; i < d; i++)
    //     c += "0";
    // if (a.size() > c.size())
    //     cout << ">" << endl;
    // else if (a.size() == c.size())
    // {
    //     if (a[0] - '0' > c[0] - '0')
    //         cout << ">" << endl;
    //     else if ((a[0] - '0' < c[0] - '0'))
    //         cout << "<" << endl;
    //     else
    //         cout << "=" << endl;
    // }
    // else
    //     cout << "<" << endl;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = min(b, d);
    b -= x;
    d -= x;
    if (b >= 7)
        cout << ">" << endl;
    else if (d >= 7)
        cout << "<" << endl;
    else
    {
        while (b > 0)
        {
            a *= 10;
            b--;
        }
        while (d > 0)
        {
            c *= 10;
            d--;
        }
        if (a > c)
            cout << ">" << endl;
        else if (a < c)
            cout << "<" << endl;
        else
            cout << "=" << endl;
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