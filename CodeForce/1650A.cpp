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
    char c;
    cin >> c;
    if (s.find(c) == string ::npos)
        cout << "NO" << endl;
    else
    {
        int pos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                pos = i;
                if (pos % 2 == 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
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