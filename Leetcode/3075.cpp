#include <bits/stdc++.h>
using namespace std;

//! không thể ăn hết Test case do TLE
long long MaximumHappinessSum(vector<int> &v, int k)
{
    long long res = 0;
    vector<int> temp = v;
    sort(temp.begin(), temp.end(), greater<int>());
    for (int i = 0; i < k; i++)
    {
        int cnt = temp[i];
        res += cnt;
        for (int j = i + 1; j < temp.size(); j++)
        {
            temp[j]--;
            if (temp[j] < 0)
                temp[j] = 0;
        }
    }
    return res;
}

long long maximumHappinessSum(vector<int> &v, int k)
{
    sort(v.begin(), v.end(), greater<int>());
    long long res = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        res += max(v[i] - cnt, 0);
        cnt++;
    }
    return res;
}
