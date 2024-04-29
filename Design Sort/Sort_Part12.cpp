#include <bits/stdc++.h>
using namespace std;

int Try(vector<int> &a)
{
    int cnt = 1, res = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
        {
            res = res + cnt * (cnt - 1) / 2; // Công thức tổ hợp chập k của n
            cnt = 1;
        }
    }
    return res;
}

int main()
{
    vector<int> v = {1, 3, 3, 3, 3, 3, 4, 4};
    cout << Try(v);
}