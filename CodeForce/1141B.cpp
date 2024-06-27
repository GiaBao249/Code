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
    set<int> se;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        se.insert(x);
    }
    if (se.size() == 1 && *se.begin() == 0)
    {
        cout << 0 << endl;
        return;
    }
    int res = 0;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 1 && a[i + 1] == 1)
            cnt++;
        else
        {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    res = max(res, cnt);
    int x = 0, y = 0;
    if (a[0] == 1 && a[n - 1] == 1)
    {
        for (int i = 0; i < n && a[i] == 1; i++)
            x++;
        for (int i = n - 1; i >= 0 && a[i] == 1; i--)
            y++;
    }
    cout << max(res, x + y) << endl;
}
int main()
{
    Solve();
    return 0;
}
