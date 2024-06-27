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
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int x = n / 2 - (n % 2 == 1 ? 0 : 1);
    int target = a[x] + 1;
    int s = 0;
    for (int i = x; i < n; i++)
    {
        if (a[i] < target)
            s += (target - a[i]);
    }
    cout << s << endl;
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