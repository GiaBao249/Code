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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = -1;
    int s = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != s)
            continue;
        if (i > 0 && a[i - 1] != s)
            x = i + 1;
        if (i < n - 1 && a[i + 1] != s)
            x = i + 1;
    }
    if (x != -1)
        cout << x << endl;
    else
        cout << x << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}