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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 || a[i][j] == 3)
                cnt++;
        }
        if (cnt == 0)
            res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    Solve();
    return 0;
}