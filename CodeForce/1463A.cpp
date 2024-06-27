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
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 9 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    if (min({a, b, c}) >= (a + b + c) / 9)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}