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
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == 'm' && s[i] == 'a' && s[i + 1] == 'p' ||
            s[i - 1] == 'p' && s[i] == 'i' && s[i + 1] == 'e')
        {
            i += 2;
            cnt++;
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