#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs1(vector<int> &a)
{
    int res = 0;
    int n = a.size();
    int i;
    int index = 2;
    if (n < 2)
    {
        if (a[0] < a[1])
            index = 0;
        else
            index = 1;
    }
    for (i = index; i < n; i++)
    {
        if (a[i - 1] < a[i - 2])
            a[i] += a[i - 1];
        else
            a[i] += a[i - 2];
        res = min(a[i], a[i - 1]);
    }
    return res;
}

// Duyệt ngược lai sẽ tối ưu thuật toán hơn

int minCostClimbingStairs2(vector<int> &a)
{
    int n = a.size();
    for (int i = n - 3; i > -1; --i)
    {
        a[i] += min(a[i + 1], a[i + 2]);
    }
    return min(a[0], a[1]);
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << minCostClimbingStairs2(v);
}