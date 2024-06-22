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

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int even = 0;
    int odd = 0;
    set<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
        se.insert(a[i]);
    }
    if (a.size() == 1 || se.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (even < odd && even >= 1 || odd < even && odd >= 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (even == odd)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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