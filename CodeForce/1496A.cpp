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
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    int res = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l] == a[r])
        {
            l++;
            r--;
            res++;
        }
        else
            break;
    }
    if (res > k)
        cout << "YES" << endl;
    else if (res == k && l <= r)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}