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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += a[i];
        s2 += a[i] / x + (a[i] % x == 0 ? 0 : 1);
    }
    cout << s1 / x + (s1 % x == 0 ? 0 : 1) << " " << s2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}