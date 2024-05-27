#include <bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int> &a)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]]++;
    int res = 0;
    int min_val = 0;
    for (auto x : mp)
    {
        if (x.second > min_val)
        {
            min_val = x.second;
            res = x.first;
        }
    }
    return res;
}
