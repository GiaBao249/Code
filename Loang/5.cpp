#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;
int n, a[MAX][MAX];
bool visited[MAX][MAX];

bool bfs(int mid)
{
    // Khởi tạo
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    // BFS
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Kiểm tra các ngã tư kế cạnh
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx * dy != 0)
                    continue;
                int nx = x + dx, ny = y + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > n)
                    continue;
                if (visited[nx][ny])
                    continue;
                if (abs(a[nx][ny] - a[x][y]) > mid)
                    continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return visited[n][n];
}

int binary_search()
{
    int left = 0, right = 1e9;
    while (left < right)
    {
        int mid = (left + right) / 2;
        // Chặt tìm kiếm nhịn phân
        if (bfs(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cout << binary_search() << endl;

    return 0;
}
