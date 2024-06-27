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
    unordered_map<int, int> mp;
    for (int &x : a)
    {
        cin >> x;
        mp[x]++;
    }
    int x = 1;
    for (auto [a, b] : mp)
        x = max(x, b);
    int res = 0;
    int size = mp.size();
    if (size == x)
        res = x - 1;
    else
        res = min(x, size);
    cout << res << endl;
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