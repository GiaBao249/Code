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
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int minn = max(a[0], a[1]);
    for (int i = 1; i < n - 1; i++)
    {
        minn = min(minn, max(a[i + 1], a[i]));
    }
    cout << minn - 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}