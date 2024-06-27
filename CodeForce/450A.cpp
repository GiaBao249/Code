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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        a[i]--;
        a[i] /= m;
        if (a[i] >= x)
        {
            x = a[i];
            y = i;
        }
    }
    cout << y + 1 << endl;
}
int main()
{
    Solve();
    return 0;
}