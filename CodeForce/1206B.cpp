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
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0, y = 0, z = 0;
    for (int &i : a)
    {
        cin >> i;
        if (i > 0)
            x++;
        else if (i == 0)
            y++;
        else
            z++;
    }
    if (a.size() == 1)
    {
        if (a[0] < 0)
            cout << abs(a[0]) + 1 << endl;
        else if (a[0] == 0)
            cout << 1 << endl;
        else
            cout << abs(a[0]) - 1 << endl;
        return;
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 1)
            cnt += a[i] - 1;
        else if (a[i] < -1)
            cnt += abs(a[i] + 1);
    }
    cnt += y;
    if (z % 2 == 1)
    {
        if (y == 0)
            cnt += 2;
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}