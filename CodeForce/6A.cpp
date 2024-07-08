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
    vector<int> a(4);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    if (((a[1] + a[2]) > a[3]) || ((a[0] + a[1]) > a[2]))
        cout << "TRIANGLE" << endl;
    else if ((a[0] + a[1] == a[2]) || (a[1] + a[2] == a[3]))
        cout << "SEGMENT" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}