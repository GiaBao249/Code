#include <bits/stdc++.h>
using namespace std;

int a[100][100];
void Insert(int n, int m)
{
    int i = 0, k = 1, d = -1;
    while (k <= n * m)
    {
        d++;
        for (i = d; i < m - d; i++)
            a[d][i] = k++;
        for (i = d + 1; i < n - d; i++)
            a[i][m - d - 1] = k++;
        for (i = m - 2 - d; i >= d; i--)
            a[n - 1 - d][i] = k++;
        for (i = n - 2 - d; i > d; i--)
            a[i][d] = k++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Insert(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}