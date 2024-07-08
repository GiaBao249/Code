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
    ll l, r, a;
    cin >> l >> r >> a;
    ll res = (r / a) + r % a;
    if (r - (r % a) - 1 >= l)
    {
        res = max(res, (r - (r % a) - 1) / a + (r - (r % a) - 1) % a);
    }
    cout << res << endl;
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