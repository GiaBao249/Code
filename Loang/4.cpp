#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

int a[100][100];
int n, s, e, cnt = 0;

void loang(int i, int j)
{
    a[i][j] = 1;
    cnt++;
    for (int k = 0; k < 4; k++)
    {
        int u = dx[k] + i;
        int v = dy[k] + j;
        if (u >= 1 && u <= n && v >= 1 && v <= n && a[u][v] == 0)
        {
            loang(u, v);
        }
    }
}

int main()
{
    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    loang(s, e);
    cout << cnt << endl;
}