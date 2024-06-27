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
    string s;
    cin >> s;
    int n = s.size();
    set<char> se;
    int cnt = 0, res = 1;
    for (int i = 0; i < n; i++)
    {
        se.insert(s[i]);
        if (se.size() > 3)
        {
            res++;
            se.clear();
            se.insert(s[i]);
        }
    }
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
