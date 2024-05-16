#include <bits/stdc++.h>
using namespace std;

int dx[7] = {0, 0, 0, 1, 2, 2, 2};
int dy[7] = {0, 1, 2, 1, 0, 1, 2};
int hourglassSum(vector<vector<int>> arr)
{
    int res = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int sum = 0;
            for (int k = 0; k < 7; k++)
            {
                int u = i + dx[k];
                int v = j + dy[k];
                sum += arr[u][v];
            }
            res = max(res, sum);
        }
    }
    return res;
}