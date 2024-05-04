#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > 0 && binary_search(v.begin(), v.end(), -v[i]))
            return v[i];
    }
    return -1;
}

int FindMaxK(vector<int> &v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    int l = 0, r = n - 1;
    int maxK = INT_MIN;
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (sum == 0)
        {
            maxK = max(maxK, v[r]);
            l++;
            r--;
        }
        else if (sum < 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return maxK != INT_MIN ? maxK : -1;
}