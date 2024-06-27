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
    sort(a.begin(), a.end());
    if (a[1] - a[0] > a[n - 1] - a[n - 2])
        cout << a[n - 1] - a[1] << endl;
    else
        cout << a[n - 2] - a[0] << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    Solve();
    return 0;
}