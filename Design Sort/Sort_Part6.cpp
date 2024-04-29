#include <bits/stdc++.h>
using namespace std;

int Sort(vector<int> &a, int val, int l, int r)
{
    l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (val == a[mid])
            return mid;
        else if (a[mid] > val)
            return Sort(a, val, l, mid - 1);
        return Sort(a, val, mid + 1, r);
    }
}

int main()
{
    int val;
    cin >> val;
    vector<int> v = {5, 7, 3, 2};
    cout << Sort(v, val, 0, v.size() - 1);
}