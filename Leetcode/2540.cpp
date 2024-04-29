#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    set<int> se;
    int res = INT_MAX;
    int ok = 0;
    for (auto x : nums1)
        se.insert(x);
    for (auto it : nums2)
    {
        if (se.count(it))
        {
            res = min(res, it);
            ok = 1;
        }
    }
    if (ok)
        return res;
    return -1;
}
