#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <limits>
#include <stack>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    stack<char> st;
    string s;
    cin >> s;
    int x = 0, y = 0, z = 0;
    if (s[0] == ')')
    {
        cout << "NO" << endl;
        return;
    }
    else if (s[s.size() - 1] == '(')
    {
        cout << "NO" << endl;
        return;
    }
    for (char c : s)
    {
        if (c == '?')
            x++;
        else if (c == '(')
            y++;
        else
            z++;
    }
    if (abs(z + y) % 2 == x % 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}