#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int matrixScore(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = 1 - a[i][j];
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        int d0 = 0;
        int d1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 0)
                d0++;
            else
                d1++;
        }
        if (d0 > d1 && d1 != n)
        {
            for (int i = 0; i < n; i++)
            {
                a[i][j] = 1 - a[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int row_value = 0;
        for (int j = 0; j < m; j++)
        {
            row_value += a[i][j] * pow(2, m - j - 1);
        }
        res += row_value;
    }
    return res;
}
int main()
{
    vector<vector<int>> v;
    int n, m;
    cin >> n >> m;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    cout << matrixScore(v);
    return 0;
}
