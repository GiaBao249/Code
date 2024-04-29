#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int a[100];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < k; i++)
        {
            ans1 += a[i];
        }
        for (int i = k; i < n; i++)
        {
            ans2 += a[i];
        }
        int res = abs(ans1 - ans2);
        cout << res << endl;
    }
}

// Cách 2
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    k = min(k, n - k);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            s1 += a[i];
        else
            s2 += a[i];
    }
    cout << abs(s1 - s2) << endl;
}
