#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool visited[100][100];
int a[100][100];
int n, m, s, t, u, v;

void loang(int i, int j)
{
    visited[i][j] = false;
    for (int k = 0; k < 4; k++)
    {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == true)
        {
            loang(x, y);
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t >> u >> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    loang(s, t);
    if (a[u][v])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}