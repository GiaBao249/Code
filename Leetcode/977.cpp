#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = pow(nums[i], 2);
    }
    sort(nums.begin(), nums.end());
    return nums;
}

// Cách 2 không dùng hàm có sẳn -- dùng hai con trỏ
vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> res(nums.size());
    int l = 0, r = nums.size() - 1;
    for (int k = nums.size() - 1; k >= 0; k--)
    {
        if (abs(nums[r]) > abs(nums[l]))
            res[k] = nums[r] * nums[r--];
        else
            res[k] = nums[l] * nums[l++];
    }
    return res;
}