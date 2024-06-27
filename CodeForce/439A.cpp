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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    int cnt = 0;
    bool ok = true;
    int br = (n - 1) * 10;
    int total = s + br;
    if (d < total)
    {
        cout << -1 << endl;
        return;
    }
    int tmp = d - total;
    cnt = tmp / 5 + (n - 1) * 2;
    cout << cnt << endl;
}
int main()
{
    Solve();
    return 0;
}