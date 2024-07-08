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
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    int minn = INT_MAX;
    for (int &x : a)
    {
        cin >> x;
        s += x;
        if (x % 2 != 0)
            minn = min(minn, x);
    }
    if (s % 2 != 0)
        s -= minn;
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}