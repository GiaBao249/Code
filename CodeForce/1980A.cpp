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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto x : s)
        mp[x]++;
    int cnt = 0;
    for (auto [a, b] : mp)
    {
        if (b < m)
            cnt += m - b;
    }
    if (mp.size() < 7)
        cnt += (7 - mp.size()) * m;
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}