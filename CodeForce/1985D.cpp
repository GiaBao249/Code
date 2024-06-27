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
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
                pos.emplace_back(i, j);
        }
    }

    int minX = n, minY = m, maxX = -1, maxY = -1;
    for (auto [a, b] : pos)
    {
        minX = min(minX, a);
        minY = min(minY, b);
        maxX = max(maxX, a);
        maxY = max(maxY, b);
    }
    int h = (minX + maxX) / 2;
    int k = (maxY + minY) / 2;
    cout << h + 1 << " " << k + 1 << endl;
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