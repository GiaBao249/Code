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
    if (a < b)
        swap(a, b);
    if (a == b)
        cout << 0 << " " << 0 << endl;
    else
        cout << a - b << " " << min(a % (a - b), (a - b) - (a % (a - b))) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}