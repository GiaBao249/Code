#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int backtracking(vector<vector<int>> &a, int n, int m, int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 0)
        return 0;
    else
    {
        int gold = a[x][y];
        a[x][y] = 0;

        int maxGold = 0;
        for (int k = 0; k < 4; k++)
        {
            int u = x + dx[k];
            int v = y + dy[k];
            maxGold = max(maxGold, backtracking(a, n, m, u, v));
        }
        a[x][y] = gold;
        return gold + maxGold;
    }
}

int getMaximumGold(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
                res = max(backtracking(a, n, m, i, j), res);
        }
    }
    return res;
}
