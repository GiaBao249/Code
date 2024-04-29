#include <bits/stdc++.h>
using namespace std;

int n, a[505][505];
bool visited[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool BFS(int mid)
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int u = dx[k] + i;
            int v = dy[k] + j;
            if (u < 1 || u > n || v < 1 || v > n)
                continue;
            if (visited[u][v])
                continue;
            if (abs(a[u][v] - a[i][j]) > mid)
                continue;
            visited[u][v] = true;
            q.push({u, v});
        }
    }
    return visited[n][n];
}

int BSeach()
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (BFS(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << BSeach() << endl;
}