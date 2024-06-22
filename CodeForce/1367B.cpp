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
#include <deque>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;
#define ll long long

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), o, e;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0 && a[i] % 2 == 1)
            o.push_back(a[i]);
        else if (i % 2 == 1 && a[i] % 2 == 0)
            e.push_back(a[i]);
    }
    if (o.size() != e.size())
    {
        cout << -1 << endl;
        return;
    }
    else
        cout << o.size() << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}