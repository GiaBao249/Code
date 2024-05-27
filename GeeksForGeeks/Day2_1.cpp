#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            res.push_back(a[i]);
    }
    return res;
}

vector<int> Leaders(int a[], int n)
{
    vector<int> res;
    res.push_back(a[n - 1]);
    int tmp = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= tmp)
        {
            tmp = a[i];
            res.push_back(a[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> res = leaders(a, n);
    for (auto x : res)
        cout << x << " ";
    return 0;
}