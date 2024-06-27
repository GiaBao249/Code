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
    int odd = 0, even = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x % 2 != 0)
            odd++;
        else
            even++;
    }
    sort(a.begin(), a.end());
    bool ok = false;
    if (odd % 2 == 0 && even % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    else if (even % 2 != odd % 2)
    {
        cout << "NO" << endl;
        return;
    }
    else if (odd % 2 && even % 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(a[i] - a[i + 1]) == 1)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}