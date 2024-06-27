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
    vector<int> a(n), b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        c.push_back(x);
    }
    vector<int> res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] != b[i])
        {
            res.push_back(a[i]);
            break;
        }
    }
    if (res.size() == 0)
        res.push_back(a[a.size() - 1]);

    for (int i = 0; i < c.size(); i++)
    {
        if (b[i] != c[i])
        {
            res.push_back(b[i]);
            break;
        }
    }
    if (res.size() == 1)
        res.push_back(b[b.size() - 1]);
    for (auto x : res)
        cout << x << endl;
}

int main()
{
    Solve();
    return 0;
}