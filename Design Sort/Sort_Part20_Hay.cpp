#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    int res = 1;
    int end_Time = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first > end_Time)
        {
            ++res;
            end_Time = a[i].second;
        }
    }
    cout << res << endl;
}