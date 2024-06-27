#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void Solve(vector<vector<int>> &a, int n, int m)
{
    while (true)
    {
        int x = INT_MIN;
        int maxi = -1, maxj = -1;
        bool find = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool ok = true;
                for (int k = 0; k < 4; k++)
                {
                    int u = i + dx[k];
                    int v = j + dy[k];
                    if (u >= 0 && u < n && v >= 0 && v < m && a[i][j] <= a[u][v])
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    if (!find || a[i][j] > x || a[i][j] == x && i < maxi || i == maxi && j < maxj)
                    {
                        x = a[i][j];
                        maxi = i;
                        maxj = j;
                        find = true;
                    }
                }
            }
        }
        if (!find)
            break;
        if (a[maxi][maxj] == 1e9)
            a[maxi][maxj] = 1;
        else
            a[maxi][maxj] -= 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        Solve(a, n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}