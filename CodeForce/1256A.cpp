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
    ll a, b, n, s;
    cin >> a >> b >> n >> s;
    // ll x = a * n;
    // while (x > s)
    //     x -= n;
    // if (x + b >= s)
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
    ll maxx = min(s / n, a) * n;
    ll x = s - maxx;
    if (x <= b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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