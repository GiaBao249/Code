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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    vector<int> b(n), res(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.emplace_back(x, i);
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        res[a[i].second] = b[i];
    }
    for (auto x : res)
        cout << x << " ";
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