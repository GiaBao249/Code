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
    int s = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s <= a[i])
        {
            cnt++;
            s += a[i];
        }
    }
    cout << cnt << endl;
}
int main()
{
    Solve();
    return 0;
}