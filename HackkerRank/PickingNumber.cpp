#include <bits/stdc++.h>
using namespace std;

int PickingNumber(vector<int> a)
{
    int n = a.size();
    int j = 0, ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        while (j < n && a[j] - a[i] <= 1)
        {
            j++;
        }
        ans = max(ans, j - i);
    }
    return ans;
}