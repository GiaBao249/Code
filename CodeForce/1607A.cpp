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
    string s, t;
    cin >> s >> t;
    vector<int> v(26, 0);
    for (int i = 0; i < 26; i++)
        v[s[i] - 'a'] = i + 1;
    int x = 0;
    for (int i = 0; i < t.size() - 1; i++)
    {
        x += abs(v[t[i] - 'a'] - v[t[i + 1] - 'a']);
    }
    cout << x << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}