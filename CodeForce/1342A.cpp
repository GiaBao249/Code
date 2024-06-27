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
    ll x, y;
    cin >> x >> y;
    int a, b;
    cin >> a >> b;
    ll s = 0;
    if (x < y)
        swap(x, y);
    if (a + a <= b)
        s = (x + y) * a;
    else
        s = y * b + (x - y) * a;
    cout << s << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}