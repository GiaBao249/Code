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
    string t;
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < n; i++)
    {
        if (t.empty() || t.back() != s[i])
            t += s[i];
    }
    if (t == "meow")
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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