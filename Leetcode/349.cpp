#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_set<int> s1, s2;
    for (int i = 0; i < nums1.size(); i++)
        s1.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); i++)
    {
        if (s1.find(nums2[i]) != s1.end())
            s2.insert(nums2[i]);
    }
    for (auto x : s2)
        res.push_back(x);
    return res;
}
