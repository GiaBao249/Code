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
    int cnt = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] != '1')
        {
            l++;
        }
        else if (s[r] != '1')
            r--;
        if (s[l] == '1' && s[r] == '1')
        {
            for (int i = l; i <= r; i++)
            {
                if (s[i] == '0')
                    cnt++;
            }
            break;
        }
    }
    cout << cnt << endl;
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