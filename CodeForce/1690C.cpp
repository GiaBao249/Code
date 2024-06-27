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
    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    vector<int> res;

    for (int i = 0; i < n - 1; i++)
    {
        if (f[i] < s[i + 1])
            res.push_back(f[i] - s[i]);
        else
        {
            s[i + 1] = f[i];
            res.push_back(f[i] - s[i]);
        }
    }
    res.push_back(f[n - 1] - s[n - 1]);
    for (auto x : res)
        cout
            << x << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}