#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int n, m, ans = 0;
void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j, int sum)
{
    if (i == n && j == m)
    {
        ans = max(ans, sum);
        return;
    }
    if (i + 1 <= n)
    {
        Try(i + 1, j, sum + a[i + 1][j]);
    }
    if (j + 1 <= m)
    {
        Try(i, j + 1, sum + a[i][j + 1]);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Input();
        ans = INT_MIN;
        Try(1, 1, a[1][1]);
        cout << ans << endl;
    }
}