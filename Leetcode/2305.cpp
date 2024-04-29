#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int i, vector<int> &a)
{
    if (i == v.size())
    {
        int ans = 0;
        for (auto it : a)
            ans = max(ans, it);
        return ans;
    }
    int min_val = INT_MAX;
    for (int j = 0; j < a.size(); j++)
    {
        a[j] += v[i];
        min_val = min(min_val, solve(v, i + 1, a));
        a[j] -= v[i];
    }
    return min_val;
}

int distributeCookies(vector<int> &cookies, int k)
{
    vector<int> distribute(k);
    return solve(cookies, 0, distribute);
}