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
    int cnt1 = 1, cnt2 = 1;
    for (int i = 0; i < n - 2; i += 2)
    {
        if (a[i] % 2 == 0 && a[i + 2] % 2 == 0 || a[i] % 2 == 1 && a[i + 2] % 2 == 1)
            cnt1 = 1;
        else
        {
            cnt1 = 0;
            break;
        }
    }
    for (int i = 1; i < n - 2; i += 2)
    {
        if (a[i] % 2 == 1 && a[i + 2] % 2 == 1 || a[i] % 2 == 0 && a[i + 2] % 2 == 0)
            cnt2 = 1;
        else
        {
            cnt2 = 0;
            break;
        }
    }
    if (cnt1 == 1 && cnt2 == 1)
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