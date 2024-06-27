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
    for (int i = 0; i < 5; i++)
    {
        string a;
        cin >> a;
        if (a[0] == s[0] || a[1] == s[1])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main()
{
    Solve();
    return 0;
}