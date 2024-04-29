#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int n, ok;
void Input()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j, string s)
{
    if (i == n && j == n)
    {
        cout << s << " ";
        ok = 1;
    }
    if (i + 1 <= n && a[i + 1][j] == 1)
    {
        Try(i + 1, j, s + 'D');
    }
    if (j + 1 <= n && a[i][j + 1] == 1)
    {
        Try(i, j + 1, s + 'R');
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Input();
        ok = 0;
        if (a[1][1] && a[n][n])
        {
            Try(1, 1, "");
        }
        cout << endl;
    }
}