#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &a)
{
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
            a[i] = max(a[i], a[i + 1]);
    }
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    if (n > 0)
    {
        a[n - 1] = -1;
    }
    return a;
}