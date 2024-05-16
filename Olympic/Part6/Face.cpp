#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};
int a[100][100];
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int res = 0;
    int a[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int u = i + dx[k];
                int v = j + dy[k];
                if (u < n && v < n && a[u][v] != 0)
                    cnt++;
                else
                    break;
            }
            if (cnt == 4)
                res++;
        }
    }
    cout << res << endl;
}