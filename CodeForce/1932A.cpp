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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.' && s[i + 1] == '*')
        {
            if (i < n && s[i + 2] == '*')
                break;
            else if (i < n && s[i + 2] != '*')
            {
                if (s[i + 2] == '@')
                {
                    cnt++;
                    s[i + 2] = '.';
                }
                i++;
            }
        }
        else if (s[i] == '.')
        {
            if (i < n && s[i + 1] == '@')
            {
                s[i + 1] = '.';
                cnt++;
            }
        }
    }
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