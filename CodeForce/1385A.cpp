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
    int x, y, z;
    cin >> x >> y >> z;
    if (x > y)
        swap(x, y);
    if (y > z)
        swap(x, z);
    if (x > z)
        swap(x, z);

    if (y != z)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << x << " " << x << " " << z << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}