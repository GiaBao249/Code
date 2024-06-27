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
    int w, h, n;
    cin >> w >> h >> n;
    int cnt = 1;
    bool ok = true;
    while (true)
    {
        if (h % 2 == 0)
        {
            h /= 2;
            cnt *= 2;
        }
        if (w % 2 == 0)
        {
            w /= 2;
            cnt *= 2;
        }

        if (h % 2 && w % 2)
        {
            if (cnt < n)
            {
                ok = false;
                break;
            }
            else
            {
                ok = true;
                break;
            }
        }
    }
    if (ok)
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