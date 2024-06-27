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
    ll a, b;
    cin >> a >> b;
    if (b == 1)
    {
        cout << "NO" << endl;
        return;
    }
    ll x = 0, y = 0, z = 0;
    x = a;
    y = a * b;
    z = x + y;
    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
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