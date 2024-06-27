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
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    int maxx = *max_element(v.begin(), v.end());
    int a = v[0], b = v[1], c = v[2];
    if (a == b && b == c)
    {
        cout << 1 << " " << 1 << " " << 1 << endl;
        return;
    }
    int x = maxx - a + (maxx - a == 0 ? 0 : 1),
        y = maxx - b + (maxx - b == 0 ? 0 : 1),
        z = maxx - c + (maxx - c == 0 ? 0 : 1);
    if (x == 0 && y == 0)
    {
        x++;
        y++;
    }
    else if (x == 0 && z == 0)
    {
        x++;
        z++;
    }
    else if (y == 0 && z == 0)
    {
        y++;
        z++;
    }
    cout << x << " " << y << " " << z << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}