#include <bits/stdc++.h>
using namespace std;

//? Hai con trỏ + sort mảng
vector<vector<int>> threeSum(vector<int> &v)
{
    vector<vector<int>> res;
    int n = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        else
        {
            int target = -v[i];
            int l = i + 1,
                r = n - 1;
            while (l < r)
            {
                int total = v[l] + v[r];
                if (total == target)
                {
                    res.push_back({v[i], v[l], v[r]});
                    while (l < r && v[l] == v[l + 1])
                        l++;
                    while (l < r && v[r] == v[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (total < target)
                    l++;
                else
                    r--;
            }
        }
    }
    return res;
}