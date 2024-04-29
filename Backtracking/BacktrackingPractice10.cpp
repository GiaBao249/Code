#include <bits/stdc++.h>
using namespace std;

int n, a[100][100], ok = 0;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

string p = "DLRU";

void Input()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        cout << s << " ";
        ok = 1;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1])
        {
            a[i1][j1] = 0;
            Try(i1, j1, s + p[k]);
            a[i1][j1] = 1;
        }
    }
}
int main()
{
    ok = 0;
    cin >> n;
    Input();
    if (a[1][1] && a[n][n])
    {
        a[1][1] = 0;
        Try(1, 1, "");
    }
    if (ok)
        cout << "";
    else
        cout << "-1 " << endl;
}
