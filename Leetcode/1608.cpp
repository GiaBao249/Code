#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0; i <= a[n - 1]; i++)
    {
        int index = lower_bound(a.begin(), a.end(), i) - a.begin();
        if (n - index == i)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int specialArray(vector<int> a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    for (int i = 0; i < 1001; i++)
    {
        int l = 0, r = n - 1, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] >= i)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (a.size() - ans == i && ans != -1)
            return i;
    }
    return -1;
}