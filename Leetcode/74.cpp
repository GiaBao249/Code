#include <bits/stdc++.h>
using namespace std;
bool BS(vector<int> &a, int k)
{
    int n = a.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
            return true;
        else if (a[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &v, int target)
{
    vector<int> rz;
    int n = v.size();
    int m = v[0].size();
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            rz.push_back(v[i][j]);
    }
    if (BS(rz, target))
        return true;
    return false;
}