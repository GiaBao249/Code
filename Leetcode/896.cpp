#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> &a)
{
    int n = a.size();
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            flag = true;
        }
    }
    if (flag == false)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            flag = true;
            return false;
        }
    }
    return true;
}
