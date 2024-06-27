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
    bool ok = false;
    for (int i = 1; i < s.size(); i++)
    {
        string a = s.substr(0, i);
        string b = s.substr(i);
        if (b[0] != '0' && (a.empty() || stoi(a) < stoi(b)))
        {
            cout << a << " " << b << endl;
            ok = true;
            break;
        }
    }
    if (!ok)
        cout << -1 << endl;
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