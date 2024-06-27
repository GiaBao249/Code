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
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int res = abs(a[1] - a[0]) + abs(a[1] - a[2]);
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}