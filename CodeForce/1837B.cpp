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
    string s;
    cin >> s;
    int x = 1, res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            x++;
        else
        {
            x = 1;
        }
        res = max(x, res);
    }
    cout << res + 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}