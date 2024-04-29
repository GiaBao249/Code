#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};
int a[100][100];
int n, m;
void Test(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    a[i][j] = 2;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (i == 1 || i == n || j == 1 || j == m)
        {
            break;
        }
        int temp = a[i][j];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int dx = x[k] + i;
            int dy = y[k] + j;
            if (a[dx][dy] == 0)
            {
                q.push(make_pair(dx, dy));
                a[dx][dy] = temp + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    Test(2, 7);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}