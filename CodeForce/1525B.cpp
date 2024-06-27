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
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    bool ok = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            ok = true;
            break;
        }
    }
    if (!ok)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        if (a[0] == 1 || a[n - 1] == n)
            cout << 1 << endl;
        else if (a[0] == n && a[n - 1] == 1)
            cout << 3 << endl;
        else
            cout << 2 << endl;
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