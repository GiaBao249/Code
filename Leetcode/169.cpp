#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    map<int, int> mp;
    for (auto x : nums)
        mp[x]++;
    int max_val = INT_MIN;
    for (auto it : mp)
    {
        max_val = max(max_val, it.second);
        if (it.second == max_val)
            res = it.first;
    }
    return res;
}