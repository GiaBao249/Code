#include <bits/stdc++.h>
using namespace std;

int BSeach(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
        {
            res = mid;
            l = mid + 1;
        }
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    int a[100], n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = BSeach(a, n, x);
    if (res != -1)
        cout << res + 1 << endl;
    else
        cout << "-1" << endl;
}