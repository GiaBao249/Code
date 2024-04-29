#include <bits/stdc++.h>
using namespace std;

void Insert(vector<long> &maxArr, int val)
{
    int i = 0;
    while (i < maxArr.size())
    {
        if (val == maxArr[i])
            return;
        else if (val > maxArr[i])
            break;
        else
            i++;
    }
    if (i < maxArr.size())
    {
        for (int j = maxArr.size() - 2; j >= i; j--)
        {
            maxArr[j + 1] = maxArr[j];
        }
        maxArr[i] = val;
    }
}

int thirdMax(vector<int> &a)
{
    vector<long> maxArr = {LONG_MIN, LONG_MIN, LONG_MIN};
    for (int i = 0; i < a.size(); i++)
    {
        Insert(maxArr, a[i]);
    }
    if (maxArr[2] == LONG_MIN)
        return maxArr[0];

    return maxArr[2];
}