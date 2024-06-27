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
// No Pain No Gain !

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    int l = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
        {
            s += a[i];
            l++;
        }
        else
            c++;
    }
    if (s % 2 == 0)
        cout << c << endl;
    else
        cout << l << endl;
}
int main()
{
    /*int t;
    cin >> t;
    while (t--)*/
    Solve();
    return 0;
}