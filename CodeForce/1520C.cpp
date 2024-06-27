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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void Solve()
{
    int n;
    cin >> n;
    int x = 1;
    int y = 2;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    bool ok = false;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x <= n * n)
            {
                a[i][j] = x;
                x += 2;
            }
            else if (y <= n * n)
            {
                a[i][j] = y;
                y += 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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