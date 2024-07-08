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
    for (int &x : a)
        cin >> x;
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        while (a[i] >= a[i + 1] && a[i] > 0)
        {
            a[i] /= 2;
            cnt++;
        }
        if (a[i] == a[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
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