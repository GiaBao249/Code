#include <bits/stdc++.h>
using namespace std;

int n, m;

void Test(int l, int m, int r, vector<int> &v)
{
    if (l == r)
    {
        for (int i = 0; i < m; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(v[l], v[i]);
            Test(l + 1, m, r, v);
            swap(v[l], v[i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    Test(0, m, n - 1, a);
}