#include <bits/stdc++.h>
using namespace std;

int a[100][100];
void Solve(int n, int m)
{
    int i = 0, j = 0, k = 1;
    a[i][j] = k++;
    while (k <= n * m)
    {
        if (i == 0 && j != m - 1)
        {
            j++;
            a[i][j] = k++;
        }
        else if (j == m - 1)
        {
            i++;
            a[i][j] = k++;
        }
        while (i < n - 1 && j > 0) // chéo xuống
        {
            i++;
            j--;
            a[i][j] = k++;
        }
        if (i == n - 1)
        {
            j++;
            a[i][j] = k++;
        }
        else if (j == 0)
        {
            i++;
            a[i][j] = k++;
        }
        while (j < m - 1 && i > 0) // chéo lên
        {
            i--;
            j++;
            a[i][j] = k++;
        }
    }
}

int main()
{
    int n = 4, m = 5;
    Solve(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}