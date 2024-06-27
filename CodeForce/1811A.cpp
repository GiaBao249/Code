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
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' >= k)
            res += s[i];
        else
        {
            res += to_string(k);
            while (i < n)
            {
                res += s[i];
                i++;
            }
            cout << res << endl;
            return;
        }
    }
    cout << res + to_string(k) << endl;
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