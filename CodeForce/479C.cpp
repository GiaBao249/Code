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
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    int x = -1e9;
    for (auto [a, b] : v)
    {
        if (b >= x)
        {
            x = b;
        }
        else
            x = a;
    }
    cout << x << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    Solve();
    return 0;
}