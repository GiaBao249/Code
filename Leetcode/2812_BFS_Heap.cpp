#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void BFS(vector<vector<int>> &a, vector<vector<int>> &score, int n)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                score[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        int s = score[x][y];
        for (int k = 0; k < 4; k++)
        {
            int u = x + dx[k];
            int v = y + dy[k];
            if (u >= 0 && v >= 0 && v < n && u < n && score[u][v] > 1 + s)
            {
                score[u][v] = s + 1;
                q.push({u, v});
            }
        }
    }
}
int maximumSafenessFactor(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1])
        return 0;
    else
    {
        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        BFS(grid, score, n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto safe = pq.top().first;
            auto temp = pq.top().second;
            pq.pop();
            if (temp.first == n - 1 && temp.second == n - 1)
            {
                return safe;
            }
            visited[temp.first][temp.second] = true;

            for (int k = 0; k < 4; k++)
            {
                int newX = dx[k] + temp.first;
                int newY = dy[k] + temp.second;
                if (newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY])
                {
                    int res = min(safe, score[newX][newY]);
                    pq.push({res, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }
    }
    return -1;
}