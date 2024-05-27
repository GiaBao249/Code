#include <bits/stdc++.h>
using namespace std;

int findPair(int n, int x, vector<int> &a)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int target = a[i] + x;
            if (a[mid] == target && mid != i)
                return 1;
            else if (a[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}
