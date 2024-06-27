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
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    int k = 1;
    while (true)
    {
        bool ok = true;
        for (auto [d, s] : p)
        {
            int timelimit = d;
            int time = 2 * k - d;
            if (d + s <= time)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
        k++;
    }
    cout << k - 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}