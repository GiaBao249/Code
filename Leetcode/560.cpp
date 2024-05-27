#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &a, int k)
{
    int n = a.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += a[j];
            if (s == k)
            {
                res = s;
                return res;
            }
        }
    }
    return res;
}

int subarraySUM(vector<int> &a, int k)
{
    int n = a.size();
    unordered_map<int, int> mp;
    int sum = 0, cnt = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (mp.find(sum - k) != mp.end())
            cnt += mp[sum - k];
        mp[sum] = mp[sum] + 1;
    }
    return cnt;
}