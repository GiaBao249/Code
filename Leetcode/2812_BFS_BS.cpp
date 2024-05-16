#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool BFS(vector<vector<int>> &a, int safe)
{
    if (a[0][0] < safe)
        return false;
    int n = a.size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == n - 1)
            return true;
        for (int k = 0; k < 4; k++)
        {
            int u = x + dx[k];
            int v = y + dy[k];
            if (u >= 0 && v >= 0 && u < n && v < n && !visited[u][v] && a[u][v] >= safe)
            {
                q.push({u, v});
                visited[u][v] = true;
            }
        }
    }
    return false;
}

int maximumSafenessFactor(vector<vector<int>> &a)
{
    int n = a.size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                dist[i][j] = 0;
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int t = q.size();
        while (t--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int u = x + dx[k];
                int v = y + dy[k];
                if (u >= 0 && v >= 0 && u < n && v < n && !visited[u][v])
                {
                    q.push({u, v});
                    visited[u][v] = true;
                    dist[u][v] = dist[x][y] + 1;
                }
            }
        }
    }

    // BFS
    int l = 0, r = 1e9;
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (BFS(dist, mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}
