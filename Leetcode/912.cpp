#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size() + a2.size();
    vector<int> result(n);
    int i = 0, i1 = 0, i2 = 0;
    while (i < n)
    {
        if (i1 < a1.size() && i2 < a2.size())
        {
            if (a1[i1] <= a2[i2])
            {
                result[i] = a1[i1];
                i++;
                i1++;
            }
            else
            {
                result[i] = a2[i2];
                i++;
                i2++;
            }
        }
        else
        {
            if (i1 < a1.size())
            {
                result[i] = a1[i1];
                i++;
                i1++;
            }
            else
            {
                result[i] = a2[i2];
                i++;
                i2++;
            }
        }
    }
    return result;
}

vector<int> mergeSort(vector<int> &a, int L, int R)
{
    if (L >= R)
        return vector<int>{a[L]};
    int k = (L + R) / 2;
    vector<int> a1 = mergeSort(a, L, k);
    vector<int> a2 = mergeSort(a, k + 1, R);

    vector<int> result = merge(a1, a2);

    return result;
}

vector<int> sortArray(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}