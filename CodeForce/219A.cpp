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
    int k;
    cin >> k;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;
    string res = "";
    for (auto [a, b] : mp)
    {
        if (b % k != 0)
        {
            cout << -1 << endl;
            return;
        }
        res += string(b / k, a);
    }
    for (int i = 0; i < k; i++)
        cout << res;
    cout << endl;
}
int main()
{

    Solve();
    return 0;
}