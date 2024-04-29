#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Check(int i, int j)
{
    for (int k = 0; k < 8; k++)
    {
        int u = i + dx[k];
        int v = j + dy[k];
        if (u <= n && u >= 1 && v <= m && v >= 1 && a[u][v] >= a[i][j])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (Check(i, j))
                cnt++;
        }
    }
    cout << cnt << endl;
}