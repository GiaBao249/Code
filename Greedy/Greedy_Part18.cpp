#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    vector<int> a;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll x1 = a[0] * a[1] * a[n - 1];
    ll x2 = a[n - 3] * a[n - 2] * a[n - 1];
    ll x3 = a[0] * a[1];
    ll x4 = a[n - 1] * a[n - 2];

    cout << max(x1, x2) << max(x3, x4) << endl;
}