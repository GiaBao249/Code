#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] * b[i]);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}