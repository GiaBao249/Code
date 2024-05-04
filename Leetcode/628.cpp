#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &v)
{
    if (v.empty())
        return 0;
    int n = v.size();
    sort(v.begin(), v.end());
    int res1 = v[n - 1] * v[n - 2] * v[n - 3];
    int res2 = v[0] * v[1] * v[n - 1];
    return max(res1, res2);
}
