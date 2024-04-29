#include <bits/stdc++.h>
using namespace std;

int tachso(int n)
{
    int dem = 0;
    while (n > 0)
    {
        n /= 10;
        dem++;
    }
    return dem;
}

int findNumbers(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (tachso(nums[i]) % 2 == 0)
            count++;
    }
    return count;
}