#include <bits/stdc++.h>
using namespace std;

int n, m, a[705][705];
bool visited[705][705];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool check;
int ans = 0;
void BFS(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 8; k++)
    {
        int u = dx[k] + i;
        int v = dy[k] + j;
        if (u >= 0 && u < n && v >= 0 && v < m)
        {
            if (check && a[u][v] > a[i][j])
                check = false;
            if (a[u][v] == a[i][j] && !visited[u][v])
                BFS(u, v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                check = true;
                BFS(i, j);
                if (check)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}